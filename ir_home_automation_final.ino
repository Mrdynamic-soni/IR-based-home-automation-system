#include<IRremote.h>
#define button_1 3772784863
#define button_2 3772817503
#define button_3 3772801183

#define relay1 3
#define relay2 4
#define relay3 5
 int rec_pin =7;
 unsigned long key;
 IRrecv irrecv(rec_pin);
 decode_results results;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();

  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(relay3,OUTPUT);

  digitalWrite(relay1,LOW);
  digitalWrite(relay2,LOW);
  digitalWrite(relay3,LOW);
}

void loop() {
 if(irrecv.decode(&results)){
  if(results.value == button_1)
  {
    if(digitalRead(3) == 0){
    digitalWrite(3,HIGH);
  }
  else{
    digitalWrite(3,LOW);
  }
 }
  if(results.value == button_2)
  {
    if(digitalRead(4) == 0){
    digitalWrite(4,HIGH);
  }
  else{
    digitalWrite(4,LOW);
  }
  }
  if(results.value == button_3)
  {
    if(digitalRead(5) == 0){
    digitalWrite(5,HIGH);
  }
  else{
    digitalWrite(5,LOW);
  }
  }
  irrecv.resume();
 }
 delay(200);
}
