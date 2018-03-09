#include "ArduinoMotorShieldR3.h"

#define TIMER_MAX 781 //OCR1A = [16 MHz / (2 * N * fDesired)] - 1, N is prescalar (1024)
//I put in a timer interrupt if you want one. Use the equation above and set TIMER_MAX to get fDesired.
//That is, it will call ISR(TIMER1_COMPA_vect) every 1/fDesired seconds. The default value gives 10 Hz.
int output1;

void stop(ArduinoMotorShieldR3& myM){
  //break the thing so it stops turning
  myM.setBrake2();
}


void setPWM(ArduinoMotorShieldR3& myM){

  int myNum = 0; 
  while (Serial.available() == 0){
    
  }
  myNum =  Serial.parseInt();
  //Serial.println(myNum);
  //myM.setSpeed2( (float) myNum/255, (float) myNum/255);
  analogWrite(3,myNum);
  
  analogWrite(11,myNum);
} 

ArduinoMotorShieldR3 myMotor;


void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

myMotor.init();
myMotor.setSpeed2(1,1); 

//pinMode(ENCODER_1, INPUT); // set ENCODER_1 to input
//pinMode(ENCODER_2, INPUT); // set ENCODER_2 to input
//InitializeInterrupt();
//interrupts();

//analogWrite(3,255); //maximum power on A

//analogWrite(11,255); // maximum power on B

return;


}



void loop() {
  


  //////////////////////////////////////////////////
  int incomingByte;
  Serial.println("Select A for PWM, B for current");
  
  while (Serial.available() == 0){
      //wait
  }
  
  incomingByte = Serial.read();
  
  if (incomingByte == 'A'){
    Serial.println("please enter a PWM value");
    setPWM(myMotor);
  }
  
  else if (incomingByte == 'B'){
    while (Serial.available() == 0){
      Serial.print("motor1: ");
      Serial.print(myMotor.getCurrent(1));
      Serial.print("   motor2: ");
      Serial.print(myMotor.getCurrent(2));
      Serial.print("\n");
      delay(1000);
    }
    Serial.read();
    
  }
  else {

    Serial.println("you f**ked up");
  }
  

}
  
  

