#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED 0.91" (128x32)
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Ultrasonic pins (UPDATED)
#define TRIG_PIN 8
#define ECHO_PIN 9

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    while (1); // OLED not found
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(20, 10);
  display.println("DISTANCE");
  display.display();
  delay(1500);
}

void loop() {
  long duration;
  float distance;

  // Trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo
  duration = pulseIn(ECHO_PIN, HIGH, 30000);

  // Distance in cm
  distance = duration * 0.034 / 2;

  // OLED display
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Distance:");

  display.setTextSize(2);
  display.setCursor(0, 14);

  if (duration == 0) {
    display.println("No Obj");
  } else {
    display.print(distance, 1);
    display.print("cm");
  }

  display.display();

  // Serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
