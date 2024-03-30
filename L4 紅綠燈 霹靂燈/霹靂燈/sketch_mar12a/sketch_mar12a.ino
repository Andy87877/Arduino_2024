int firstLEDPin = 2, lastLedPin = 11;

void setup() {
  for (int led = firstLEDPin; led <= lastLedPin; led++){
     pinMode(led, OUTPUT);
  }
  Serial.begin(115200); 
}

void loop() {   
  for (int speed = 1; speed < 50; speed++){
    Serial.println(speed);
    for (int led = firstLEDPin; led <= lastLedPin; led++){
       digitalWrite(led, HIGH);
       delay(speed);
       digitalWrite(led, LOW);
    }
    for (int led = lastLedPin; led >= firstLEDPin; led--){
       digitalWrite(led, HIGH);
       delay(speed);
       digitalWrite(led, LOW);
    }
  }
}
