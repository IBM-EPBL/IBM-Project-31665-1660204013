// C++ code
//
int sensorvalue = 0;
int temperature = 0;

void setup()
{
  pinMode(8, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  sensorvalue = digitalRead(8);
  Serial.println(sensorvalue);
  if (sensorvalue == 1) {
    digitalWrite(3, HIGH);
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(3, LOW);
    digitalWrite(7, LOW);
  }
  delay(1000); // Delay a little bit to improve simulation performance
  //  temperature monitoring
  temperature = (-40 + 0.488155 * (analogRead(A1) - 20));
  if (temperature < 36) {
    analogWrite(11, 51);
    analogWrite(10, 204);
    analogWrite(9, 0);
  }
  if (temperature > 36) {
    analogWrite(11, 255);
    analogWrite(10, 102);
    analogWrite(9, 0);
  }
  if (temperature > 38) {
    analogWrite(11, 255);
    analogWrite(10, 0);
    analogWrite(9, 0);
  }
  delay(1000); // Delay a little bit to improve simulation performance
}