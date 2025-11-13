# 🌍 Earthquake Detection and Monitoring over IoT

A **low-cost seismic activity detection system** built using Arduino/NodeMCU, vibration sensors, and IoT platforms.  
It provides **real-time earthquake monitoring**, local alerts, and **graphical visualization** through ThingSpeak or Blynk.

---

## ⚙️ Features

- 🌐 Real-time IoT monitoring (ThingSpeak / Blynk)
- 📈 Live data visualization (acceleration & vibration)
- 🚨 Instant buzzer + LCD warning system
- 💰 Low-cost design for deployment in rural/hilly regions
- 🏔️ Designed for **Himachal Pradesh earthquake-prone zones**

---

## 🧰 Components Used

| Component | Quantity | Description |
|------------|-----------|-------------|
| Arduino / NodeMCU | 1 | Central controller |
| ADXL335 / MPU6050 | 1 | Detects ground motion |
| SW-420 Vibration Sensor | 1 | Detects shocks |
| 16x2 LCD Display | 1 | Displays live readings |
| Buzzer | 1 | Alerts users |
| Wi-Fi Module (ESP8266) | 1 | For cloud connectivity |
| ThingSpeak Cloud | – | For IoT monitoring |

---

## 🧠 System Workflow

1. Sensors measure ground vibration and motion.  
2. If threshold values are exceeded, a local alarm triggers.  
3. NodeMCU sends data to ThingSpeak IoT cloud.  
4. Users and authorities can monitor data in real-time on any device.

---

## 🧩 Libraries Required

- `ESP8266WiFi.h`
- `ThingSpeak.h`
- `Wire.h`
- `LiquidCrystal_I2C.h`

---

## 📊 Sample ThingSpeak Dashboard

- Field 1 → Acceleration (g)
- Field 2 → Vibration Status
- Graphs auto-update every 2 seconds.

---

## 🔋 Power Supply

- 5V DC for NodeMCU, LCD, sensors, and buzzer

---

## 🧾 Applications

- Early earthquake detection
- IoT-based disaster alert networks
- Real-time data analytics for seismic studies
- Educational and research demonstrations

---

## 👩‍💻 Author

**Arpita Sharma**  
🎓 Electronics and Communication Engineering – JNGEC Sundarnagar  
📧 [arpitasharma5022@gmail.com](mailto:arpitasharma5022@gmail.com)  
🔗 [LinkedIn](https://www.linkedin.com/in/arpita-sharma-686044358/)
