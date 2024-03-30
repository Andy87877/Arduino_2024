// 數位類比
int sensorPin = A0; //電位計(可變電阻)接A0
int ledPin = 2; // LED接
int sensorValue = 0; //可變電阻的值

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // 開啟
}

void loop(){
  sensorValue = analogRead(sensorPin); //讀取可變電阻的值
  Serial.print("sensor =");
  Serial.println(sensorValue);
  
  digitalWrite(ledPin, HIGH);
  delay(sensorValue);
  digitalWrite(ledPin, LOW);
  delay(sensorValue);
}
