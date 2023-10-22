int pumpT1_T2 = 5;
int pumpT2_T1 = 3;
int pumpT2_T3 = 4;
int stirMotor = 2;
int phPin = A0;
bool processStarted = false; 


const int turbidityPin = A1; // Change this to the appropriate pin
float phValue,sensorValue = 0;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(pumpT1_T2, OUTPUT);
pinMode(pumpT2_T1, OUTPUT);
pinMode(pumpT2_T3, OUTPUT);
pinMode(stirMotor, OUTPUT);
}

void loop() {
  
   if (!processStarted) { // Only ask to start the process if it hasn't started already
    Serial.print("Start the process y/n:");
    char choose = Serial.read();
    Serial.println();
    if (choose == 'y') {
      processStarted = true; // Set the flag to indicate that the process has started
    }
  }

  if (processStarted) { // If the process has started, continue with your logic
    // Rest of your code here...
    Process();
  }
}

void Process(){
  PH(stirMotor, phPin);
    pumpOn(pumpT1_T2);
    int turbidityValue = turbidity(turbidityPin);
    int limit;
    if(turbidityValue > limit)
    {
      pumpOn(pumpT2_T1);
    }
    else {
      pumpOn(pumpT2_T3);
      
    }
}

int turbidity(int turbidityPin) {
  int turbidityValue = analogRead(turbidityPin); // Read analog value from sensor
  Serial.print("Turbidity Value: ");
  Serial.println(turbidityValue);
  delay(1000);
  
  return turbidityValue; // Return the turbidity value
}


void PH(int stirMotor, int phPin)
{
  int limit;
 phValue = analogRead(phPin);
  sensorValue = (phValue-200)/35;
  Serial.print("ph = ");
  Serial.println(sensorValue);
  if(sensorValue > limit)
  {
    // Turn on red led 
    // Add a button to start coagulation 
  }
  else {
    // turn on green led for 5secs 
   coagulationFlocuationSedimentation(stirMotor);
     
  }
}

void pumpOn(int pin)
{
  digitalWrite(pin,HIGH);
}

void pumpOff(int pin)
{
  digitalWrite(pin,LOW);
}

void stirMotorOn(int pin)
{
  digitalWrite(pin,HIGH);
  
}

void stirMotorOff(int pin)
{
  digitalWrite(pin,LOW);
}
void addCoagulant(){}

void coagulationFlocuationSedimentation(int pin)
{
   Serial.print("Start stirring the mixture? (y/n): ");
  char startStirring = Serial.read();
  Serial.println();

  if (startStirring == 'y') {
    stirMotorOn(pin); // Start stirring
    delay(5000);      // Rotate the motor for some time time = 180000
    stirMotorOff(pin); // Switch off the motor for floc particles to settle down
    delay(5000);
    stirMotorOn(pin); // slowly rotate the motor
    delay(5000); // final give 15 min
    stirMotorOff(pin);
    delay(100000);// in real 2hrs 
    }
  }
