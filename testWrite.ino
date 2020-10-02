#define DIGITALPREAMBLE "FFFE";
#define ANALOGPREAMBLE "FEFE";

int digitalPins[30];
int digitalVals[30];
int analogPins[10];
int analogVals[10];


/******************************************
* 
* Baktanken med koden er at Man har én metode for hver inputtype.
* De digitale sender bare hvis de er endret.
* Pythonkoden holder styr på om det skal sendes signal videre.
* Muligens bør trottle skilles ut fra analoge
*
*******************************************/


void setup()
{
  Serial.begin(9600);  // initialize serial communications at 9600 bps
  Serial.print("Setup");
  //Setting up digital pins
  int counter = 0;
  for(int i = D22; i < D49; i++){
    pinMode(i, INPUT);
    digitalPins[counter] = i;
    digitalVals[counter] = 0;
    counter++;
  }
  counter =0;
  for(int i = A0;i<A14;i++){
    pinMode(i, INPUT);
    analogPins[counter] = i;
    analogVals[counter] = 0;
    counter++;
  }
}

void loop()
{
  Serial.print(DIGITALPREAMBLE);
  for(int i=0; i<(sizeof(digitalPins)/sizeof(digitalPins[0]));i++){
    checkPushBottonInputs(i);
  }
  delay(5);
  Serial.flush();
    checkAnalogInputs();
  delay(15);
}



void checkAnalogInputs(){
  for(int i=0; i<(sizeof(analogPins)/sizeof(analogPins[0]));i++){
    analogVals[i]=analogRead(i);
  }
    Serial.print(ANALOGPREAMBLE);
    Serial.print(byte(analogVals));
    Serial.print("\n");
    Serial.flush();
}


void checkDIgitalInputs(int i){
  int state = digitalRead(digitalPins[i]);
  if(state!=digitalVals[i]){
    Serial.print(byte(i)));
    Serial.print("\n");
    digitalVals[i]=state;
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
