#include <SoftwareSerial.h>
// put your setup code here, to run once:
//SoftwareSerial ArduinoSerial(14,15);
#define ArduinoSerial Serial3
//SoftwareSerial ArduinoSerial;

int trigger=1;

//IR Sensor intialized
int IR_FR = 0; //Mega A1
int IR_FL = 0; //Mega A2
int IR_BR = 0; //Mega A3
int IR_BL = 0; //Mega A4


int ir_level = 300; //assign IR sensitivity 

//Ultrasonic sensor pin assignment

#define echoPin 2
#define trigPin 3

#define echoPinB 6
#define trigPinB 7


//LDR sensor
int LDR_FR_input = A5;
int LDR_FR_value = 0; //LDR value holder

int LDR_FL_input = A6;
int LDR_FL_value = 0; //LDR value holder

int LDR_BR_input = A7; 
int LDR_BR_value = 0; //LDR value holder

int LDR_BL_input = A8;
int LDR_BL_value = 0; //LDR value holder



//Motors for movement
const int M1_in1 = 10;
const int M1_in2 = 11;
// const int M1_EnA = D12; connected straight to 5V

const int M2_in3 = 26;
const int M2_in4 = 28;
// const int M2_EnB = D30; connected straight to 5V

//Motor for shutter
const int M3_in3 = 34;
const int M3_in4 = 36;
// const int M3_EnA = D38; connected straight to 5V

int ledpin = 13;

float val;
float val2;
int turnon;
long duration_FR, distance_FR; 
long duration_BR, distance_BR;

void setup(){
Serial.begin(115200);
ArduinoSerial.begin(115200);
    pinMode(ledpin,OUTPUT);

   //Motor 1 and Motor 2
    pinMode(M1_in1,OUTPUT); 
    pinMode(M1_in2,OUTPUT); 
    pinMode(M2_in3,OUTPUT);  
    pinMode(M2_in4,OUTPUT); 

    //Motor for shutter
    pinMode(M3_in3,OUTPUT); 
    pinMode(M3_in4,OUTPUT); 

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

   pinMode(trigPinB, OUTPUT);
  pinMode(echoPinB, INPUT);
    

       

    loop();
}

void loop() {

  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

   long durationB, distanceB;
  digitalWrite(trigPinB, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPinB, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinB, LOW);
  durationB = pulseIn(echoPinB, HIGH);
  distanceB = (durationB/2) / 29.1;

  
while (ArduinoSerial.available()>0){
   val=ArduinoSerial.parseFloat();
//   val2=ArduinoSerial.parseFloat();

     Serial.println("rain= ");
    Serial.println(val); 
    

  if(ArduinoSerial.read()=='\n'){

    val2=ArduinoSerial.parseFloat();
    
  Serial.println("android =");
    Serial.println(val2);
}
  }

  


    //Get LDR values
      LDR_FR_value = analogRead(LDR_FR_input);
      LDR_FL_value = analogRead(LDR_FL_input);
      LDR_BR_value = analogRead(LDR_BR_input);
      LDR_BL_value = analogRead(LDR_BL_input);
      
  if (turnon>0 &&turnon<2){

// 
//
//       //move forward
//     digitalWrite(M1_in1,LOW) ; //motor1 input 1
//     digitalWrite(M1_in2,HIGH) ; //motor1 input 2
//     digitalWrite(M2_in3,HIGH) ; //motor2 input 1
//     digitalWrite(M2_in4,LOW) ; //motor2 input 22
     


  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  
if ((LDR_FL_value > 900) || (LDR_BR_value > 900) ){
        if(val<1){
      //stop moving
      digitalWrite(M1_in1,LOW); //motor1 input 1
      digitalWrite(M1_in2,LOW); //motor1 input 2
      digitalWrite(M2_in3,LOW); //motor2 input 1
      digitalWrite(M2_in4,LOW); //motor2 input 2

      delay(2000);
        }
        else{
      check();
        }
}

   else if ( distance < 25 ){
       //move backwards
      digitalWrite(M1_in1,HIGH) ; //motor1 input 1
      digitalWrite(M1_in2,LOW) ; //motor1 input 2
      digitalWrite(M2_in3,LOW) ; //motor2 input 1
      digitalWrite(M2_in4,HIGH) ; //motor2 input 2

      delay(4000);

      //turn left
      digitalWrite(M1_in1,LOW) ; //motor1 input 1
      digitalWrite(M1_in2,LOW) ; //motor1 input 2
      digitalWrite(M2_in3,HIGH) ; //motor2 input 1
      digitalWrite(M2_in4,LOW) ; //motor2 input 2

      delay(2500);
      
      digitalWrite(M1_in1,LOW) ; //motor1 input 1
      digitalWrite(M1_in2,LOW) ; //motor1 input 2
      digitalWrite(M2_in3,LOW) ; //motor2 input 1
      digitalWrite(M2_in4,LOW) ; //motor2 input 22
      delay(1000);
    }

  
    else {       
  //move forward
     digitalWrite(M1_in1,LOW) ; //motor1 input 1
     digitalWrite(M1_in2,HIGH) ; //motor1 input 2
     digitalWrite(M2_in3,HIGH) ; //motor2 input 1
     digitalWrite(M2_in4,LOW) ; //motor2 input 22
    }
    
  }// end if (turnon>0 &&turnon<2)
  

check();

 //software_Reset() ;

}
//Receive input from user here

//val 1 from sensors, val 2 from android command

