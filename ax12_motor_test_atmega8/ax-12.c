#include "ax-12.h"

volatile unsigned char Parameter[128]={0xff,0xff};
unsigned char MoterID[20] ;
unsigned int Position[20];
volatile unsigned char data100=0, data10=0, data1=0;


void TxD(unsigned char MoterID ,unsigned char Length)
{
    volatile unsigned char Counter; //For Counter
    volatile unsigned char CheckSum=2; //Used CheckSum >> ~(ID + Length + Parameters)

    Parameter[2]=MoterID;
    Parameter[3]=Length;
    for(Counter=0; Counter < (Length+3); Counter++) 
    {
            USART_Transmit(Parameter[ Counter ]);
            CheckSum += Parameter[ Counter ];
    }
    USART_Transmit(~(CheckSum));
}

void MOTOR_Move(unsigned char MoterID ,unsigned int Position,unsigned int Speed)
{
    volatile unsigned char Counter; //For Counter
    volatile unsigned char CheckSum=2; //Used CheckSum >> ~(ID + Length + Parameters)
    CheckSum=2;
    Parameter[2]=MoterID;
    Parameter[3]=7;
    Parameter[4]=INST_WRITE;
    Parameter[5]=P_GOAL_POSITION_L ;
    Parameter[6]=Position & 0xff ;//Position_L
    Parameter[7]=Position >> 8 ;//Position_H
   // Parameter[8]=Speed& 0xff ;//Position_L
 //   Parameter[9]=Speed >> 8 ;//Position_H
  	Parameter[8]=Speed ;//Speed_L
 	Parameter[9]=Speed>> 8;//Speed_H
    for(Counter=0; Counter < (10); Counter++) 
    {
            USART_Transmit(Parameter[ Counter ]);
 	           CheckSum += Parameter[ Counter ];
    }
    USART_Transmit(~(CheckSum));
}

void Multi_Move0(unsigned char N)
{
    volatile unsigned char Counter; //For Counter
    volatile unsigned char CheckSum=2; //Used CheckSum >> ~(ID + Length + Parameters)
    volatile unsigned char i=0;
    CheckSum=2;
    Parameter[2]=0xfe;
    Parameter[3]=((4 + 1)*N + 4);// L>> datalength(move >>4) N >> nimber of moter
    Parameter[4]=INST_SYNC_WRITE;
    Parameter[5]=P_GOAL_POSITION_L ;
    Parameter[6]=4;//length
    for(i=0;i<N ;i++) {
        Parameter[i*5+7]=MoterID[i];
        Parameter[i*5+8]=Position[i] & 0xff ;//Position_L
        Parameter[i*5+9]=Position[i] >> 8 ;//Position_H
        Parameter[i*5+10]=0xf0 ;//Speed_L
        Parameter[i*5+11]=2;//Speed_H  6+(i*N)
    }
    for(Counter=0; Counter < 7+(5*N) ; Counter++) 
    {
            USART_Transmit(Parameter[ Counter ]);
            CheckSum += Parameter[ Counter ];
    }
    USART_Transmit(~(CheckSum));
}  
