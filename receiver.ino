#include <SoftwareSerial.h>
#include <Stepper.h>
SoftwareSerial HC08(8,9); //8:rx 9:tx
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 4, 5, 10, 11);
#define RAIN 1
#define SUN 2
int state; 
void setup() {
   Serial.begin(9600); 
   HC08.begin(9600); 
   // set the speed at 60 rpm:
  myStepper.setSpeed(180);
    state=SUN;
}

/*String readLine(){
      String s =  "";
      char c;
      while((c = HC08.read()) !='\n')
      {
          s += c;
      }  
      delay(10);
      return s;
}*/
//String rcv_string;
char ch;
void loop() {
  if(state==SUN){
    if (HC08.available()){
      //Serial.println("data in");
      //rcv_string = readLine();
      ch=(char)HC08.read();
      //Serial.println((char)HC08.read());
      if(ch=='W'){
          //Serial.println("Emergency");  
          for(int i=0;i<30;i++){
             // Serial.println("clockwise");
              myStepper.step(stepsPerRevolution);
          }
          state=RAIN;
       }
      //Serial.println(rcv_string);  
    }
  }
  if(state==RAIN){
    if (HC08.available()){
      //Serial.println("data in");
      //rcv_string = readLine();
      ch=(char)HC08.read();
      //Serial.println((char)HC08.read());
      if(ch=='D'){
          //Serial.println("Emergency");  
          for(int i=0;i<30;i++){
             // Serial.println("clockwise");
              myStepper.step(-stepsPerRevolution);
          }
          state=SUN;
       }
      //Serial.println(rcv_string);  
    }
  }
}


