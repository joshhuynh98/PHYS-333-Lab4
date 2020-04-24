long t0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT); // assuming the IR heating lamp is attached to pin 13
  t0 = millis();
}

void loop() {
int reading = analogRead(A0);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  float temp = voltage/0.01;

  if (temp<98) {
    digitalWrite(13, HIGH);
  }
  if (temp>100) {
    digitalWrite(13, LOW);  
  }
  
  delay(500);
}
