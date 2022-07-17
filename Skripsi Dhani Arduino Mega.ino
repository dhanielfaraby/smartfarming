

const int R = 14;
const int L = 12;

const int sensorair = A0;
int nilaisensorair=0;

void setup(){
pinMode(R, OUTPUT);
pinMode(L, OUTPUT);

Serial.begin (9600);
}

void loop() {
  int level = analogRead(sensorair);
    nilaisensorair = analogRead(sensorair);

  if (level>1020){
  Serial.println("Air Penuh");
  Serial.println("Kapasitas air");
  Serial.println(nilaisensorair);
  digitalWrite(R, HIGH);
    delay (1000);

  }

else{
  Serial.println("Air Kosong");
  Serial.println("Kapasitas air");
  Serial.println(nilaisensorair);

  digitalWrite(R, LOW);
  delay (1000);
  }
}
