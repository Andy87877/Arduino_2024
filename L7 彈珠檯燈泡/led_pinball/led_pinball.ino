//彈珠台燈泡
#include <Bounce2.h> //防止按鈕反覆彈跳
#define buttonPin 13 //按鈕接腳
#define delayTime 20 //按鈕的延遲時間
#define baudrate 9600 //監控視窗rate
#define count 8 //燈泡數量

int sensorPin = A0; //電位計(可變電阻)接A0  
int sensorValue = 0;// 變數存放A0狀態(0-1023) 
int outputValue = 0;//存放A0壓縮後的值(0-100)
//先定義了一個名為 bouncer 的物件，需要指定讀取的接腳及延遲時間
Bounce bouncer = Bounce(buttonPin, delayTime);    

boolean ledState; //燈泡狀態
int ledPin[] = {2,3,4,5,6,7,8,9};    //設定3~9為LED接腳
int index[4] = {0,0,0,0}; //燈泡亮度位置

void analogRead_sensor(){ //讀取可變電阻
    sensorValue = analogRead(sensorPin);//讀取sensorPin的值
    outputValue = map(sensorValue, 0, 1023, 0, 200);//等比例壓縮
}
void Bouncer(){ //判斷是否按按鈕
  //讀取接腳的狀態且判斷狀態是否有變化
  if (bouncer.update() == true && bouncer.read() == LOW) {  
      ledState = !ledState;
      Serial.print("按鈕狀況(0停 1閃):   ");
      Serial.println(ledState);
  }
}

void delay_or_not(){ //判斷是否要delay
    analogRead_sensor();
    Bouncer();//判斷按按鈕
    if(ledState==1) delay(outputValue);    //電位計調整改變延遲時間
}

void setup() {
    Serial.begin(baudrate);
    randomSeed(analogRead(A0));//亂數種子
    pinMode(buttonPin, INPUT_PULLUP); //定義按鈕接腳為輸入並啟用開發板內建的上拉電阻
    ledState = LOW;

    
    for(int i=0;i<count;i++){
      digitalWrite(ledPin[i],LOW); //開閉led燈
    }  
    
    for (int i = 0;i<count;i++){
      pinMode (ledPin[i],OUTPUT);//開啟輸出接腳
    }
}

void loop() { //主程式
    delay_or_not(); 
    // 按一下
    if(ledState==1){
        for (int i = 0; i < 4; i++){
          index[i]=random(count*1.5); //index[i]值亂數0~12抽一個
        }  
        delay_or_not();
        
        for (int i = 0; i < 4; i++){//index[i]值的燈亮起
          digitalWrite(ledPin[index[i]],HIGH);   
        }      
        delay_or_not();
        
        for (int i = 0; i < 4; i++){//index[i]值的燈熄滅
          digitalWrite(ledPin[index[i]],LOW);   
        }    
        delay_or_not(); 
    }else{
      for (int i = 0; i < 4; i++){//index[i]值的燈亮起
        digitalWrite(ledPin[index[i]],HIGH);   
      } 
    }
}
