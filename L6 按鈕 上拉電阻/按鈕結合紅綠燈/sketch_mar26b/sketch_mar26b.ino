// 7GREEN 8YELLOW 9RED
int G_led = 7, Y_led = 8, R_led = 9;
int SW_pin = 12; //按鈕
int val;

void traffic_light();// 紅綠燈

void setup(){
  Serial.begin(9600);
  pinMode(SW_pin, INPUT_PULLUP); //開啟上拉電阻
  pinMode(G_led, OUTPUT);
  pinMode(Y_led, OUTPUT);
  pinMode(R_led, OUTPUT);
}


void loop(){
  val = digitalRead(SW_pin); //讀取數位接腳數值
  Serial.print("按鈕: ");
  Serial.println(val);


  if (val == LOW){//按按鈕
    traffic_light();
  }

  //黃燈閃爍
  digitalWrite(Y_led, HIGH);
  delay(30);
  digitalWrite(Y_led, LOW);
  delay(30);
}

void traffic_light(){ // 紅綠燈
  digitalWrite(Y_led, LOW);
    digitalWrite(R_led, HIGH);
    delay(2000);
    digitalWrite(R_led, LOW);

    // 紅綠燈
    digitalWrite(G_led, HIGH);
    delay(2000);
    digitalWrite(G_led, LOW);

    for (int i = 0; i < 5; i++){
      digitalWrite(G_led, HIGH);
      delay(200);
      digitalWrite(G_led, LOW);
      delay(200);
    }
    digitalWrite(G_led, LOW);
    digitalWrite(Y_led, HIGH);
    delay(1000);
    digitalWrite(Y_led, LOW);
    digitalWrite(R_led, HIGH);
    delay(2000);
    digitalWrite(R_led, LOW);
}
