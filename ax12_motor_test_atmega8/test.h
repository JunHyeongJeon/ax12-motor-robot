//Made by Min JeaKyung
//Codevision_AVR_V2.03.4
//ATmege 128
//UART1(RXD1, TXD1)

#ifndef TEST_H_
#define TEST_H_

#include "usart.h"

#define CON_PORT PORTD
#define SEND 0X02
#define GET 0X01

  int ang1, ang2;
#include <stdio.h>
//Control Table EEPROM Area
#define model_number_l 0x00
#define model_number_h 0x01
#define version_of_firmware 0x02
#define id 0x03
#define baud_rate 0x04
#define return_delay_time 0x05
#define cw_angle_limit_l 0x06 
#define cw_angle_limit_h 0x07  
#define ccw_angle_limit_l 0x08  
#define ccw_angle_limit_h 0x09  
#define reserved1 0x0a  
#define the_highest_limit_temperature 0x0b  
#define the_lowest_limit_voltage 0x0c
#define the_highest_limit_voltage 0x0d  
#define max_torque_l 0x0e  
#define max_torque_h 0x0f  
#define status_return_level 0x10  
#define alarm_led 0x11  
#define alarm_shutdown 0x12  
#define reserved2 0x13  
#define down_calibration_l 0x14  
#define down_calibration_h 0x15  
#define up_calibration_l 0x16 
#define up_calibration_h 0x17

//Control Table RAM Area   
#define torque_enable 0x18
#define led 0x19 
#define cw_compliance_margin 0x1a   
#define ccw_compliance_margin 0x1b 
#define cw_compliance_slope 0x1c  
#define ccw_compliance_slope 0x1d  
#define goal_position_l 0x1e  
#define goal_position_h 0x1f  
#define moving_speed_l 0x20
#define moving_speed_h 0x21  
#define torque_limit_l 0x22  
#define torque_limit_h 0x23     
#define present_position_l 0x24
#define present_position_h 0x25
#define present_speed_l 0x26
#define present_speed_h 0x27
#define present_load_l 0x28
#define present_lead_h 0x29
#define present_voltage 0x2a
#define present_temperature 0x2b
#define registered_instruction 0x2c
#define reserved3 0x2d
#define moving 0x2e
#define lock 0x2f
#define punch_l 0x30
#define punch_h 0x31

void dgree_to_hex(int dg)
{
  dg = (int)(dg * 3.41);
    
  ang1 = dg>>8;
  ang2 = dg & 0x0ff;
}


void put_data(unsigned char id_num, unsigned char data_type, unsigned char data)
{
	int i;
	char put[8];
	put[0] = 0xff;
	put[1] = 0xff;
	put[2] = id_num;   //id
	put[3] = 0x04;     //length
	put[4] = 0x03;     //write data
	put[5] = data_type;     //data_type
	put[6] = data;
	put[7] = 0x00;

	for( i = 2; i<7; i++)
	{
		put[7] += put[i];
	}
	put[7] = ~put[7];

	CON_PORT = SEND;

	for(i=0;i<8;i++)
	{
		USART_Transmit(put[i]);
	}
}

void get_data(unsigned char id_num, unsigned char data_type, unsigned char data, char *get)
{
	int i;
	char put[8];

	put[0] = 0xff;
	put[1] = 0xff;
	put[2] = id_num;   //id
	put[3] = 0x04;     //length
	put[4] = 0x02;     //read data
	put[5] = data_type;     //data_type
	put[6] = data;
	put[7] = 0x00;

	for( i = 2; i<7; i++)
	{
		put[7] += put[i];
	}
	put[7] = ~put[7];

	CON_PORT = SEND;

	for(i=0;i<8;i++)
	{
		USART_Transmit(put[i]);
	}

	CON_PORT = GET;

	for(i=0; i<8; i++)
	{
		*get = USART_Receive();
		get++;
	}

}

void act_dynamixel(char mot_id, int ang)
{
	int i;
	char act[11];
	dgree_to_hex(ang);
	act[0] = 0xff;
	act[1] = 0xff;
	act[2] = mot_id;
	act[3] = 0x07;
	act[4] = 0x03;
	act[5] = goal_position_l;
	act[6] = ang2;
	act[7] = ang1;
	act[8] = 0x00;
	act[9] = 0x02;
	act[10] = 0x00;

	for( i = 2; i<10; i++)
	{
		act[10] += act[i];
	}
	act[10] = ~act[10];


	for(i=0;i<11;i++)
	{
	 	USART_Transmit(act[i]);
	}
}

void reg_act(char mot_id, int ang)
{
	int i;
	char act[11];
	dgree_to_hex(ang);
	act[0] = 0xff;
	act[1] = 0xff;
	act[2] = mot_id;
	act[3] = 0x07;
	act[4] = 0x04;
	act[5] = goal_position_l;
	act[6] = ang2;
	act[7] = ang1;
	act[8] = 0x60;
	act[9] = 0x00;
	act[10] = 0x00;

	for( i = 2; i<10; i++)
	{
		act[10] += act[i];
	}
	act[10] = ~act[10];


	for(i=0;i<11;i++)
	{
		USART_Transmit(act[i]);
	}
}

void action()
{
	int i;
	char act[6];
	act[0] = 0xff;
	act[1] = 0xff;
	act[2] = 0xfe;
	act[3] = 0x02;
	act[4] = 0x05;
	act[5] = 0x00;

	for( i = 2; i<5; i++)
	{
		act[5] += act[i];
	}
	act[5] = ~act[5];

	for(i=0;i<6;i++)
	{
		USART_Transmit(act[i]);
	}
} 

void ang()
{
	int i;
	char act[9];

	act[0] = 0xff;
	act[1] = 0xff;
	act[2] = 0xfe;
	act[3] = 0x05;
	act[4] = 0x03;
	act[5] = cw_angle_limit_l;
	act[6] = 0x00;
	act[7] = 0x00;
	act[8] = 0x00;

	for( i = 2; i<8; i++)
	{
		act[8] += act[i];
	}
	act[8] = ~act[8];

	for(i=0;i<9;i++)
	{
		USART_Transmit(act[i]);
	}

	act[0] = 0xff;
	act[1] = 0xff;
	act[2] = 0xfe;
	act[3] = 0x05;
	act[4] = 0x03;
	act[5] = ccw_angle_limit_l;
	act[6] = 0xff;
	act[7] = 0x03;
	act[8] = 0x00;

	for( i = 2; i<8; i++)
	{
		act[8] += act[i];
	}
	act[8] = ~act[8];

}

#endif /* TEST_H_ */
