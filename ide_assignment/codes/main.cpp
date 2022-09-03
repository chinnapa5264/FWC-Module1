#include<Arduino.h>
int A=0,B=0,C=0;
int X,Y;

//Code released under GNU GPL.  Free to use for anything.
void verify(int F)
{
  digitalWrite(13, F);
}
// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(13, OUTPUT); 
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, INPUT); 
}

// the loop function runs over and over again forever
void loop ()
{
C = digitalRead(4);//LSB
B = digitalRead(5);
A = digitalRead(6);;//MSB
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
//&& is the AND operation
// || is the OR operation
// ! is the NOT operation
