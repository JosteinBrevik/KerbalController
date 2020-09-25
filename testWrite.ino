//#include <string>
// Serial test script
int buttonPins[] = {4, 7};
int nrOfButtons = 2;

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
