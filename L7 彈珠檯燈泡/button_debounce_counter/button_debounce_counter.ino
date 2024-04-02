/* 去除開關彈跳.... 使用Bounce2.h 函式庫.... 按鈕計數器..搭配LED亮滅                              
 */                               
#include <Bounce2.h>   //引入函式庫
#define ledPin 2      //定義LED接腳 與 int ledPin = 2; 語法相同
#define buttonPin 13   //定義按鈕接腳
#define delayTime 20 //定義延遲時間
#define baudrate 9600 //定義鮑率(傳輸速率)
int counter=0;
boolean ledState=LOW;//存放LED亮滅狀態,初始變數存放LED關閉

Bounce bouncer = Bounce(buttonPin, delayTime);//先定義了一個名為 bouncer 的物件，需要指定讀取的接腳及延遲時間

void setup() {
    Serial.begin(baudrate);  //開啟序列埠..速率為9600
    pinMode(ledPin, OUTPUT); //定義LED接腳為輸出
    pinMode(buttonPin, INPUT_PULLUP); //定義按鈕接腳為輸入並啟用開發板內建的上拉電阻..按下為0 
                                       
    digitalWrite(ledPin,  LOW);
}

void loop() {
    if (bouncer.update() == true && bouncer.read() == LOW) {  //讀取接腳的狀態且判斷狀態是否有變化，因此這段程式碼的功能是當狀態發生變化且為低電位時改變 LED 的狀態。
        ledState = !ledState;
        counter=counter+1;
        digitalWrite(ledPin, ledState);
        Serial.print("counter~");
        Serial.println(counter);
    }
}
