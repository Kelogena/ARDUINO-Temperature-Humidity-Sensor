# 🌡️ Arduino Temperature & Humidity Monitor with LCD 1602

A temperature and humidity monitoring system built with an Arduino Uno, a temperature/humidity sensor, and a 16x2 LCD display. The system reads environmental data from the sensor and displays the measurements directly on the LCD screen.



## 📋 Features

* Real-time temperature/humidity monitoring
* LCD 1602 display output
* Adjustable LCD contrast using potentiometer
* Simple Arduino Uno implementation
* Suitable for educational and IoT projects

---

## 🛠 Hardware Requirements

| Component                     | Quantity |
| ----------------------------- | -------- |
| Arduino Uno                   | 1        |
| Temperature & Humidity Sensor | 1        |
| LCD 1602 Display              | 1        |
| 10kΩ Potentiometer            | 1        |
| Breadboard                    | 1        |
| Jumper Wires                  | Multiple |
| USB-B to USB-A Cable          | 1        |

---

## 📸 Hardware Setup

The assembled prototype should look similar to the image below:

* Arduino Uno
* LCD 1602 Display
* Temperature/Humidity Sensor
* Breadboard
* Potentiometer for LCD contrast adjustment

Store your project image as:


<img width="1280" height="964" alt="project-photo jpg" src="https://github.com/user-attachments/assets/8402a724-0191-415f-816b-2ba31f341326" />


and update the image path if necessary.

---
## 📐 Wiring Schematic

A complete wiring schematic for the project is included in the repository:

``text
docs/arduino_wiring_schematic.svg
``
Preview:

<img width="84" height="150" alt="arduino_wiring_schematic" src="https://github.com/user-attachments/assets/07dc71b0-41d5-41a2-8a8f-c68e4069bc3f" />

The schematic illustrates the connections between:

* Arduino Uno
* LCD 1602 Display
* Temperature & Humidity Sensor
* 10kΩ Potentiometer
* Power (5V) and GND rails

Use the schematic together with the wiring tables below when assembling the circuit.

## 🔌 Wiring Instructions

### Temperature & Humidity Sensor

| Sensor Pin | Arduino Uno   |
| ---------- | ------------- |
| GND (-)    | GND           |
| OUT        | Digital Pin 7 |
| VCC (+)    | 5V            |

---

### Potentiometer (LCD Contrast Control)

| Potentiometer Pin | Connection     |
| ----------------- | -------------- |
| Left Leg          | 5V             |
| Middle Leg        | LCD Pin 3 (VO) |
| Right Leg         | GND            |

---

### LCD 1602 Connections

| LCD Pin | Function | Arduino Connection       |
| ------- | -------- | ------------------------ |
| 1       | VSS      | GND                      |
| 2       | VDD      | 5V                       |
| 3       | VO       | Potentiometer Middle Pin |
| 4       | RS       | Digital Pin 12           |
| 5       | RW       | GND                      |
| 6       | E        | Digital Pin 11           |
| 11      | D4       | Digital Pin 5            |
| 12      | D5       | Digital Pin 4            |
| 13      | D6       | Digital Pin 3            |
| 14      | D7       | Digital Pin 6            |
| 15      | LED+     | 5V                       |
| 16      | LED-     | GND                      |

---

## 🚀 Getting Started

### 1. Download Project

Clone the repository:

```bash
git clone https://github.com/yourusername/arduino-temperature-humidity-monitor.git
cd arduino-temperature-humidity-monitor
```

Or download the ZIP file and extract it.

---

### 2. Open in Arduino IDE

1. Open Arduino IDE.
2. Open the project `.ino` file.

---

### 3. Select Board

```text
Tools → Board → Arduino Uno
```

---

### 4. Select COM Port

```text
Tools → Port → Your COM Port
```

Commonly:

```text
COM3
COM4
```

---

### 5. Connect Hardware

Connect the Arduino Uno to your laptop using:

```text
USB-B ↔ USB-A Cable
```

---

### 6. Upload Code

Click:

```text
Upload (→)
```

Wait until the IDE displays:

```text
Done Uploading.
```

---

## 📚 Required Libraries

Install the required libraries through Arduino Library Manager.

### For DHT Sensors

* DHT Sensor Library
* Adafruit Unified Sensor

Installation:

```text
Arduino IDE
  → Tools
  → Manage Libraries
```

Search and install both libraries.

---

## 💻 Example LCD Output

```text
Temp: 24.5°C
Hum : 56%
```

---

## 📁 Project Structure

```text
arduino-temperature-humidity-monitor/
│
├── src/
│   └── temperature_humidity_monitor.ino
│
├── docs/
│   ├── project-photo.jpg
│   └── arduino_wiring_schematic.svg
│
├── README.md
```

---

## 🔧 Troubleshooting

### LCD Is Blank

* Verify LCD pin connections.
* Adjust the potentiometer slowly.
* Ensure LCD pin 5 (RW) is connected to GND.
* Confirm 5V and GND connections.

### Sensor Returns No Data

* Verify sensor VCC and GND.
* Ensure sensor OUT pin is connected to Arduino pin 7.
* Check that the correct sensor type is configured in code.

### Upload Failed

* Confirm correct COM port selection.
* Verify Arduino Uno board is selected.
* Reconnect the USB cable.
* Close Serial Monitor before uploading.

---

## 📈 Future Improvements

* Data logging to SD card
* Wi-Fi support with ESP8266/ESP32
* Cloud monitoring dashboard
* Alarm notifications
* Historical temperature graphs

---

## 🤝 Contributing

Pull requests and improvements are welcome.

1. Fork the repository
2. Create a feature branch
3. Commit changes
4. Push to GitHub
5. Open a Pull Request

---

## 📝 License

Distributed under the MIT License.

---

## 👨‍💻 Author

Created as an Arduino temperature and humidity monitoring project using an LCD 1602 display and Arduino Uno.
