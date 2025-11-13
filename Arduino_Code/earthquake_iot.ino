/***************************************************
 * EARTHQUAKE DETECTION AND MONITORING OVER IoT
 * Using NodeMCU + MPU6050 + SW-420 + Buzzer + LCD + ThingSpeak
 ***************************************************/
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "ThingSpeak.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

WiFiClient client;

// ThingSpeak Info
unsigned long myChannelNumber = YOUR_CHANNEL_ID;
const char * myWriteAPIKey = "YOUR_API_KEY";

// Sensor pins
#define VIB_PIN D5
#define BUZZER_PIN D6

// MPU6050
const int MPU = 0x68;
int16_t AcX, AcY, AcZ;
float vibrationValue;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lcd.begin();
  lcd.backlight();

  pinMode(VIB_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  // Initialize MPU6050
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  // Wi-Fi connection
  WiFi.begin(ssid, password);
  lcd.setCursor(0, 0);
  lcd.print("Connecting WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  ThingSpeak.begin(client);
  lcd.clear();
  lcd.print("WiFi Connected!");
  delay(1000);
}

void loop() {
  // Read accelerometer
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true);

  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();

  int vib = digitalRead(VIB_PIN);
  float netAcc = sqrt((AcX * AcX) + (AcY * AcY) + (AcZ * AcZ)) / 1000.0;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Acc: ");
  lcd.print(netAcc, 2);
  lcd.setCursor(0, 1);

  if (netAcc > 2.0 || vib == HIGH) {
    lcd.print("EARTHQUAKE!");
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    lcd.print("Normal");
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Send data to ThingSpeak
  ThingSpeak.setField(1, netAcc);
  ThingSpeak.setField(2, vib);
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  delay(2000);
}
