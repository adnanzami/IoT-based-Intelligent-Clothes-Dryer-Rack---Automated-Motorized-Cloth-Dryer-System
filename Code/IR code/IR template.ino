
 int ir_analog = 0;     //initialize 
// int ir_digital = 4;   //Digital Pin 4


int ir_level = 300;   //IR sensor level

void setup() {
  // put your setup code here, to run once:

   Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  ir_analog = analogRead(A2);
 // ir_digital = digitalRead(4); 
 
  
  Serial.print("Analog value: ");
  Serial.println(ir_analog);

 // Serial.print("Digital value: ");
 // Serial.println(ir_digital);
  
  delay(1000);
}
