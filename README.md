# 📈 Grafik Potensiometer Realtime

Proyek ini adalah aplikasi berbasis HTML yang menampilkan grafik nilai **potensiometer** secara **realtime** menggunakan data dari **Firebase Realtime Database**. Visualisasi dilakukan dengan **Chart.js** dan plugin **chartjs-plugin-zoom**, menampilkan 20 data terbaru dan mendukung scroll horizontal untuk melihat data sebelumnya. Nilai grafik diambil dari nilai potensiometer yang diinputkan ke Firebase realtime database. Project ini dikendalikan menggunakan ESP32.

---

## 🔧 Fitur

- Menampilkan grafik nilai potensiometer secara realtime.
- Data diperbarui otomatis setiap 2 detik.
- Grafik dipengaruhi oleh nilai potensiometer yang berubah
- Menampilkan hanya 20 data terbaru secara default.
- Mendukung scroll (pan) horizontal ke data sebelumnya.
- Tampilan responsif dan bersih.
- Menggunakan Chart.js dan plugin zoom untuk pengalaman interaktif.

---

## 🖥️ Tampilan Antarmuka

- Grafik garis berwarna merah dengan bayangan transparan.
- Sumbu Y dari 0 hingga 4095 (standar ADC 12-bit).
- Data ditandai sebagai "Data 1", "Data 2", dst., berdasarkan urutan waktu.

---

## 🧩 Teknologi yang Digunakan

- **HTML5**
- **CSS**
- **JavaScript**
- [Chart.js](https://www.chartjs.org/)
- [chartjs-plugin-zoom](https://www.chartjs.org/chartjs-plugin-zoom/)
- [Firebase Realtime Database](https://firebase.google.com/products/realtime-database)

---

## 🔗 Sumber Data Firebase

Data diambil dari endpoint berikut:
https://uasswnnofal-default-rtdb.asia-southeast1.firebasedatabase.app/POTENSIO/history.json

## 📜 Lisensi
Proyek ini bebas digunakan untuk keperluan pembelajaran dan non-komersial.

© 2025 – Dibuat oleh Muhammad Naufal Afif


