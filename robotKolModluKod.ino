#include <Servo.h>
#include <SoftwareSerial.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

int pos1 = 90;
int pos2 = 90;
int pos3 = 90;
int pos4 = 90;
int pos5 = 90;
int pos6 = 90;


bool mPressed = false; // 'm' sinyalinin basılı olup olmadığını kontrol etmek için flag
bool isMoving = false; // Hareketin devam edip etmediğini kontrol etmek için flag


void setup() {
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);
  servo6.attach(11);

  Serial.begin(9600);
  Serial.println("Servo kontrol başlatıldı.");

  int pos1 = 90;
  servo1.write(pos1);
  delay(1000);
  servo5.write(150);
  delay(1000);
  servo4.write(175);
  delay(1000);
  int pos6 = 90;
  servo6.write(pos6);
  delay(1000);
  servo2.write(180);
  delay(1000);
  servo2.write(0);
  delay(1000);
  servo2.write(90);
  delay(1000);
  servo3.write(140);
  delay(1000);
  servo5.write(170);



}

void loop() {
  if (Serial.available() > 0) {
    char veri = Serial.read();
    veri = toupper(veri); // Harfleri büyük harfe çevir

    // Servo1 kontrol tutmaç
    if (veri == 'B' && pos1 < 180) {
      pos1 += 1;
      servo1.write(pos1);
      delay(15);
    }
    if (veri == 'A' && pos1 > 0) {
      pos1 -= 1;
      servo1.write(pos1);
      delay(15);
    }

    // Servo2 kontrol bilek sağ sol
    if (veri == 'C' && pos2 < 180) {
      pos2 += 1;
      servo2.write(pos2);
      delay(15);
    }
    if (veri == 'D' && pos2 > 0) {
      pos2 -= 1;
      servo2.write(pos2);
      delay(15);
    }

    // Servo3 kontrol bilek yukarı aşağı
    if (veri == 'E' && pos3 < 180) {
      pos3 += 1;
      servo3.write(pos3);
      delay(15);
    }
    if (veri == 'F' && pos3 > 0) {
      pos3 -= 1;
      servo3.write(pos3);
      delay(15);
    }

    //Servo4 kontrol dirsek
    if (veri == 'H' && pos4 < 180){
      pos4 += 1;
      servo4.write(pos4);
      delay(15);
    }
    if (veri == 'G' && pos4 > 0){
      pos4 -= 1;
      servo4.write(pos4);
      delay(15);
    }

    //Servo5 kontrol omuz
    if (veri == 'I' && pos5 < 180){
      pos5 += 1;
      servo5.write(pos5);
      delay(15);
    }
    if (veri == 'J' && pos5 > 0){
      pos5 -= 1;
      servo5.write(pos5);
      delay(15);
    }

        //Servo6 kontrol bel
    if (veri == 'K' && pos6 < 180){
      pos6 += 1;
      servo6.write(pos6);
      delay(15);
    }
    if (veri == 'L' && pos6 > 0){
      pos6 -= 1;
      servo6.write(pos6);
      delay(15);
    }

// "M" komutuna özel hareketler
    if (veri == 'M') {
      Serial.println("M komutu alındı. Motor hareketi başlıyor.");
      
      while (true) {  // Sonsuz döngü

 // 'N' tuşu serbest bırakıldığında, flag'i sıfırla
  if (Serial.available() > 0) {
    Serial.println("Seri haberleşme var");
    char veri = Serial.read();
    Serial.print("Gelen Veri:");
    Serial.println(veri);
      if (veri == 'N') {
         Serial.println("N tuşuna basıldı duruyor");
        break;
    }
  }
//Servo6 kontrol bel
    //Servo5 kontrol omuz
        //Servo4 kontrol dirsek
            // Servo3 kontrol bilek yukarı aşağı
                // Servo2 kontrol bilek sağ sol
                    // Servo1 kontrol tutmaç
        // 1. Motor 180 derece dönsün
        servo6.write(180);
        delay(2000); // 1 saniye bekle

        servo5.write(120);
        delay(2000); // 1 saniye bekle

        servo1.write(0);
        delay(2000); // 1 saniye bekle

        servo5.write(170);
        delay(2000); // 1 saniye bekle

        servo6.write(90);
        delay(2000); // 1 saniye bekle

        servo5.write(120);
        delay(2000); // 1 saniye bekle       

        servo1.write(90);
        delay(2000); // 1 saniye bekle

        servo5.write(170);
        delay(2000); // 1 saniye bekle





       
      }
    }
  }
}