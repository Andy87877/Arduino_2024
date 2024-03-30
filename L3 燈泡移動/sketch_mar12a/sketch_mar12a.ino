int RED = 13, Yellow = 12, Green = 11;

void setup() {
  pinMode(RED, OUTPUT);//red
  pinMode(Yellow, OUTPUT);//yellow
  pinMode(Green, OUTPUT);//green
}

void loop() {       
  digitalWrite(Yellow, LOW); 
  digitalWrite(RED, HIGH);   
  delay(10);      
  digitalWrite(RED, LOW); 
  digitalWrite(Yellow, HIGH);  
  delay(10);    
  digitalWrite(Yellow, LOW); 
  digitalWrite(Green, HIGH);   
  delay(10);   
  digitalWrite(Green, LOW); 
  digitalWrite(Yellow, HIGH);   
  delay(10);    
}
