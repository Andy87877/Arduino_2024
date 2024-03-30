//int firstLEDPin = 2, lastLedPin = 11;
int led_array[] = {2,3,4,5,6,7,8,9,10,11}; //燈泡接的接角
int ledCount = 10; //燈泡的數量

int sensorPin = A0; //電位計(可變電阻)接A0
int sensorValue = 0; //可變電阻的值
int outputValue = 0; //變數存放(0~1023壓縮值)MAP

void sensorValue_function();// 讀取可變電阻的值 並且 轉換成等比例的等待秒數
void LED_OUTPUT(); //霹靂燈運作

void setup() {
  for (int led = 0; led < ledCount; led++){
     pinMode(led_array[led], OUTPUT);
  }
  Serial.begin(9600); //開啟序列埠監控視窗
}

void loop() { //主程式
  sensorValue_function(); // 讀取可變電阻的值
  LED_OUTPUT(); //霹靂燈運作
}

void sensorValue_function(){ // 讀取可變電阻的值 並且 轉換成等比例的等待秒數
  sensorValue = analogRead(sensorPin); //讀取可變電阻的值   
  outputValue = map(sensorValue, 0, 1023, 1, 128); //等比例縮小控制範圍

  //print 序列埠監控視窗
  Serial.print("sensorValue =");
  Serial.print(sensorValue);
  Serial.print("      output =");
  Serial.println(outputValue);
}

void LED_OUTPUT(){ //霹靂燈運作
  for (int led = 0; led < ledCount; led++){
     sensorValue_function();// 讀取可變電阻的值
     
     digitalWrite(led_array[led], HIGH);
     delay(outputValue);
     digitalWrite(led_array[led], LOW);
  }
  for (int led = ledCount-1; led >= 0; led--){
     sensorValue_function();// 讀取可變電阻的值
    
     digitalWrite(led_array[led], HIGH);
     delay(outputValue);
     digitalWrite(led_array[led], LOW);
  }
}
