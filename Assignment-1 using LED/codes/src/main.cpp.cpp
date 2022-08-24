#include<Arduino.h>
int A=0,B=0,C=1;
int X,Y;

//Code released under GNU GPL.  Free to use for anything.
void verify(int F)
{
  digitalWrite(13, F);
}
// the setup function runs once when you press reset or power the board
void setup() {
    pinMode(13, OUTPUT);  
}

// the loop function runs over and over again forever
void loop ()
{
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