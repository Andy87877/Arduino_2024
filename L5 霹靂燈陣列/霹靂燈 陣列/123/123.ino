//int firstLEDPin = 2, lastLedPin = 11;
int led_array[] = {2,3,4,5,6,7,8,9,10,11};
int ledCount = 9;

void setup() {
  for (int led = 0; led <= ledCount; led++){
     pinMode(led_array[led], OUTPUT);
  }
  Serial.begin(115200); 
}

void loop() {   
  for (int speed = 1; speed < 50; speed++){
//    Serial.println(speed);
    for (int led = 0; led <= ledCount; led++){
       Serial.println(led_array[led]);
       digitalWrite(led_array[led], HIGH);
       delay(speed);
       digitalWrite(led_array[led], LOW);
    }
    for (int led = ledCount; led >= 0; led--){
       Serial.println(led_array[led]);
       digitalWrite(led_array[led], HIGH);
       delay(speed);
       digitalWrite(led_array[led], LOW);
    }
  }
}
