/*
 按鈕計數器~有彈跳現象
 */
int led=2;
int SW_pin = 13;  // 指定 D13 接腳連接按鈕
int val;//存放按鈕狀態的變數
int counter=0;//計數器變數
void setup()
  {
  Serial.begin(9600);  //開啟序列埠..速率為9600.與電腦連線
  
  pinMode(SW_pin, INPUT_PULLUP);//開啟上拉電阻
                               
  pinMode(led, OUTPUT);         // 規劃 接腳2為數位輸出接腳led
}

void loop() 
{
  Serial.println("hi");
   val = digitalRead(SW_pin);  // 讀取數位接腳13的值  
  //  delay(100);//按鈕按下後100ms再取信號(無法完全消除彈跳現象)
  if (val==LOW) {  // 依照電路設計  按下按鈕=0  放開按鈕=1
    digitalWrite(led, HIGH);  //　按下按鈕=>燈亮
   counter=counter+1;
    Serial.print("counter~");
    Serial.println(counter);
  }
  
  else {
    digitalWrite(led, LOW);   //　放開按鈕=>燈滅
  }

} 
