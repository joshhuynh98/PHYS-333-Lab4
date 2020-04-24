long t0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT); // the LED representative of the cooker heater connected to pin 13
  t0 = millis();

  boil();
}

void loop() {
  warm();
}

void boil() {
  int reading = analogRead(A0);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  float temp = voltage/0.01;

  while ((millis()-t0) < 1200000) { // cook for 20 minutes
    if (temp<212) { // boiling temp in F
      pwm(500,100,10,13); // 100% power
    }
  }
}

void warm() {
  int reading = analogRead(A0);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  float temp = voltage/0.01;

  if (temp<150) { // warm rice temp
    pwm(500,50,10,13); // 50% power
  }
}

void pwm(float duration, float power, float period, int pin) {
  /*
  duration (ms)
  power (out of 1000)
  period (microseconds)
  output pin
  */
  unsigned long time_0 = millis();

  while ((millis()-time_0) < duration) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(power*period);
    digitalWrite(pin, LOW);
    delayMicroseconds((1000-power)*period);
  }
  return;
}
