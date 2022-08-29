//Takes a number as input and prints the next number as output

#include <avr/io.h>

#include <util/delay.h>

#include <stdbool.h>
int main (void)
{

 bool A=0,B=0,C=0,X=0,Y=0;
 DDRD = 0b111100011;
 PORTD=0b000011100;   // activating pull ups

 DDRB = 0b00100000;  //13 th pin as out
 

while(1)
{
 C = (PIND & (1 << PIND7)) == (1 << PIND7);
 B = (PINB & (1 << PINB0)) == (1 << PINB0);
 A = (PINB & (1 << PINB1)) == (1 << PINB1);

X= A | C;
Y= A | ((!A) & C) | (B & C); 

if(X==Y)
{
 PORTB |= (1 << 5);
}
else
{
PORTB|=(0 <<5);
}
}
return 0;

}