//#include <string>
// Serial test script
int buttonPins[] = {4, 7};
int nrOfButtons = 2;
int digitalPins[];
int digitalVals[];
int analogPins[];
int analogVals[];

void setup()
{

  Serial.begin(9600);  // initialize serial communications at 9600 bps
  Serial.print("Setup");
  for(int i = 0; i < nrOfButtons; i++){
    pinMode(buttonPins[i], INPUT);
  }
}

void loop()
{
  for(int i=0; i<(sizeof(digitalPins)/sizeof(digitalPins[0]));i++){
    checkDigitalInputs(i);
  }
  for(int j=0; j<(sizeof(analogPins)/sizeof(analogPins[0]));j++){
    checkAnalogInputs(j);
  }
}



void checkAnalogInputs(int i){
}


void checkDigitalInputs(int i){
  int state = digitalRead(digitalPins[i]);
  if(state!=digitalVals[i]){
    Serial.print();
    Serial.print("\n");
    Serial.flush();
    delay(10);
  }
}


void GAMMELKODE(){
      //while(!Serial.available()) {}
  delay(1000);

  // serial write section
  String preamble = "FFFE";
  for(int i = 0; i < nrOfButtons; i++){
    bool buttonState = digitalRead(buttonPins[i]);
    if(buttonState)
    {
      
      Serial.print(preamble);
      int ard_sends = i;
      Serial.print(ard_sends);
      Serial.print("\n");
      Serial.flush();
      delay(10); 
    }
  }
}
