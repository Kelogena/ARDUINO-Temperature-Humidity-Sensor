/*
  TEMPERATURE STATION
  Arduino Uno + DHT11 + 1602A LCD (direct, no I2C) + Buzzer + LED

  LCD WIRING (count pins from left to right on the LCD):
  -------------------------------------------------------
  LCD pin 1  (GND / VSS)  -> Arduino GND
  LCD pin 2  (VCC / VDD)  -> Arduino 5V
  LCD pin 3  (Contrast V0)-> middle leg of potentiometer
                             left leg of pot  -> Arduino 5V
                             right leg of pot -> Arduino GND
                             (turn pot to adjust screen brightness)
  LCD pin 4  (RS)         -> Arduino pin 12
  LCD pin 5  (RW)         -> Arduino GND
  LCD pin 6  (EN)         -> Arduino pin 11
  LCD pin 7  (D0)         -> NOT CONNECTED
  LCD pin 8  (D1)         -> NOT CONNECTED
  LCD pin 9  (D2)         -> NOT CONNECTED
  LCD pin 10 (D3)         -> NOT CONNECTED
  LCD pin 11 (D4)         -> Arduino pin 5
  LCD pin 12 (D5)         -> Arduino pin 4
  LCD pin 13 (D6)         -> Arduino pin 3
  LCD pin 14 (D7)         -> Arduino pin 6
  LCD pin 15 (LED+)       -> Arduino 5V  (backlight on)
  LCD pin 16 (LED-)       -> Arduino GND

  DHT11 WIRING:
  -------------
  3-pin breakout board:
    Left  pin (S / DAT) -> Arduino pin 7
    Middle pin (VCC)    -> Arduino 5V
    Right  pin (GND)    -> Arduino GND

  4 bare pins (no board):
    Pin 1 (VCC)  -> Arduino 5V
    Pin 2 (DATA) -> Arduino pin 7
                   + 10k resistor between pin 7 and 5V
    Pin 3        -> nothing
    Pin 4 (GND)  -> Arduino GND

  BUZZER:
  -------
    Long  leg (+) -> 100 ohm resistor -> Arduino pin 9
    Short leg (-) -> Arduino GND

  LED:
  ----
    Long  leg (+) -> 220 ohm resistor -> Arduino pin 8
    Short leg (-) -> Arduino GND

  POTENTIOMETER (10k from your kit):
  -----------------------------------
  You NEED this to see anything on the LCD.
  It controls the contrast of the screen.
    Left  leg -> Arduino 5V
    Middle leg-> LCD pin 3
    Right leg -> Arduino GND
  After wiring, turn the knob slowly until text appears.

  LIBRARIES NEEDED (Sketch -> Include Library -> Manage Libraries):
    1. DHT sensor library  by Adafruit
       (say YES when it offers Adafruit Unified Sensor)
    NOTE: LiquidCrystal is already built into Arduino IDE - no install needed!

  BOARD: Tools -> Board -> Arduino Uno
*/

#include <DHT.h>
#include <LiquidCrystal.h>   // built-in, no install needed

// ---------- pins ----------
#define DHT_PIN     7
#define DHT_TYPE    DHT11
#define BUZZER_PIN  9
#define LED_PIN     8

// LCD pins: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

// ---------- settings ----------
#define TEMP_ALARM  28    // buzzer triggers above this in Celsius

// ---------- state ----------
DHT dht(DHT_PIN, DHT_TYPE);
unsigned long lastReadTime = 0;
unsigned long lastBeepTime = 0;
bool beepState   = false;
bool alarmActive = false;

void setup() {
  Serial.begin(9600);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  dht.begin();

  lcd.begin(16, 2);   // 16 columns, 2 rows

  // boot message
  lcd.setCursor(0, 0);
  lcd.print("  TEMP STATION  ");
  lcd.setCursor(0, 1);
  lcd.print("  Starting...   ");
  delay(2000);
  lcd.clear();

  Serial.println("Temperature Station ready.");
  Serial.println("------------------------------");
}

void loop() {
  unsigned long now = millis();

  // read sensor every 2 seconds
  if (now - lastReadTime >= 2000) {
    lastReadTime = now;

    float humidity    = dht.readHumidity();
    float temperature = dht.readTemperature();

    // sensor failed?
    if (isnan(humidity) || isnan(temperature)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Sensor error!   ");
      lcd.setCursor(0, 1);
      lcd.print("Check wiring    ");
      Serial.println("ERROR: DHT11 read failed. Check wiring.");
      alarmActive = false;
      return;
    }

    // row 0: temperature
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature, 1);
    lcd.print(" C      ");

    // row 1: humidity
    lcd.setCursor(0, 1);
    lcd.print("Humi: ");
    lcd.print(humidity, 1);
    lcd.print(" %      ");

    // alarm check
    if (temperature >= TEMP_ALARM) {
      alarmActive = true;
      digitalWrite(LED_PIN, HIGH);
    } else {
      alarmActive = false;
      digitalWrite(LED_PIN, LOW);
      digitalWrite(BUZZER_PIN, LOW);
      beepState = false;
    }

    // Serial Monitor output
    Serial.print("Temp: ");
    Serial.print(temperature, 1);
    Serial.print(" C    Humidity: ");
    Serial.print(humidity, 1);
    Serial.print(" %");
    if (alarmActive) Serial.print("   *** TOO HOT ***");
    Serial.println();
  }

  // buzzer beeps every 500ms while alarm is on
  if (alarmActive && now - lastBeepTime >= 500) {
    lastBeepTime = now;
    beepState = !beepState;
    digitalWrite(BUZZER_PIN, beepState ? HIGH : LOW);
  }
}
