#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

#define PIN_LDR 32
#define PIN_TRIG 25
#define PIN_ECHO 26
#define PIN_RELAY_LDR 33
#define PIN_RELAY_SWITCH 27
#define PIN_DHT 14
#define DHTTYPE DHT11

int distance;
int analogValue;
float humidity;
float temperature;
bool relayState;
int switchState;
DHT dht(PIN_DHT, DHTTYPE);

const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* token = "YOUR_UBIDOTS_TOKEN";
const char* APIlabel = "YOUR_API_LABEL_ON_DEVICE";
const char* ubidots_server = "http://industrial.api.ubidots.com/api/v1.6/devices/";


void setup() {
  Serial.begin(115200);
  pinMode(PIN_LDR, INPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  pinMode(PIN_RELAY_LDR, OUTPUT);
  pinMode(PIN_RELAY_SWITCH, OUTPUT);

  digitalWrite(PIN_RELAY_LDR, HIGH);
  digitalWrite(PIN_RELAY_SWITCH, HIGH);
  switchState = 0;

  Serial.println(F("DHTxx test!"));
  dht.begin();

  WiFi.begin(ssid, pass);
  Serial.print("Menghubungkan ke WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nTerhubung ke WiFi");
}

void loop() {
  readUltrasonic();
  readLDR();
  readDHT();
  Switch();
  sendDataToUbidots();
  delay(1000);
}

void readUltrasonic() {
  unsigned long interval_HCSR04 = 1000;
  unsigned long previousMillis_HCSR04 = 0;
  unsigned long currentMillis_HCSR04 = millis();
  
  if ((unsigned long)(currentMillis_HCSR04 - previousMillis_HCSR04) >= interval_HCSR04) {
    digitalWrite(PIN_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_TRIG, LOW);

    unsigned long duration = pulseIn(PIN_ECHO, HIGH, 30000);
    distance = duration / 58.0;

    Serial.print("Jarak dalam Cm: ");
    Serial.print(distance);
    Serial.print("\nJarak dalam Inch: ");
    Serial.print(duration / 148.0);

    if (distance <= 200 && distance > 0) {
      Serial.println("\n\n===================================");
      Serial.println("!!! ORANG TERDETEKSI !!!");
      Serial.println("Objek berada kurang dari 2 meter");
      Serial.println("===================================");
    }
  }
}

void readLDR() {
  unsigned long interval_LDR = 1000;
  unsigned long previousMillis_LDR = 0;
  unsigned long currentMillis_LDR = millis();
  
  if ((unsigned long)(currentMillis_LDR - previousMillis_LDR) >= interval_LDR) {
    analogValue = analogRead(PIN_LDR);
    relayState = false;

    Serial.print("\nLDR Value: ");
    Serial.print(analogValue);

    if (analogValue > 2000) {
      Serial.println(" => Dark");
      digitalWrite(PIN_RELAY_LDR, LOW);
      relayState = true;
    } else {
      Serial.println(" => Very bright");
      digitalWrite(PIN_RELAY_LDR, HIGH);
      relayState = false;
    }
    Serial.print("Relay: ");
    Serial.println(relayState ? "ON" : "OFF");
  }
}

void readDHT() {
  unsigned long interval_DHT11 = 1000;
  unsigned long previousMillis_DHT11 = 0;
  unsigned long currentMillis_DHT11 = millis();
  
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  if ((unsigned long)(currentMillis_DHT11 - previousMillis_DHT11) >= interval_DHT11)
  {

    if (isnan(humidity) || isnan(temperature)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }
    Serial.print(F("Humidity: "));
    Serial.print(humidity);
    Serial.print(F("% , Temperature: "));
    Serial.print(temperature);
    Serial.println("°C");
  }
}

void Switch() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = String(ubidots_server) + APIlabel + "/switch/lv?token=" + token;
    http.begin(url);

    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      String payload = http.getString();
      switchState = payload.toInt();

      if (switchState == 1) { digitalWrite(PIN_RELAY_SWITCH, LOW); }
      else { digitalWrite(PIN_RELAY_SWITCH, HIGH); }
      Serial.print("Relay Switch dari Ubidots: ");
      Serial.println(switchState == 1 ? "ON" : "OFF");

    } else {
      Serial.print("Gagal membaca data dari Ubidots: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }
}

void sendDataToUbidots() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = String(ubidots_server) + APIlabel + "/?token=" + token;
    http.begin(url);
    http.addHeader("Content-Type", "application/json");

    String jsonPayload = "{";
    jsonPayload += "\"jarak\":{\"value\":" + String(distance) + "},";
    jsonPayload += "\"suhu\":{\"value\":" + String(temperature, 2) + "},";
    jsonPayload += "\"kelembapan\":{\"value\":" + String(humidity, 2) + "},";
    jsonPayload += "\"ldr\":{\"value\":" + String(analogValue) + "},";
    jsonPayload += "\"relay\":{\"value\":" + String(relayState ? 1 : 0) + "},";
    jsonPayload += "\"switch\":{\"value\":" + String(switchState) + "}";
    jsonPayload += "}";

    int httpResponseCode = http.POST(jsonPayload);
    if (httpResponseCode > 0) { Serial.println("----\nData terkirim ke Ubidots."); }
    else {
      Serial.print("Error dalam pengiriman: ");
      Serial.println(httpResponseCode);
    }
    http.end();
    
  } else { Serial.println("WiFi tidak terhubung"); }
}
