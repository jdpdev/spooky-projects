unsigned long stepTimer = 0;
unsigned long stepEndTime = 0;
byte currentStep = 0;

#define STEPS 2
const byte stepPins[STEPS] = { 6, 9 }; 

void setup() {
  Serial.begin(9600);
  Serial.println("start neon animation");

  analogWrite(6, 0);
  analogWrite(9, 0);
}

void loop() {
  analogWrite(stepPins[currentStep], 0);
  currentStep++;
  
  if (currentStep >= STEPS) {
    currentStep = 0;
  }

  Serial.println(stepPins[currentStep]);
  analogWrite(stepPins[currentStep], 255);

  delay(2000);
}
