long t0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  t0 = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(A0);
  float voltage = reading * 5.0;
  voltage /= 1024.0;

  Serial.print(millis()-t0);
  Serial.println(" ms");

  Serial.print(reading);
  Serial.print(" pin A0");

  Serial.print(voltage);
  Serial.println(" volts");

  float temp = voltage/0.01;

  Serial.print(temp);
  Serial.println(" fahrenheit");

  delay(500);
}
