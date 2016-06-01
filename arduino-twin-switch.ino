#include <Servo.h>

#define MOTOR_1_PIN       9
#define MOTOR_1_ON_PIN    2
#define MOTOR_1_OFF_PIN   3
#define MOTOR_2_PIN       10
#define MOTOR_2_ON_PIN    4
#define MOTOR_2_OFF_PIN   5
#define MOTOR_3_PIN       11
#define MOTOR_3_ON_PIN    6
#define MOTOR_3_OFF_PIN   7

#define SWITCH_1_ON       1
#define SWITCH_1_OFF      2
#define SWITCH_2_ON       3
#define SWITCH_2_OFF      4
#define SWITCH_3_ON       5
#define SWITCH_3_OFF      6

#define DEGREE_ON         20
#define DEGREE_OFF        0
#define DEGREE_ON_R       0
#define DEGREE_OFF_R      20

Servo m1, m2, m3;
int data;

// 0: push, 1:release
int switch_1_on, switch_1_off;
int switch_2_on, switch_2_off;
int switch_3_on, switch_3_off;

boolean switch_1_state_on;
boolean switch_2_state_on;
boolean switch_3_state_on;

void setup() {

  switch_1_state_on = false;
  switch_2_state_on = false;
  switch_3_state_on = false;
  
  // put your setup code here, to run once:
  m1.attach(MOTOR_1_PIN);
  m2.attach(MOTOR_2_PIN);
  m3.attach(MOTOR_3_PIN);

  m1.write(DEGREE_OFF_R);
  m2.write(DEGREE_OFF_R);
  m3.write(DEGREE_OFF_R);

  pinMode(MOTOR_1_ON_PIN, INPUT_PULLUP);
  pinMode(MOTOR_1_OFF_PIN, INPUT_PULLUP);
  pinMode(MOTOR_2_ON_PIN, INPUT_PULLUP);
  pinMode(MOTOR_2_OFF_PIN, INPUT_PULLUP);
  pinMode(MOTOR_3_ON_PIN, INPUT_PULLUP);
  pinMode(MOTOR_3_OFF_PIN, INPUT_PULLUP);

  /* Serial */
  Serial.begin(9600);
  // Xbee Serial1 port baud rate should be set the same to the xbee baud rate
  Serial1.begin(9600);  

}

void loop() {
  // put your main code here, to run repeatedly:

  data = Serial1.read();

  /* SWITCH 1 */
  
  if (switch_1_state_on == true){

    switch_1_off = digitalRead(MOTOR_1_OFF_PIN);
    
    if (switch_1_off == 0){
      m1.write(DEGREE_OFF_R);
      Serial1.write(SWITCH_1_OFF); // switch 1 off
      Serial.println("SWITCH_1_OFF");
      delay(500);
      switch_1_state_on = false;
    }

    if (data == SWITCH_1_OFF) {
      m1.write(DEGREE_OFF_R);
      Serial.println("SWITCH_1_OFF");
      delay(500);
      switch_1_state_on = false;
    }

  } else { // switch_1_state_on == false

    switch_1_on = digitalRead(MOTOR_1_ON_PIN);

    if (switch_1_on == 0) {
      m1.write(DEGREE_ON_R);
      Serial1.write(SWITCH_1_ON); // switch 1 on
      Serial.println("SWITCH_1_ON");
      delay(500);
      switch_1_state_on = true;
    }

    if (data == SWITCH_1_ON) {
      m1.write(DEGREE_ON_R);
      Serial.println("SWITCH_1_ON");
      delay(500);
      switch_1_state_on = true;
    }

  }


  /* SWITCH 2 */
 
  if (switch_2_state_on == true){

    switch_2_off = digitalRead(MOTOR_2_OFF_PIN);
    
    if (switch_2_off == 0){
      m2.write(DEGREE_OFF_R);
      Serial1.write(SWITCH_2_OFF); // switch 2 off
      Serial.println("SWITCH_2_OFF");
      delay(500);
      switch_2_state_on = false;
    }
    
     if (data == SWITCH_2_OFF) {
      m2.write(DEGREE_OFF_R);
      Serial.println("SWITCH_2_OFF");
      delay(500);
      switch_2_state_on = false;
    }
    
  } else { // switch_1_state_on == false

    switch_2_on = digitalRead(MOTOR_2_ON_PIN);

    if (switch_2_on == 0) {
      m2.write(DEGREE_ON_R);
      Serial1.write(SWITCH_2_ON); // switch 2 on
      Serial.println("SWITCH_2_ON");
      delay(500);
      switch_2_state_on = true;
    }

    if (data == SWITCH_2_ON) {
      m2.write(DEGREE_ON_R);
      Serial.println("SWITCH_2_ON");
      delay(500);
      switch_2_state_on = true;
    }

  }


  /* SWITCH 3 */

  if (switch_3_state_on == true){

    switch_3_off = digitalRead(MOTOR_3_OFF_PIN);
    
    if (switch_3_off == 0){
      m3.write(DEGREE_OFF_R);
      Serial1.write(SWITCH_3_OFF); // switch 3 off
      Serial.println("SWITCH_3_OFF");
      delay(500);
      switch_3_state_on = false;
    }

    if (data == SWITCH_3_OFF) {
      m3.write(DEGREE_OFF_R);
      Serial.println("SWITCH_3_OFF");
      delay(500);
      switch_3_state_on = false;
    }

  } else { // switch_1_state_on == false

    switch_3_on = digitalRead(MOTOR_3_ON_PIN);

    if (switch_3_on == 0) {
      m3.write(DEGREE_ON_R);
      Serial1.write(SWITCH_3_ON); // switch 3 on
      Serial.println("SWITCH_3_ON");
      delay(500);
      switch_3_state_on = true;
    }

    if (data == SWITCH_3_ON) {
      m3.write(DEGREE_ON_R);
      Serial.println("SWITCH_3_ON");
      delay(500);
      switch_3_state_on = true;
    }

  }
  
}