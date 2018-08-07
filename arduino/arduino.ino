
bool buffer[1024];
bool ready;

void setup() {
  Serial.begin(2000000);
  pinMode(13,OUTPUT);
}

void loop() {
}

void serialEvent(){
  while (Serial.available()) {
    char value = Serial.read();
    if (value == '1') {   
      PORTB |= 0b00100000;
    } 
    else { // value == '0'
      PORTB &= 0b11011111; 
    };
    delay(1);
  }
}
