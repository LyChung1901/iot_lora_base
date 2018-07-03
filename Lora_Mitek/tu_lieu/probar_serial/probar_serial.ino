char c;
int a;

void setup() {
  Serial.begin(9600);
}
void medir();
void loop() {
  if (Serial.available()) {
    c = Serial.read();
    switch (c) {
      case 'A':
        medir();
        break;
    }
  }
}

void medir() {
  while (c != 'D') {
    a = analogRead(0);
    Serial.println(a);
    if (Serial.available()) {
      c = Serial.read();
      if (c == 'D') {
        return;
      }
    }
    delay(200);
  }
}

