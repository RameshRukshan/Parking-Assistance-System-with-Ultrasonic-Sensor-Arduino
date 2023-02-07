int frontLeftEcho = 12;
int frontLeftTriger = 13;
int backLeftEcho = 10;
int backLeftTriger = 11;
int backRightTriger = 9;
int backRightEcho = 8;
int frontRightTriger = 7;
int frontRightEcho = 6;

int buzzer = 5;

int frontLeftRed = 4;
int frontLeftGreen = 3;
int frontRightRed = 1;
int frontRightGreen = 2;
int backLeftRed = A0;
int backLeftGreen = A1;
int backRightRed = A2;
int backRightGreen = A3;

long duration, distanceFrontLeft, distanceFrontRight, distanceBackLeft, distanceBackRight;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(frontLeftEcho, INPUT);
  pinMode(frontLeftTriger, OUTPUT);
  pinMode(frontRightEcho, INPUT);
  pinMode(frontRightTriger, OUTPUT);
  pinMode(backLeftEcho, INPUT);
  pinMode(backLeftTriger, OUTPUT);
  pinMode(backRightEcho, INPUT);
  pinMode(backRightTriger, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(frontLeftRed, OUTPUT);
  pinMode(frontLeftGreen, OUTPUT);
  pinMode(frontRightRed, OUTPUT);
  pinMode(frontRightGreen, OUTPUT);
  pinMode(backLeftRed, OUTPUT);
  pinMode(backLeftGreen, OUTPUT);
  pinMode(backRightRed, OUTPUT);
  pinMode(backRightGreen, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(frontLeftTriger, HIGH);
  delay(5);
  digitalWrite(frontLeftTriger, LOW);

  duration = pulseIn(frontLeftEcho, HIGH);
  distanceFrontLeft = (duration/2) / 29.1;

  if(distanceFrontLeft < 50){
    tone(buzzer, 500, 500);
    delay(000);
    Serial.println("Less than 50 cm Front Left");
  }else if(distanceFrontLeft < 150){
    tone(buzzer, 500, 500);
    delay(1000);
    Serial.println("Less than 1.5m Front Left");
  }else if(distanceFrontLeft < 300){
    tone(buzzer, 500, 500);
    delay(2000);
    Serial.println("Less than 3m Front Left");
  }else{
    Serial.println("All ok Front Left");
  }

  Serial.print(distanceFrontLeft);
  Serial.print("cm Front Left | ");

  digitalWrite(frontRightTriger, HIGH);
  delay(5);
  digitalWrite(frontRightTriger, LOW);

  duration = pulseIn(frontRightEcho, HIGH); 
  distanceFrontRight = (duration/2) / 29.1;

  if(distanceFrontRight < 50){
    tone(buzzer, 500, 500);
    delay(000);
    Serial.println("Less than 50 cm Front Right");
  }else if(distanceFrontRight < 150){
    tone(buzzer, 500, 500);
    delay(1000);
    Serial.println("Less than 1.5m Front Right");
  }else if(distanceFrontRight < 300){
    tone(buzzer, 500, 500);
    delay(2000);
    Serial.println("Less than 3m Front Right");
  }else{
    Serial.println("All ok Front Right");
  }

  Serial.print(distanceFrontRight);
  Serial.print("cm Front Right | ");

  digitalWrite(backLeftTriger, HIGH);
  delay(5);
  digitalWrite(backLeftTriger, LOW);

  duration = pulseIn(backLeftEcho, HIGH);
  distanceBackLeft = (duration/2) / 29.1;

  if(distanceBackLeft < 50){
    tone(buzzer, 500, 500);
    delay(000);
    Serial.println("Less than 50 cm Back Left");
  }else if(distanceBackLeft < 150){
    tone(buzzer, 500, 500);
    delay(1000);
    Serial.println("Less than 1.5m Back Left");
  }else if(distanceBackLeft < 300){
    tone(buzzer, 500, 500);
    delay(2000);
    Serial.println("Less than 3m Back Left");
  }else{
    Serial.println("All ok Back Left");
  }

  Serial.print(distanceBackLeft);
  Serial.print("cm Back Left | ");

  digitalWrite(backRightTriger, HIGH);
  delay(5);
  digitalWrite(backRightTriger, LOW);

  duration = pulseIn(backRightEcho, HIGH);
  distanceBackRight = (duration/2) / 29.1;

  if(distanceBackRight < 50){
    tone(buzzer, 500, 500);
    delay(000);
    Serial.println("Less than 50 cm Back Right");
  }else if(distanceBackRight < 150){
    tone(buzzer, 500, 500);
    delay(1000);
    Serial.println("Less than 1.5m Back Right");
  }else if(distanceBackRight < 300){
    tone(buzzer, 500, 500);
    delay(2000);
    Serial.println("Less than 3m Back Right");
  }else{
    Serial.println("All ok Back Right");
  }

  Serial.print(distanceBackRight);
  Serial.print("cm Back Right | ");

  Serial.println();
  
  delay(250);
}
