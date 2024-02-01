#define MOTION_SENSOR_PIN 2
#define BUTTON_PIN 4
#define LED_PIN 12

int motionState = 0;
bool buttonPressed = false;

void setup() {
  Serial.begin(9600);
  pinMode(MOTION_SENSOR_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Use internal pull-up resistor for push button
  pinMode(LED_PIN, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonInterrupt, CHANGE);
}

void loop() {
  buttonInterrupt();
  if (!buttonPressed) {
    motionState = digitalRead(MOTION_SENSOR_PIN);
    Serial.print("Motion Sensor: ");
    Serial.println(motionState);
    if (motionState == HIGH) {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED: ON");
    } else {
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED: OFF");
    }
    delay(500);
  }
}
// Interrupt Service Routine for push button
void buttonInterrupt() {
 if (digitalRead(BUTTON_PIN) == LOW) { // If button is pressed
    digitalWrite(LED_PIN, HIGH); // Turn on the LED
  Serial.println("Interrupted!!");
 } else {
    digitalWrite(LED_PIN, LOW); // Turn off the LED
   Serial.println("Not Interrupt!!");
  }
  delay(500);
}
