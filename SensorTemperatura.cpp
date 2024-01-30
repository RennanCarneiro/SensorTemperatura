// C++ code
//
int counter;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  if ((-40 + 0.488155 * (analogRead(A0) - 20)) < 25) {
    // BLUE LED < 25
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
    noTone(7);
  }
  if ((-40 + 0.488155 * (analogRead(A0) - 20)) >= 25 && (-40 + 0.488155 * (analogRead(A0) - 20)) <= 37) {
    // YELLOW LED >= 25
    digitalWrite(12, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(12, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(12, LOW);
  } else {
    digitalWrite(12, LOW);
  }
  if ((-40 + 0.488155 * (analogRead(A0) - 20)) > 37) {
    for (counter = 0; counter < 10; ++counter) {
      // RED LED > 37
      digitalWrite(8, HIGH);
      tone(7, 165, 1000); // play tone 40 (E3 = 165 Hz)
      delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(8, LOW);
      delay(1000); // Wait for 1000 millisecond(s)
      noTone(7);
    }
  } else {
    digitalWrite(8, LOW);
    noTone(7);
  }
}
