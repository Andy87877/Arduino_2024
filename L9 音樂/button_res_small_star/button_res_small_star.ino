/*小星星前奏曲*/
//不用迴圈彈奏音樂,避掉按鈕接受訊號時間
//請自創一段小音樂
//ppt CH11-17
//ppt CH11-21
int sensorPin = A0;    
int sensorValue = 0;  
int outputValue = 0;
#include <Bounce2.h>
#define delayTime 20 //定義延遲時間
#define buttonPin 2   //定義按鈕接腳
#define   Buzzer   3    // 定義Buzzer腳位
int led=8;
int i;
Bounce bouncer = Bounce(buttonPin, delayTime);
boolean buttonState=HIGH;//按鈕狀態初始值設為1,按下為0
int Frequency[]={0,262,294,330,349,392,494,532};//設定X Do Re Mi Fa So La Si Do
int arr[] = {5,3,3,4,2,2,1,2,3,4,5,5,5,5,3,3,4,2,2,1,3,5,5,3,2,2,2,2,2,3,4,3,3,3,3,3,4,5,5,3,3,4,2,2,1,3,5,5,1};
int beat[]= {1,1,2,1,1,2,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,4,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,2,1,1,2,1,1,1,1,4};
 
int duartion;
void setup() { 
  pinMode(buttonPin, INPUT_PULLUP); //定義按鈕接腳為輸入並啟用開發板內建的上拉電阻
  pinMode(Buzzer, OUTPUT); // 設定D3為數位輸出
  pinMode(led,OUTPUT); 
 digitalWrite(led,LOW);//關閉LED燈
  noTone(Buzzer);
}
void loop(){
  sensorValue = analogRead(sensorPin);
  outputValue = map(sensorValue, 0, 1023, 300, 1000);
  duartion=60000/outputValue;//計算每拍時間
  if (bouncer.update() == true && bouncer.read() == LOW){   //讀取接腳的狀態且判斷狀態是否有變化，因此這段程式碼的功能是當狀態發生變化且為低電位時改變 LED 的狀態。
    buttonState = !buttonState;
    Serial.println(buttonState);   
  }
  if(buttonState==0){
    tone(Buzzer,Frequency[arr[i]]); //發出Frequency陣列內之聲音配合節拍
    digitalWrite(led,HIGH);
    delay(beat[i]*duartion);
    noTone(Buzzer);//停止發出聲音
    digitalWrite(led,LOW);
    delay(beat[i]*duartion);
    if(i==49){
      i = 0;
    } else {
      i = i+1;
    }
  } else {
    i=0;
    noTone(Buzzer);
    digitalWrite(led,LOW);//關閉LED燈
  }
}


    
