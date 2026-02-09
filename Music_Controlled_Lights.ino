const int soundSensor = 2;
const int redLed = 3;
const int greenLed = 5;
const int blueLed = 6;

void setup() {

  Serial.begin(9600);

  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
}


void loop() {
  int soundValue = digitalRead(soundSensor);
  Serial.print("Sound Level:  ");
  Serial.println(soundValue);
  digitalWrite(redLed, soundValue);
  digitalWrite(greenLed, soundValue);
  digitalWrite(blueLed, soundValue);
  delay(10);
}
