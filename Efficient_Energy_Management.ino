#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);                 //Initializing LCD Display

#define echo_usensor1 A0                        //Echo pin of Usensor1
#define trigger_usensor1 A1                     //Trigger pin of Usensor1
#define echo_usensor2 A2
#define trigger_usensor2 A3

int relay1=8;                                   //initailize value of relay1
int relay2=13;                                  //initialize value of relay2

long distance1=0,distance2=0;                   //initialising distance from usensors
int flag1=0,flag2=0,person=0;                   //intialising person count and flags

void usensor_read(int pin1,int pin2,long &sensor_time){
  long time;
  pinMode(pin1, OUTPUT);                        //pin1=Trigger Pin
  digitalWrite(pin1, LOW);                      
  delayMicroseconds(2);
  digitalWrite(pin1, HIGH);
  delayMicroseconds(10);                        //8 sonic bursts
  digitalWrite(pin1, LOW);
  pinMode(pin2, INPUT);
  time = pulseIn(pin2, HIGH);                   //Time between pulses
  sensor_time=time/29/2;                        //calculating distance from microseconds to cm
}
void setup() {                                  //One time setup in starting the circuit
  Serial.begin(9600);                           // initialize serial communication at 9600 bits per second:
  pinMode(relay1,OUTPUT);                       //Starting relay pins
  pinMode(relay2,OUTPUT);

  lcd.begin(16,2);                              //starting lcd
  lcd.setCursor(0,0);                           //setting cursor at start of lcd
  lcd.print("    IIIT-NR    ");
  delay(1000);                                  //delay of 1 second
  lcd.clear();
}

void loop() {                                   //infinite loop
  usensor_read(trigger_usensor1,echo_usensor1,distance1);delay(30);    //Reading Sensor Values
  usensor_read(trigger_usensor2,echo_usensor2,distance2);delay(30);

  Serial.print("da:");Serial.println(distance1);
  Serial.print("db:");Serial.println(distance2);
  //Checking if Person is entering or exiting
  if (distance1<90 && flag1==0){
    flag1=1;if (flag2==0) person+=1;
  }
  if (distance2<90 && flag2==0){
    flag2=1;if (flag1==0 && person>0) person-=1;
  }
  if (distance1>90 && distance2>90 && flag1==1 && flag2==1){
    flag1=0;flag2=0;
    delay(1000);
  }
  //LCD Displays
  lcd.setCursor(0,0);
  lcd.print("Have persons:");
  lcd.print( person);
  lcd.setCursor(0,1);
  lcd.print("Lights mode:");
  //Logic for LED control
  if(person>10){digitalWrite(relay1,HIGH);digitalWrite(relay2,HIGH);lcd.print("High");}
  else if (person>0){digitalWrite(relay1,HIGH);digitalWrite(relay2,LOW);lcd.print("Mid ");}
  else {digitalWrite(relay1,LOW);digitalWrite(relay2,LOW);lcd.print("Off ");}
}
