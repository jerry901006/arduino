#include "I2Cdev.h"
#include <Wire.h>
#include <MPU6050.h>
#include <BleMouse.h>

BleMouse bleMouse;
MPU6050 imu;
int16_t ax, ay, az, gx, gy, gz;
int vx, vy;
int buttonL = 0; // IO0 button  //宣告按鈕狀態預設為不按
int buttonR = 4;
int buttonLstate = HIGH;   //預設按鈕狀態預設為不按
int buttonRstate = HIGH;   //預設按鈕狀態預設為不按

void setup() {
  Serial.begin(115200);
  Wire.begin();
  pinMode(buttonL, INPUT_PULLUP);  //設定按鈕為輸入
  pinMode(buttonR, INPUT_PULLUP);  //設定按鈕為輸入
  
  Serial.print("MPU6050 initializing");
  imu.initialize();
  while (!imu.testConnection()) { Serial.print("."); }
  Serial.println();  
  Serial.println("BLE Mouse starting !");
  bleMouse.begin();
}

void loop() {
  imu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  vx =  -(ax+250)/200;  
  vy = -(ay-250)/200;
  
  
  Serial.print("ax = "); Serial.print(ax); 
  Serial.print(", ay = "); Serial.print(ay);
  Serial.print(", az = "); Serial.print(az);
  Serial.print("\t");
  Serial.print("X = ");    Serial.print(vx);
  Serial.print(", Y = ");  Serial.println(vy);
  
  bleMouse.move(vx, vy);
    
  buttonLstate = digitalRead(buttonL);  //讀取按鈕狀態
  buttonRstate = digitalRead(buttonR);  //讀取按鈕狀態
  
  if (buttonLstate == LOW) { // press button to Ground  //LOW代表按鈕按了
    bleMouse.click(MOUSE_LEFT);
    delay(100);
  } 
  else if(buttonRstate == LOW) { // press button to Ground  //LOW代表按鈕按了
    bleMouse.click(MOUSE_RIGHT);
    delay(100);
  }
  delay(100);
}
