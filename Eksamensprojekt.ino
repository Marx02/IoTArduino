//140 = 90 degrees

// defines pins numbers

//rotation motor
const int stepPin1 = 6;
const int dirPin1 = 7;
int rotateButton = 2;
//elevation motor
const int stepPin2 = 4; 
const int dirPin2 = 5 ;
int downButton = 3;
int upButton = 9;
int state = 1;

volatile boolean buttonState = true;
 
void setup() {
  //rotation
  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
  pinMode(downButton, INPUT_PULLUP);
  pinMode(upButton, INPUT_PULLUP);

  //elevation
  pinMode(stepPin2,OUTPUT); 
  pinMode(dirPin2,OUTPUT);
  pinMode(rotateButton, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(rotateButton), Rotate90, LOW);
  attachInterrupt(digitalPinToInterrupt(downButton), downUp, LOW);
  Serial.begin(9600);
}
void loop() {
  /*
  if (digitalRead(rotateButton) != buttonState)
  {
    buttonState = !buttonState;
    Serial.print("This button is ");
    Serial.println(buttonState);
  }

  if (digitalRead(upButton) == HIGH != buttonState){
    buttonState = !buttonState;
    Serial.println("GOING UP");
    digitalWrite(dirPin2,HIGH); 
      digitalWrite(stepPin2,HIGH);
      delayMicroseconds(1000);
  */
  
}


void Rotate90(){
  Serial.println("ROTATE");
  digitalWrite(dirPin1,LOW); 
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 140; x++) {
    digitalWrite(stepPin1,HIGH);
    delayMicroseconds(1000);
  }
}    
void downUp(){
  Serial.println("ELEVATION");

    digitalWrite(dirPin2,HIGH); 
    // Makes 400 pulses for making two full cycle rotation
    for(int x = 0; x < 140; x++) {
      digitalWrite(stepPin2,HIGH);
      delayMicroseconds(1000);
      digitalWrite(stepPin2,LOW);
      delayMicroseconds(1000);
    }
 
}

/*void 90Spin(){
  for(int x = 0; x < 140; x++) {
    digitalWrite(stepPin1,HIGH);
    delayMicroseconds(1000);
}
*/
