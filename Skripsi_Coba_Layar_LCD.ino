#include <LiquidCrystal_I2C.h>

#include <Wire.h> 
LiquidCrystal_I2C lcd(0x27, 20, 4);
 const int Relay1=53;
 const int Lampu=51;
 void setup() {
  // put your setup code here, to run once:
  pinMode(Relay1, OUTPUT);
  pinMode(Lampu, OUTPUT);
  
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(3,1);
  lcd.print("Dhani Elfaraby");
  lcd.setCursor(5,2);
  lcd.print("DracoWorks");
  delay(1000);
  lcd.clear();
Serial.begin (9600);
  
}
void loop() {
  // put your main code here, to run repeatedly:
  int nilaisensorair = analogRead(A0);
  int nilaisensortanah = analogRead(A1);
  int nilaisensorldr = analogRead(A2); 
  

    if (nilaisensorair > 550) {
      Serial.println("===============");
      lcd.print("Air penuh");
      Serial.println("Air Penuh");
        lcd.setCursor(0,0);
        lcd.print("Tandon Penuh");
      Serial.print("Kapasitas air : ");
      Serial.println(nilaisensorair);
        lcd.setCursor(0,1);
        lcd.print("Kapasitas air : ");
        lcd.print(nilaisensorair);
      Serial.print("Level Kelembapan Tanah : ");
        if (nilaisensortanah > 900){
          Serial.println("Kering ");
          lcd.setCursor(0,2);
          lcd.print("Kelembapan : ");
          lcd.print("Kering");
        }
        else{
          Serial.println("Basah ");
          lcd.setCursor(0,2);
          lcd.print("Kelembapan : ");
          lcd.print("Basah");
        }
      Serial.print("Keadaan Cahaya : ");
      if (nilaisensorldr < 580){
        Serial.println("Cahaya Terang, Lampu Mati ");
        lcd.setCursor(0,3);
        lcd.print("Lampu Mati");
        digitalWrite(Lampu, LOW);
      }
      else{
        Serial.println("Cahaya Gelap, Lampu Hidup ");
        lcd.setCursor(0,3);
        lcd.print("Lampu Hidup");
        digitalWrite(Lampu, HIGH);
      }
      digitalWrite(Relay1, HIGH); //Relay High , Rangkaian terbuka, Pompa Mati
      Serial.println("===============");
      delay (2000);
      lcd.clear();
      }

   else if (nilaisensorair < 600){
      Serial.println("===============");
      Serial.println("Air Kosong");
        lcd.setCursor(0,0);
        lcd.print("Tandon kosong");
      Serial.print("Kapasitas air : ");
      Serial.println(nilaisensorair);
        lcd.setCursor(0,1);
        lcd.print("Kapasitas air : ");
        lcd.print(nilaisensorair);
      Serial.print("Level Kelembapan Tanah : ");
       if (nilaisensortanah > 900){
          Serial.println("Kering ");
          lcd.setCursor(0,2);
          lcd.print("Kelembapan : ");
          lcd.print("Kering");
        }
        else{
          Serial.println("Basah ");
          lcd.setCursor(0,2);
          lcd.print("Kelembapan : ");
          lcd.print("Basah");
        }
        Serial.print("Keadaan Cahaya : ");
      if (nilaisensorldr < 500){
        Serial.println("Cahaya Terang, Lampu Mati ");
        lcd.setCursor(0,3);
        lcd.print("Lampu Mati");
        digitalWrite(Lampu, LOW);
      }
      else{
        Serial.println("Cahaya Gelap, Lampu Hidup ");
        lcd.setCursor(0,3);
        lcd.print("Lampu Hidup");
        digitalWrite(Lampu, HIGH);
      }
      digitalWrite(Relay1, LOW); 
      Serial.println("===============");

      delay (2000);
      lcd.clear();
      }
    }
