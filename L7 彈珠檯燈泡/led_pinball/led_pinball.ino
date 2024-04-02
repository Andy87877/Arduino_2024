/*      
 陣列:PPT3-34~35         
 */
 //改成會有4顆燈的彈珠台
 //說明random的使用
#include <Bounce2.h>
#define buttonPin 13   //定義按鈕接腳
#define delayTime 20    //定義延遲時間
#define baudrate 9600     //定義鮑率
int sensorPin = A0; //電位計(可變電阻)接A1  
     
int sensorValue = 0;// 變數存放A0狀態(0-1023) 
int outputValue = 0;//存放A0壓縮後的值(0-100)
Bounce bouncer = Bounce(buttonPin, delayTime);    //先定義了一個名為 bouncer 的物件，需要指定讀取的接腳及延遲時間
boolean ledState;
 int ledPin[] = {3,4,5,6,7,8,9,10,11,12};    //設定3~12為LED接腳
int a=1;    //設a變數為1索引值
int b=5;    //設b變數為5索引值
int c=7;    //設c變數為7索引值
int d=9;    //設d變數為9索引值
void setup() {
    Serial.begin(baudrate);
    randomSeed(analogRead(A0));//亂數種子
    pinMode(buttonPin, INPUT_PULLUP); //定義按鈕接腳為輸入並啟用開發板內建的上拉電阻
    ledState = LOW;
    for(int i=0;i<10;i++)
  {
    digitalWrite(ledPin[i],LOW);//開閉10顆led燈
  }  
    
    for (int i = 0;i<10;i++)
    {
    pinMode (ledPin[i],OUTPUT);//開啟3~12輸出接腳
    }
}

void loop() {
    sensorValue = analogRead(sensorPin);//讀取A1的值
  outputValue = map(sensorValue, 0, 1023, 0, 100);//等比例壓縮
    
    if (bouncer.update() == true && bouncer.read() == LOW) {  //讀取接腳的狀態且判斷狀態是否有變化，因此這段程式碼的功能是當狀態發生變化且為低電位時改變 LED 的狀態。
        ledState = !ledState;
        Serial.println(ledState);
    }
    if(ledState==1)
    {
      digitalWrite(ledPin[a],HIGH);   //a值的燈亮起
      digitalWrite(ledPin[b],HIGH);   //b值的燈亮起
      digitalWrite(ledPin[c],HIGH);   //c值的燈亮起
      digitalWrite(ledPin[d],HIGH);   //c值的燈亮起
      
      delay(outputValue);    //電位計調整改變延遲時間
      digitalWrite(ledPin[a],LOW);   //a值的燈暗掉 
      digitalWrite(ledPin[b],LOW);   //b值的燈暗掉
      digitalWrite(ledPin[c],LOW);   //c值的燈暗掉
      digitalWrite(ledPin[d],LOW);   //c值的燈暗掉
      
      delay(outputValue);    //電位計調整改變延遲時間
      a=random(10);   //a值為亂數0~9中抽一個,至少會有一顆燈亮
      b=random(20);   //b值為亂數0~19中抽一個,自行調整亮燈機率
      c=random(20);   //c值為亂數0~19中抽一個,自行調整亮燈機率
      d=random(20);   //d值為亂數0~19中抽一個,自行調整亮燈機率
    }
    //試試random(0,9)產生0~8亂數
    //試試random(5,9)產生5~8亂數
    else
    digitalWrite(ledPin[a],HIGH);   //a值索引值的燈亮起
    digitalWrite(ledPin[b],HIGH);   //b值索引值的燈亮起
    digitalWrite(ledPin[c],HIGH);   //c值索引值的燈亮起
    digitalWrite(ledPin[d],HIGH);   //c值索引值的燈亮起

}
