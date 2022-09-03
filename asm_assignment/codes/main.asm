.include "/home/chinnapareddy/m328Pdef.inc"

ldi r30, 0b00100000 ;identifying output pin 13
out DDRB,r30
ldi r16, 0b11100011  ;identifying input pins 2,3,4
out DDRD,r16          ;declaring pins as input
ldi r16,0b11111011   ;giving input
out PortD,r16
ldi r17,0b00000001
ldi r18,0b00000001
ldi r19,0b00000001

AND r17,r16          ;r17=A
LSR  r16
AND r18,r16           ;r18=B
LSR r16
AND r19,r16           ;r19=C

ldi r21,0b00000001 
eor r21,r17           ;r21=A'

ldi r22,0b00000001
eor r22,r18           ;r22=B'

ldi r23,0b00000001
eor r23,r19           ;r23=C'

mov r5,r17            ;r5=A
OR r5,r19            ;r5=A+C   (X)      


mov r0,r21            ;r0=A'
AND r0,r19            ;r0=A'C 
mov r1,r19            ;r1=C
AND r1,r18            ;r1=BC
mov r6,r17            ;r5=A
OR r6,r0            ;r5=A+A'C           
OR r6,r1              ;r5=A+A'C+BC (Y)

 cp r5,r6
breq lbl

lbl:
ldi r29,0b00000001


mov r30,r29            ;r30=0000000Y
LSL r30               ;r30=000000Y0
LSL r30               ;r30=00000Y00
LSL r30               ;r30=0000Y000
LSL r30               ;r30=000Y0000
LSL r30               ;r30=00Y00000
out PortB,r30







Start:
rjmp Start