String inputBuffer = "";  
char vectorChar[20];
bool EOF = false;

void setup() {
  inputBuffer.reserve(20);
  Serial.begin(115200);
  pinMode(13,OUTPUT);

}

void loop() { 
  if (EOF){                     
    EOF = false;               
    inputBuffer.toCharArray(vectorChar, 20);  
    int numeroEntero = atoi(vectorChar);      
   
    if (numeroEntero == 0x01){
        digitalWrite(13, HIGH);
    }
    else if (numeroEntero == 0x02){
      digitalWrite(13, LOW);
    }
    inputBuffer = "";
  }
}

void serialEvent(){
  while (Serial.available()) {
    char character = Serial.read();
    inputBuffer += character;
    if (character == '\n') {       
      EOF = true;                  
    } 
  }
}
