

#define echoPin 2
#define trigPin 3

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



void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
    

   //Motor 1 and Motor 2
    pinMode(M1_in1,OUTPUT); 
    pinMode(M1_in2,OUTPUT); 
    pinMode(M2_in3,OUTPUT);  
    pinMode(M2_in4,OUTPUT); 

    //Motor for shutter
    pinMode(M3_in3,OUTPUT); 
    pinMode(M3_in4,OUTPUT); 
 
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

 Serial.println("Distance: ");
 Serial.println(distance);


if (distance < 25){
  
     digitalWrite(M1_in1,HIGH) ; //motor1 input 1
     digitalWrite(M1_in2,LOW) ; //motor1 input 2
     digitalWrite(M2_in3,LOW) ; //motor2 input 1
     digitalWrite(M2_in4,HIGH) ; //motor2 input 22

     delay (3000);

     digitalWrite(M1_in1,LOW) ; //motor1 input 1
     digitalWrite(M1_in2,LOW) ; //motor1 input 2
     digitalWrite(M2_in3,LOW) ; //motor2 input 1
     digitalWrite(M2_in4,LOW) ; //motor2 input 22

     delay(1500);
}
     else {
            digitalWrite(M1_in1,LOW) ; //motor1 input 1
     digitalWrite(M1_in2,HIGH) ; //motor1 input 2
     digitalWrite(M2_in3,HIGH) ; //motor2 input 1
     digitalWrite(M2_in4,LOW) ; //motor2 input 22

          }
 
}
