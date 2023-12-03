#include<Servo.h> 
#define echo 12 
#define trig 13

Servo servo;  //Servo 클래스로 servo객체 생성
int servoAngle = 0;  // 각도를 조절할 변수 servoAngle
unsigned long timer;
long duration, distance;
boolean is_reached = false; // "Reached"를 이미 출력했는지를 확인하는 변수

void setup() 
{ //핀 입출력 설정
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  servo.attach(A5);
}

void loop() 
{
  //현재 시간 가져오기
  unsigned long currentMillis = millis();

  //차량 허가(나중에)
  
  //초음파 센서 시리얼통신
  digitalWrite(trig, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance < 10 && !is_reached) {  // 거리가 10 미만일 때
    Serial.println("Reached");
    is_reached = true; // "Reached"를 출력했음을 표시
  } else if (distance >= 10 && is_reached) { // 거리가 다시 10 이상이 되었을 때
    is_reached = false; // "Reached" 상태를 해제
  }

  
  //서보모터 90도
  if(distance < 10){
    servoAngle = 0;
    servo.write(servoAngle);
    timer = millis();
    is_reached = true;
  }

  //서보모터 원상태
  if(millis() - timer > 5000 && distance >= 20){
    servoAngle = 90;
    servo.write(servoAngle);
    is_reached = false;
  }

  delay(500);
}
