#include <WiFi.h>
#include <FirebaseESP32.h>


// WiFi
#define WIFI_SSID "Naufal"
#define WIFI_PASSWORD "12345678"


// Firebase
#define FIREBASE_HOST "uasswnnofal-default-rtdb.asia-southeast1.firebasedatabase.app"  // TANPA https://
#define FIREBASE_AUTH "vzAIacP0rm4QSejhvTSBv0Ds35sMQn4dxVXvqZbc"  // Kosong jika pakai akses anonymous


FirebaseData fbdo;
FirebaseAuth firebaseAuth;
FirebaseConfig firebaseConfig;


unsigned long lastSendTime = 0;
const int interval = 2000;
const int potPin = 34;


void setup() {
  Serial.begin(115200);


  // Koneksi WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Connected!");


  // Konfigurasi Firebase
  firebaseConfig.host = FIREBASE_HOST;
  firebaseConfig.signer.tokens.legacy_token = FIREBASE_AUTH;


  // Inisialisasi koneksi ke Firebase
  Firebase.begin(&firebaseConfig, &firebaseAuth);
}


void loop() {
  if (millis() - lastSendTime > interval) {
    lastSendTime = millis();


    int nilaiPot = analogRead(potPin);
    Serial.println("Nilai Potensio: " + String(nilaiPot));


    // Kirim nilai terbaru ke /POTENSIO/latest (bisa ditimpa)
    if (Firebase.setInt(fbdo, "/POTENSIO/latest", nilaiPot)) {
      Serial.println("Terkirim ke /POTENSIO/latest");
    } else {
      Serial.print("Gagal kirim latest: ");
      Serial.println(fbdo.errorReason());
    }


    // Simpan data riwayat ke /POTENSIO/history (dengan push)
    if (Firebase.pushInt(fbdo, "/POTENSIO/history", nilaiPot)) {
      Serial.println("Terkirim ke /POTENSIO/history (push)");
    } else {
      Serial.print("Gagal push history: ");
      Serial.println(fbdo.errorReason());
    }
  }
}



