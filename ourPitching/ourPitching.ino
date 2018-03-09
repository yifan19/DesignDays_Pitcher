#include "ArduinoMotorShieldR3.h"
void stop(ArduinoMotorShieldR3* myM){
  myM->setBrake2();
}

void setPWM(ArduinoMotorShieldR3& myM){

  int incomingByte;
  float myNum = 0; 
  int numArray[32];
  int numSize = 0;
  int done = false;

  if (Serial.available()){
    
    while (!done){

      incomingByte = Serial.read();
      Serial.println(incomingByte);
      if (incomingByte == '\n'){
         done = true;
      } else {
        incomingByte -= 49;
        numArray[numSize] = incomingByte;
        numSize++;
      }
    }
  }



    
  for (int i = 0 ; i < numSize ; i++){
       
    myNum *= 10; // 0 *10 = 0
    myNum += numArray[numSize]; // 0 + 5
    Serial.println(myNum);
    
  }
  
  myM.setSpeed2(myNum/255,myNum/255); 
} 


ArduinoMotorShieldR3 myMotor;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myMotor.init();

myMotor.setSpeed2(0.5,0.5); 


analogWrite(3,255); //maximum power on A
analogWrite(11,255); // maximum power on B


//analogWrite(3,255); //maximum power on A

//analogWrite(11,255); // maximum power on B
stop(&myMotor);

Serial.println("I am READY");
Serial.println("please enter the PWM you want");

return;


}



void loop() {
  int incomingByte;
  // put your main code here, to run repeatedly:
  if (Serial.available()){
  setPWM(myMotor);
  }
}
