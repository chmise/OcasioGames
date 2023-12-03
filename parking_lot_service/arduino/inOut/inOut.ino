#include <Servo.h>
#define ECHO_PIN 12
#define TRIG_PIN 13

Servo servo; //Servo 클래스로 servo객체 생성
int servoAngle = 0; //Servo 각도를 조절할 변수 servoAngle
unsigned long timer;
long duration, distance;
boolean is_reached = false; //"Reached"를 이미 출력했는지를 확인하는 변수

void setup() 
{ 
  //핀 입출력 설정
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  servo.attach(A5);
}
//현재 시간 가져오기


long measureDistance() //초음파 센서 동작으로 거리가 리턴값임
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  return (duration / 2) / 29.1;
}

void controlServo() //Servo 각도 조작 로직
{
  if (distance < 10) 
  {
    servoAngle = 0;
    servo.write(servoAngle);
    timer = millis();
    is_reached = true;
  } else if (millis() - timer > 5000 && distance >= 20) 
  {
    servoAngle = 90;
    servo.write(servoAngle);
    is_reached = false;
  }
}

void loop() //메인루프
{
  distance = measureDistance();

  if (distance < 10 && !is_reached) // 시리얼통신 조건
  {
    Serial.println("Reached");
    is_reached = true;
  } else if (distance >= 10 && is_reached) 
  {
    is_reached = false;
  }

  controlServo();
  delay(500);
}