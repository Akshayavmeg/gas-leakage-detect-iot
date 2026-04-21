// Gas Leakage Detection System (MQ2 + LED + Buzzer)

int gasSensor = A0;
int buzzer = 8;
int led = 9;
int threshold = 600;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int gasValue = analogRead(gasSensor);
  Serial.println(gasValue);

  if (gasValue > threshold) {
    digitalWrite(led, HIGH);

    // Buzzer beeping pattern
    for (int i = 0; i < 3; i++) {
      tone(buzzer, 2000);
      delay(150);
      noTone(buzzer);
      delay(150);
    }
  } else {
    digitalWrite(led, LOW);
    noTone(buzzer);
  }

  delay(200);
}