void check(){
if(val2>0.00&&val2<2.00){
   val2=0.00;
   turnon=1;


//         //move forward
//     digitalWrite(M1_in1,LOW) ; //motor1 input 1
//     digitalWrite(M1_in2,HIGH) ; //motor1 input 2
//     digitalWrite(M2_in3,HIGH) ; //motor2 input 1
//     digitalWrite(M2_in4,LOW) ; //motor2 input 22

     
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

 

 if ((LDR_FR_value > 900) || (LDR_FL_value > 900) || (LDR_BR_value > 900) || (LDR_BL_value > 900)){
        
      //stop moving
      digitalWrite(M1_in1,LOW); //motor1 input 1
      digitalWrite(M1_in2,LOW); //motor1 input 2
      digitalWrite(M2_in3,LOW); //motor2 input 1
      digitalWrite(M2_in4,LOW); //motor2 input 2
      delay(1000);
}

  else if ( distance < 25 ){
       //move backwards
      digitalWrite(M1_in1,HIGH) ; //motor1 input 1
      digitalWrite(M1_in2,LOW) ; //motor1 input 2
      digitalWrite(M2_in3,LOW) ; //motor2 input 1
      digitalWrite(M2_in4,HIGH) ; //motor2 input 2

      delay(4000);

      //turn left
      digitalWrite(M1_in1,LOW) ; //motor1 input 1
      digitalWrite(M1_in2,LOW) ; //motor1 input 2
      digitalWrite(M2_in3,HIGH) ; //motor2 input 1
      digitalWrite(M2_in4,LOW) ; //motor2 input 2

      delay(3000);
      
      digitalWrite(M1_in1,LOW) ; //motor1 input 1
      digitalWrite(M1_in2,LOW) ; //motor1 input 2
      digitalWrite(M2_in3,LOW) ; //motor2 input 1
      digitalWrite(M2_in4,LOW) ; //motor2 input 22
      delay(1000);
    }

    else {       
  //move forward
     digitalWrite(M1_in1,LOW) ; //motor1 input 1
     digitalWrite(M1_in2,HIGH) ; //motor1 input 2
     digitalWrite(M2_in3,HIGH) ; //motor2 input 1
     digitalWrite(M2_in4,LOW) ; //motor2 input 22
    }
}

if((val2 > 1.0&& val2<3.00) || val > 0.0){ //go back inside and close the shutter
         Serial.println("hi this is 2");
         val2=0.00;
         turnon=0;
if (trigger >0 && trigger<2){
  
  trigger = 0;

  
  //close shutters
      digitalWrite(M3_in3,LOW) ; //motor1 input 1
      digitalWrite(M3_in4,HIGH) ; //motor1 input 2

      delay(6500);
      
      digitalWrite(M3_in3,LOW); //motor1 input 1
      digitalWrite(M3_in4,LOW);

 long durationB, distanceB;
  digitalWrite(trigPinB, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPinB, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinB, LOW);
  durationB = pulseIn(echoPinB, HIGH);
  distanceB = (durationB/2) / 29.1;


     //move backwards
      digitalWrite(M1_in1,HIGH) ; //motor1 input 1
      digitalWrite(M1_in2,LOW) ; //motor1 input 2
      digitalWrite(M2_in3,LOW) ; //motor2 input 1
      digitalWrite(M2_in4,HIGH) ; //motor2 input 2

      delay(7000);

if (distanceB < 25){

       digitalWrite(M1_in1,LOW) ; //motor1 input 1
      digitalWrite(M1_in2,LOW) ; //motor1 input 2
      digitalWrite(M2_in3,LOW) ; //motor2 input 1
      digitalWrite(M2_in4,LOW) ; //motor2 input 2

      //open shutters
      digitalWrite(M3_in3,HIGH) ; //motor1 input 1
      digitalWrite(M3_in4,LOW) ; //motor1 input 2
      delay(6500);
      
       digitalWrite(M3_in3,LOW) ; //motor1 input 1
      digitalWrite(M3_in4,LOW) ; //motor1 input 2

      donothing();
}
 donothing();
}

  
  
} //end of (val2 == 2 || val == 1) go back inside and close the shutter


if(val2 > 2.00&& val2<4.00){  
//opening* the curtains
//      digitalWrite(LED_BUILTIN, HIGH);


    //open* shutters
      digitalWrite(M3_in3,LOW) ; //motor1 input 1
      digitalWrite(M3_in4,HIGH) ; //motor1 input 2
      
      delay(6500);
            
      digitalWrite(M3_in3,LOW) ; //motor1 input 1
      digitalWrite(M3_in4,LOW) ; //motor1 input 
      val2=0.00;

donothing();


} //end of if(val2 == 3)

if (val2 > 3.00 && val2<5.00){
  //close* the curtains
//      digitalWrite(LED_BUILTIN, HIGH);
      
    //close* shutters
      digitalWrite(M3_in3,HIGH) ; //motor1 input 1
      digitalWrite(M3_in4,LOW) ; //motor1 input 2
      delay(6500);

      digitalWrite(M3_in3,LOW) ; //motor1 input 1
      digitalWrite(M3_in4,LOW) ; //motor1 input 
      val2=0.00;
donothing();

        

} //end of if (val == 0)


if (val < 1.00){
  
trigger = 1;

loop();
} //end of if (val == 0)


} // end of void check();
void donothing(){

   digitalWrite(M1_in1,LOW) ; //motor1 input 1
      digitalWrite(M1_in2,LOW) ; //motor1 input 2
      digitalWrite(M2_in3,LOW) ; //motor2 input 1
      digitalWrite(M2_in4,LOW) ; //motor2 input 2
      digitalWrite(M3_in3,LOW) ; //motor1 input 1
      digitalWrite(M3_in4,LOW) ; //motor1 input 
         Serial.println("done");
         val2=0.00;
         val=0.00;
         delay(2000);
         loop();
}




