[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?style=flat)](https://github.com/ellerbrock/open-source-badges/)
[![License: GPL-3.0](https://img.shields.io/badge/License-GPL-%2D3.0-blue.svg?logo=github&color=%23F7DF1E)](https://opensource.org/license/gpl-3.0)
![GitHub last commit](https://img.shields.io/github/last-commit/cakraawijaya/Ubidots-Room-Monitoring-System?logo=Codeforces&logoColor=white&color=%23F7DF1E)
![Project](https://img.shields.io/badge/Project-ESP32-light.svg?style=flat&logo=espressif&logoColor=white&color=%23F7DF1E)
![Type](https://img.shields.io/badge/Type-BNSP%20IIoT%20Project-light.svg?style=flat&logo=gitbook&logoColor=white&color=%23F7DF1E)

# Ubidots Room Monitoring System
Sistem pemantauan dan pengendalian ruangan cerdas — memantau suhu, kelembapan, intensitas cahaya, dan kehadiran penghuni, dilengkapi dengan visualisasi dasbor secara real-time serta pengendalian relai jarak jauh melalui Ubidots.

<br><br>

## Kebutuhan Proyek
| Bagian | Deskripsi |
| --- | --- |
| Papan Pengembangan | DOIT ESP32 DEVKIT V1 |
| Editor Kode | Arduino IDE 1.8.19 (Versi Lama yang Stabil) |
| Driver | CP210X USB Driver |
| Platform IoT | Ubidots |
| Protokol Komunikasi | Hypertext Transfer Protocol (HTTP) |
| Arsitektur IoT | 3 Lapisan |
| Bahasa Pemrograman | C/C++ |
| Pustaka Arduino | • WiFi (bawaan)<br>• HTTPClient (bawaan)<br>• DHT sensor library oleh Adafruit (Versi: 1.4.6) |
| Aktuator | • Kipas DC 5V (x1)<br>• Relay elektromekanis 2-channel (x1)<br>• LED (x1) |
| Sensor | • DHT11: Suhu & Kelembapan Udara (x1)<br>• Modul Sensor LDR (x1)<br>• HC-SR04: Sensor Ultrasonik (x1) |
| Komponen Lainnya| • Kabel USB Mikro - USB tipe A (x1)<br>• Papan ekspansi ESP32 (x1)<br>• Breadboard (x1)<br>• Adaptor DC 9V 1A (x1)<br>• Resistor 220 ohm (x1)<br>• Kabel jumper (1 set) |

<br><br>

## Unduh & Instal
1. Arduino IDE

   <table><tr><td width="810">

   ```
   https://bit.ly/ArduinoIDE_Installer
   ```

   </td></tr></table><br>

2. CP210X USB Driver

   <table><tr><td width="810">
   
   ```
   https://bit.ly/CP210X_USBdriver
   ```

   </td></tr></table>
   
<br><br>

## Rancangan Proyek

<table>
<tr>
<th width="840">Arsitektur</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Diagram/Architecture.jpg" alt="architecture"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Desain Perangkat Lunak</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Diagram/Flowchart Firmware.jpg" alt="flowchart"></td>
</tr>
</table>
<table>
<tr>
<th width="420">Diagram Ilustrasi</th>
<th width="420">Diagram Blok</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Diagram/Pictorial Diagram.jpg" alt="pictorial-diagram"></td>
<td align="center"><img src="Assets/Documentation/Diagram/Block Diagram.jpg" alt="block-diagram"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Pengkabelan</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Table/Device Wiring.jpg" alt="wiring"></td>
</tr>
</table>

<br><br>

## Pengaturan Arduino IDE
1. Buka ``` Arduino IDE ``` terlebih dahulu, kemudian buka proyek dengan cara klik ``` File ``` -> ``` Open ``` : 

   <table><tr><td width="810">
      
      ``` Code.ino ```
         
   </td></tr></table><br>
   
2. Isi ``` Url Pengelola Papan Tambahan ``` di Arduino IDE

   <table><tr><td width="810">

      Klik ``` File ``` -> ``` Preferences ``` -> masukkan ``` Boards Manager Url ``` dengan menyalin tautan berikut :
      
      ```
      https://dl.espressif.com/dl/package_esp32_index.json
      ```
         
   </td></tr></table><br>
   
3. ``` Pengaturan Board ``` di Arduino IDE

   <table>
      <tr><th width="810">

      Cara mengatur board ``` DOIT ESP32 DEVKIT V1 ```
            
      </th></tr>
      <tr><td width="810">
         
      • Klik ``` Tools ``` -> ``` Board ``` -> ``` Boards Manager ``` -> Instal ``` esp32 ```.

      • Kemudian pilih papan dengan mengklik: ``` Tools ``` -> ``` Board ``` -> ``` ESP32 Arduino ``` -> ``` DOIT ESP32 DEVKIT V1 ```.

      </td></tr>
   </table><br>
   
4. ``` Ubah Kecepatan Papan ``` di Arduino IDE

   <table><tr><td width="810">

      Klik ``` Tools ``` -> ``` Upload Speed ``` -> ``` 115200 ```
         
   </td></tr></table><br>
   
5. ``` Instal Pustaka ``` di Arduino IDE

   <table><tr><td width="810">

      Unduh semua file zip pustaka. Kemudian tempelkan di: ``` C:\Users\Computer_Username\Documents\Arduino\libraries ```
         
   </td></tr></table><br>

6. ``` Pengaturan Port ``` di Arduino IDE

   <table><tr><td width="810">

      Klik ``` Port ``` -> Pilih sesuai dengan port perangkat anda ``` (anda dapat melihatnya di Device Manager) ```
         
   </td></tr></table><br>

7. Ubah ``` Nama WiFi ```, ``` Kata Sandi WiFi ```, dan sebagainya sesuai dengan apa yang anda gunakan saat ini.<br><br>

8. Sebelum mengunggah program, silakan klik: ``` Verify ```.<br><br>

9. Jika tidak ada kesalahan dalam kode program, silakan klik: ``` Upload ```.<br><br>
    
10. Beberapa hal yang perlu anda lakukan saat menggunakan ``` board ESP32 ``` :

    <table><tr><td width="810">
       
       • Jika ``` board ESP32 ``` tidak dapat memproses ``` Source Code ``` secara total -> Tekan tombol ``` EN (RST) ``` -> ``` Restart ```.

       • Jika ``` board ESP32 ``` tidak dapat memproses ``` Source Code ``` secara otomatis maka :<br>

      - Ketika informasi: ``` Uploading... ``` telah muncul -> segera tekan dan tahan tombol ``` BOOT ```.<br>

      - Ketika informasi: ``` Writing at .... (%) ``` telah muncul -> lepaskan tombol ``` BOOT ```.

       • Jika pesan: ``` Done Uploading ``` telah muncul -> ``` Program yang diisikan tadi sudah bisa dioperasikan ```.

       • Jangan tekan tombol ``` BOOT ``` dan ``` EN ``` secara bersamaan karena hal ini bisa beralih ke mode ``` Unggah Firmware ```.

    </td></tr></table><br>

11. Jika masih ada masalah saat unggah program, maka coba periksa pada bagian ``` driver ``` / ``` port ``` / ``` yang lainnya ```.

<br><br>

## Pengaturan Ubidots
1. Memulai Ubidots : 

   <table><tr><td width="810">
   
      • Silakan <a href="https://industrial.ubidots.com/accounts/signin/">Masuk</a> agar dapat mengakses layanan ``` Ubidots ```.
      
      • Jika anda belum memiliki akun ``` Ubidots ```, silakan buat dulu.

   </td></tr></table><br>

2. Membuat dasbor :

   <table><tr><td width="810">
   
      • Pada bagian ``` Data ``` -> pilih menu ``` Dashboards ```.
   
      • Hapus dasbor demo bawaan Ubidots sebelum membuat dasbor baru.
   
      • Klik ``` Add new Dashboard ```.
   
      • ``` Name ```, ``` Tags ```, ``` Default time range ``` -> sesuaikan dengan kebutuhan anda.

      • ``` Dynamic Dashboard ``` -> ubah menjadi ``` Dynamic (Single Device) ```.

      • ``` Default Device ``` -> pilih device yang ingin ditampilkan.

      • Pengaturan yang lain biarkan saja -> kemudian klik ``` SAVE ```.

   </td></tr></table><br>

3. Membuat widget Text :

   <table><tr><td width="810">
   
      • Pastikan anda berada di menu ``` Dashboards ```.
   
      • Klik ``` + Add new widget ```.
   
      • Pilih ``` Text ``` untuk membuat label.
   
      • Beri nama label tersebut, misalnya: ``` MONITORING ``` / ``` KONTROL ```.
   
      • Sesuaikan gaya, ukuran, dan detail lainnya sesuai kebutuhan.
   
      • Klik ``` SAVE ``` untuk menambahkan Widget Teks ke dasbor.
   
      • Jika ingin mengubah isi widget, silakan klik simbol ``` pensil ``` -> setelah itu, klik ``` SAVE ```.

   </td></tr></table><br>

4. Membuat widget Thermometer :

   <table><tr><td width="810">
   
      • Pastikan anda berada di menu ``` Dashboards ```.
   
      • Klik ``` + Add new widget ```.
   
      • Pilih ``` Thermometer ``` untuk suhu ruangan.
   
      • Silakan atur variabel yang ingin Anda gunakan pada widget tersebut.
   
      • Sesuaikan gaya, ukuran, dan detail lainnya sesuai kebutuhan.
   
      • Klik ``` SAVE ``` untuk menambahkan Widget Thermometer ke dasbor.
   
      • Jika ingin mengubah isi widget, silakan klik simbol ``` pensil ``` -> setelah itu, klik ``` SAVE ```.

   </td></tr></table><br>

5. Membuat widget Gauge :

   <table><tr><td width="810">
   
      • Pastikan anda berada di menu ``` Dashboards ```.
   
      • Klik ``` + Add new widget ```.
   
      • Pilih ``` Gauge ``` untuk kelembapan ruangan.
   
      • Silakan atur variabel yang ingin Anda gunakan pada widget tersebut.
   
      • Sesuaikan gaya, ukuran, dan detail lainnya sesuai kebutuhan.
   
      • Klik ``` SAVE ``` untuk menambahkan Widget Gauge ke dasbor.
   
      • Jika ingin mengubah isi widget, silakan klik simbol ``` pensil ``` -> setelah itu, klik ``` SAVE ```.

   </td></tr></table><br>

6. Membuat widget Indicator :

   <table><tr><td width="810">
   
      • Pastikan anda berada di menu ``` Dashboards ```.
   
      • Klik ``` + Add new widget ```.
   
      • Pilih ``` Indicator ``` untuk menampilkan status LED berdasarkan intensitas cahaya.
   
      • Silakan atur variabel yang ingin Anda gunakan pada widget tersebut.
   
      • Sesuaikan gaya, ukuran, dan detail lainnya sesuai kebutuhan.
   
      • Klik ``` SAVE ``` untuk menambahkan Widget Indicator ke dasbor.
   
      • Jika ingin mengubah isi widget, silakan klik simbol ``` pensil ``` -> setelah itu, klik ``` SAVE ```.

   </td></tr></table><br>

7. Membuat widget Line Chart :

   <table><tr><td width="810">
   
      • Pastikan anda berada di menu ``` Dashboards ```.
   
      • Klik ``` + Add new widget ```.
   
      • Pilih ``` Line Chart ``` untuk memvisualisasikan data jarak.
   
      • Silakan atur variabel yang ingin Anda gunakan pada widget tersebut.
   
      • Sesuaikan gaya, ukuran, dan detail lainnya sesuai kebutuhan.
   
      • Klik ``` SAVE ``` untuk menambahkan Widget Line Chart ke dasbor.
   
      • Jika ingin mengubah isi widget, silakan klik simbol ``` pensil ``` -> setelah itu, klik ``` SAVE ```.

   </td></tr></table><br>

8. Membuat widget HTML Canvas :

   <table><tr><td width="810">

      • Pastikan anda berada di menu ``` Dashboards ```.
   
      • Klik ``` + Add new widget ```.
   
      • Pilih ``` HTML Canvas ``` untuk membuat visualisasi khusus yang menampilkan intensitas cahaya.
   
      • Di bagian ``` Code Editor ```, silakan atur sebagai berikut :<br><br>

      <table>
      <tr>
         <th align="left">Kode HTML</th>
      <tr>
      <tr><td width="810">
               
      ```html
      
      <div class="ldr-widget">
          <div class="ldr-circle">
              <span id="ldr-value">-</span>
          </div>
      </div>
         
      ```
      </td></tr>
      </table><br>

      <table>
      <tr>
         <th align="left">Kode CSS</th>
      <tr>
      <tr><td width="810">
               
      ```css
      
      html,
      body {
          width: 100%;
          height: 100%;
          margin: 0;
          padding: 0;
          overflow: hidden;
      }
      
      .ldr-widget {
          width: 100%;
          height: 100%;
          min-height: 200px;
          background: #ffffff;
          position: relative;
          font-family: Arial, sans-serif;
      }
      
      .ldr-title {
          position: absolute;
          top: 12px;
          left: 15px;
          font-size: 16px;
          font-weight: normal;
          color: #5e5e5e;
      }
      
      .ldr-circle {
          position: absolute;
          width: 160px;
          height: 160px;
          top: 50%;
          left: 50%;
          transform: translate(-50%, -50%);
          border-radius: 50%;
          background-color: #ff9800;
          display: flex;
          align-items: center;
          justify-content: center;
          color: #ffffff;
      }
      
      #ldr-value {
          font-size: 28px;
          font-weight: bold;
          line-height: 1;
      }
         
      ```
      </td></tr>
      </table><br>

      <table>
      <tr>
         <th align="left">Kode JavaScript</th>
      <tr>
      <tr><td width="810">
               
      ```javascript
      
      const TOKEN = "UBIDOTS_TOKEN";
      const VARIABLE_ID = "VARIABLE_ID";
   
      function getLDRValue() {
      
          const url =
              "https://industrial.api.ubidots.com/api/v1.6/variables/" +
              VARIABLE_ID +
              "/values?page_size=1";
      
          fetch(url, {
              method: "GET",
              headers: {
                  "X-Auth-Token": TOKEN,
                  "Content-Type": "application/json"
              }
          })
              .then(response => response.json())
              .then(data => {
      
                  if (data.results && data.results.length > 0) {
      
                      const value = Number(data.results[0].value);
      
                      document.getElementById("ldr-value").textContent =
                          value.toFixed(1);
                  }
      
              })
              .catch(error => {
                  console.error("Error mengambil data LDR:", error);
              });
      }
      
      getLDRValue();
      setInterval(getLDRValue, 5000);
         
      ```
      </td></tr>
      </table><br>
   
      • Sesuaikan gaya, ukuran, dan detail lainnya sesuai kebutuhan.
   
      • Klik ``` SAVE ``` untuk menambahkan Widget HTML Canvas ke dasbor.
   
      • Jika ingin mengubah isi widget, silakan klik simbol ``` pensil ``` -> setelah itu, klik ``` SAVE ```.<br><br>

   </td></tr></table><br>

9. Membuat widget Switch :

   <table><tr><td width="810">
   
      • Pastikan anda berada di menu ``` Dashboards ```.
   
      • Klik ``` + Add new widget ```.
   
      • Pilih ``` Switch ``` untuk mengontrol NYALA/MATI Kipas.
   
      • Silakan atur variabel yang ingin Anda gunakan pada widget tersebut.
   
      • Sesuaikan gaya, ukuran, dan detail lainnya sesuai kebutuhan.
   
      • Klik ``` SAVE ``` untuk menambahkan Widget Switch ke dasbor.
   
      • Jika ingin mengubah isi widget, silakan klik simbol ``` pensil ``` -> setelah itu, klik ``` SAVE ```.

   </td></tr></table><br>

10. Konfigurasi firmware : 

    <table><tr><td width="810">
   
      • Klik bagian ``` User ``` yang ada di pojok kiri bawah -> lalu pilih ``` API Credentials ```.
   
      • Salin ``` Default token ``` -> lalu tempelkan pada kode firmware. Contohnya sebagai berikut:

      <table><tr><td width="780">
   
      ```ino
      const char* token = "BBUS-aRZvtYRMM7IWbrKFcICR30YYP7dh5Q"; // define ubidots token
      ```

      </td></tr></table>

    </td></tr></table>

<br><br>

## Memulai
1. Unduh dan ekstrak repositori ini.<br><br>
   
2. Pastikan anda memiliki komponen elektronik yang diperlukan.<br><br>
   
3. Pastikan komponen anda telah dirancang sesuai dengan diagram.<br><br>
    
4. Konfigurasikan perangkat anda menurut pengaturan di atas.<br><br>

5. Selamat menikmati [Selesai].

<br><br>

## Sorotan

<table>
<tr>
<th width="840" colspan="8">Perangkat</th>
</tr>
<tr>
<th width="210" colspan="2">Sensor DHT11</th>
<th width="210" colspan="2">Sensor LDR</th>
<th width="210" colspan="2">Sensor HC-SR04</th>
<th width="210" colspan="2">Kipas</th>
</tr>
<tr>
<td width="105" align="center"><img src="Assets/Documentation/Experiment/DHT11 Sensor/Device.jpg" alt="device"></td>
<td width="105" align="center"><img src="Assets/Documentation/Experiment/DHT11 Sensor/Serial Monitor.jpg" alt="serial-monitor"></td>
<td width="105" align="center"><img src="Assets/Documentation/Experiment/LDR Sensor/Device.jpg" alt="device"></td>
<td width="105" align="center"><img src="Assets/Documentation/Experiment/LDR Sensor/Serial Monitor.jpg" alt="serial-monitor"></td>
<td width="105" align="center"><img src="Assets/Documentation/Experiment/HC-SR04 Sensor/Device.jpg" alt="device"></td>
<td width="105" align="center"><img src="Assets/Documentation/Experiment/HC-SR04 Sensor/Serial Monitor.jpg" alt="serial-monitor"></td>
<td width="105" align="center"><img src="Assets/Documentation/Experiment/Switch (FAN)/Device.jpg" alt="device"></td>
<td width="105" align="center"><img src="Assets/Documentation/Experiment/Switch (FAN)/Serial Monitor.jpg" alt="serial-monitor"></td>
</tr>
<tr>
<th width="840" colspan="8">Sakelar (KIPAS)</th>
</tr>
<tr>
<th width="420" colspan="4">Nyala</th>
<th width="420" colspan="4">Mati</th>
</tr>
<tr>
<td colspan="4" align="center"><img src="Assets/Documentation/Experiment/Switch (FAN)/Switch On.jpg" alt="switch-on"></td>
<td colspan="4" align="center"><img src="Assets/Documentation/Experiment/Switch (FAN)/Switch Off.jpg" alt="switch-off"></td>
</tr>
</table>
<table>
<tr>
<th width="840">Dasbor Ubidots</th>
</tr>
<tr>
<td align="center"><img src="Assets/Documentation/Experiment/Ubidots Dashboard.jpg" alt="dashboard"></td>
</tr>
</table>

<br>
<strong>Informasi lebih lanjut:</strong> <a href="https://github.com/cakraawijaya/Ubidots-Room-Monitoring-System/blob/master/Assets/Documentation/Report/Portofolio%20Pelatihan%20Sertifikasi%20BNSP%20IIoT%20-%20Devan%20Cakra%20Mudra%20Wijaya-14-35.pdf"><u>Klik Disini</u></a>

<br><br><br>

## Apresiasi
Jika karya ini bermanfaat bagi anda, maka dukunglah karya ini sebagai bentuk apresiasi kepada penulis dengan mengklik tombol ``` ⭐Bintang ``` di bagian atas repositori.

<br><br>

## Penafian
Aplikasi ini merupakan hasil pengembangan dari Bootcamp Edutic.id x BNSP 2026. Saya tidak memungkiri bahwa saya masih menggunakan layanan pihak ketiga dalam pengerjaan ini, antara lain: library, framework, dan lain sebagainya.
