#include<ESP8266WiFi.h>
#include "ThingSpeak.h"
const int REDLED=12;
const int GREENLED=14;
int flag=0;
const int BLUELED=13;
const char ssid[]="iBall-Baton";
const char password[]="mintysameer1973";
const unsigned long channel_id=1098676;
const char read_api_key[]="J8VS2P3WUVOKYIBD";
WiFiClient client;

void setup() {
  // put your setup code here, to run once:
  pinMode(REDLED,OUTPUT);
  digitalWrite(REDLED,LOW);
   pinMode(BLUELED,OUTPUT);
  digitalWrite(BLUELED,LOW);
   pinMode(GREENLED,OUTPUT);
  digitalWrite(GREENLED,LOW);
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  delay(500);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected to Wifi");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
  randomSeed(micros());
  
}
int red_prev;
int blue_prev;
int green_prev;

void loop() {
  // put your main code here, to run repeatedly:
int red_led=ThingSpeak.readIntField(channel_id,1,read_api_key);
int blue_led=ThingSpeak.readIntField(channel_id,2,read_api_key);
int green_led=ThingSpeak.readIntField(channel_id,3,read_api_key);
int lighting=ThingSpeak.readIntField(channel_id,4,read_api_key);


//lighting up red led
if(red_led==10){
  digitalWrite(REDLED,HIGH);
  red_prev=red_led;
  Serial.println("Red LED is turned on");
}
if(red_led==5){
  digitalWrite(REDLED,LOW);
  red_prev=red_led;
  Serial.println("Red LED is turned off");
}
if(red_led==-1){
  red_prev=red_led;
Serial.println("Null");
return;
}
delay(500);

//lighting up blue led
if(blue_led==10){
  digitalWrite(BLUELED,HIGH);
  blue_prev=blue_prev;
  Serial.println("Blue LED is turned on");
}
if(blue_led==5){
  digitalWrite(BLUELED,LOW);
  blue_prev=blue_prev;
  Serial.println("Blue LED is turned off");
}
if(blue_prev==-1){
  blue_prev=blue_prev;
Serial.println("Null");
return;
}
delay(500);

//lighting up green led

if(green_led==10){
  digitalWrite(GREENLED,HIGH);
  green_prev=green_led;
  Serial.println("Green LED is turned on");
}
if(green_led==5){
  digitalWrite(GREENLED,LOW);
  green_prev=green_led;
  Serial.println("Green LED is turned off");
}
if(green_led==-1){
  green_prev=green_led;
Serial.println("Null");
return;
}
delay(500);

if(lighting==10){
  red_led=0;
  green_led=0;
  blue_led=0;
  for(int i=12;i<=14;i++){
    digitalWrite(i,HIGH);
    delay(500);
  }
  delay(500);
  for(int j=14;j>=12;j--){
    digitalWrite(j,LOW);
    delay(500);
  }
  Serial.println("Lights ON");
   red_led=red_prev;
  blue_led=blue_prev;
  green_led=green_prev;
}
if(lighting==5){
  red_led=red_prev;
  blue_led=blue_prev;
  green_led=green_prev;
  Serial.println("Lights OFF");
  
}
if(lighting==-1){
  Serial.println("Lights null");
  return;
}



}
