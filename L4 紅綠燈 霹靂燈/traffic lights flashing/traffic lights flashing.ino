int RED = 13, Yellow = 12, Green = 11;

void setup() {
  pinMode(13, OUTPUT);//red
  pinMode(12, OUTPUT);//yellow
  pinMode(11, OUTPUT);//green
}

//digitalWrite(Yellow, LOW); 
//delay(10);      

void loop() {   
  // 綠 2秒
  digitalWrite(RED, LOW); 
  digitalWrite(Yellow, LOW); 
  digitalWrite(Green, HIGH); 
  delay(2000); 

  // 綠 閃5
  for (int i = 0; i < 5; i++){
    digitalWrite(Green, LOW); 
    delay(200); 
    digitalWrite(Green, HIGH); 
    delay(200); 
  }

  //黃 1秒
  digitalWrite(Yellow, HIGH); 
  digitalWrite(Green, LOW); 
  delay(1000); 

  //紅 2秒
  digitalWrite(RED, HIGH); 
  digitalWrite(Yellow, LOW); 
  delay(2000); 
}
