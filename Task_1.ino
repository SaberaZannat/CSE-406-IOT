

const int sensorPin = A0;            // Analog pin connected to sensor signal
const int dryValue = 900;            // Calibrate for your sensor (dry reading)
const int submergedValue = 200;      // Calibrate for your sensor (fully submerged)

const int LOW_LEVEL = 25;
const int MEDIUM_LEVEL = 75;
const int HIGH_LEVEL = 95;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  int percentage = map(sensorValue, dryValue, submergedValue, 0, 100);
  percentage = constrain(percentage, 0, 100);

  // Print values for plotting
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.println(percentage);

  // Check thresholds and print alerts
  if (percentage < LOW_LEVEL) {
    Serial.println("Alert: LOW WATER LEVEL");
  } else if (percentage < MEDIUM_LEVEL) {
    Serial.println("Water level is MEDIUM");
  } else if (percentage >= HIGH_LEVEL) {
    Serial.println("Alert: HIGH WATER LEVEL");
  }

  delay(100);
}





