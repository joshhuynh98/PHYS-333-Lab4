long t0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(13, OUTPUT); // assuming the IR heating lamp is attached to pin 13
  pinMode(12, OUTPUT); // error indicating LED
  t0 = millis();
}

void loop() {
  int reading0 = analogRead(A0);
  float voltage0 = reading0 * 5.0;
  voltage0 /= 1024.0;
  float temp0 = voltage0/0.01;

  int reading1 = analogRead(A1);
  float voltage1 = reading1 * 5.0;
  voltage1 /= 1024.0;
  float temp1 = voltage1/0.01;

  if (temp0<98 && temp1<98) {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
  }
  else if (temp0>100 && temp1>100) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);  
  }
  else {
    digitalWrite(12, HIGH); // throws error
  }
  
  delay(500);
}
