/*VehicleBackupSensor*/

#define TRIG 5
#define ECHO 6
#define blue 9
#define green 10
#define red 11
#define buzzer 3

void setup() {

  Serial.begin(115200);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {

  float distance = getDistance();
  Serial.println(distance);
  if(distance < 3 || distance > 807){ 

    setColor(255, 0, 0); // red
    tone(buzzer, 1000);
    delay(500);
    noTone(buzzer);
    delay(500);

  }else if(distance < 15){ 

    setColor(0, 255, 0); // green

  }else{

    setColor(0, 0, 0);

  }

   delay(100);

}

void setColor(int r, int g, int b) {

  analogWrite(red, r);
  analogWrite(green, g);
  analogWrite(blue, b);

}


float getDistance() {

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long duration = pulseIn(ECHO, HIGH);
  float distance = duration / 58.0; 
  return distance;

}