#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

// Create objects for BME280 and OLED
Adafruit_BME280 bme;  // BME280 object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Timing for data refresh
unsigned long delayTime = 2000;

void setup() {
  Serial.begin(9600);

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // 0x3C is the default I2C address
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Initialize BME280 sensor
  if (!bme.begin(0x76)) {  // 0x76 is the default I2C address for BME280
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    for (;;)
      ;
  }

  // Initial display message
  display.setCursor(0, 0);
  display.println("BME280 Sensor");
  display.println("Initializing...");
  display.display();
  delay(2000);
}

void loop() {
  // Clear the display
  display.clearDisplay();

  // Get sensor data
  float temperature = bme.readTemperature();
  float humidity = bme.readHumidity();
  float pressure = bme.readPressure() / 100.0F;  // Convert to hPa

  // Print data to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");
  Serial.println();

  // Display data on OLED
  // display.setCursor(0, 0);
  //display.println("BME280 Sensor Data");
  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");

  display.setCursor(0, 10);
  display.print("Humidity: ");
  display.print(humidity);
  display.println(" %");

  display.setCursor(0, 20);
  display.print("Pressure: ");
  display.print(pressure);
  display.println(" hPa");

  display.display();

  // Wait for the next update
  delay(delayTime);
}
