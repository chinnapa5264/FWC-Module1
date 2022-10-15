#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include<Arduino.h>
//    Can be client or even host   //
#ifndef STASSID
#define STASSID "chinna"  // Replace with your network credentials
#define STAPSK  "9390467299"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;


void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}
int A=0,B=0,C=0;
int X,Y;

//Code released under GNU GPL.  Free to use for anything.
void verify(int F)
{
  digitalWrite(13, F);
}
// the setup function runs once when you press reset or power the board
void setup() {
	OTAsetup();
    pinMode(18, OUTPUT); 
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT); 
}

// the loop function runs over and over again forever
void loop ()
{
	OTAloop();
C = digitalRead(4);//LSB
B = digitalRead(3);
A = digitalRead(2);;//MSB
X= A || C;
Y= A || (!A && C) || (B && C);
if(X=Y) 
{
verify(1);
}
else
{
verify(0); 
}
}
