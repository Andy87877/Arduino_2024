int led = 4; // led燈
int SW_pin = 12; //按鈕
int val; // true or false

void setup(){
  Serial.begin(9600);
  pinMode(SW_pin, INPUT_PULLUP); //開啟上拉電阻
  pinMode(led, OUTPUT);
}

void loop(){
  val = digitalRead(SW_pin); //讀取數位接腳數值
  Serial.print("hi~");
  Serial.println(val);

  if (val == LOW){//按按鈕
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  delay(100);
}
