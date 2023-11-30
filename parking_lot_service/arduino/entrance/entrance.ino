// 포트 정해두기 //echo 13, trig 12
#define echo 13 
#define trig 12
void setup() 
{
  //핀 입출력 설정
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() 
{

  //현재 시간 가져오기

  //차량 허가(아직 안해도됨)

  //초음파 센서 작동
  Serial.print(read_ultrasonic());
  Serial.println("[cm]");
  delay(500);

  //모터 90도

  //모터가 언제 내려갈지 정하고

  //현재 시간을 저장하고 모터 원위치

}

// 초음파 센서 함수(거리 계산)
double read_ultrasonic(){
  double return_time,howlong;
  digitalWrite(trig, HIGH);
  delay(5);
  digitalWrite(trig, LOW);
  return_time = pulseIn(echo, HIGH);
  howlong = 340. * return_time / (2.*10000);
  if (howlong > 99){
  howlong = 99;
  }
  return howlong;
}
