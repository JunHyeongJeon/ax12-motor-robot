#ifndef AX-12_H_
#define AX-12_H_

#include "usart.h"
#include <util/delay.h>

#define ON 1
#define OFF 0
//--- Control Table Address ---
//EEPROM AREA
#define P_MODEL_NUMBER_L             0
#define P_MODOEL_NUMBER_H            1
#define P_VERSION                    2
#define P_ID                         3
#define P_BAUD_RATE                  4
#define P_RETURN_DELAY_TIME          5
#define P_CW_ANGLE_LIMIT_L           6
#define P_CW_ANGLE_LIMIT_H           7
#define P_CCW_ANGLE_LIMIT_L          8
#define P_CCW_ANGLE_LIMIT_H          9
#define P_SYSTEM_DATA2               10
#define P_LIMIT_TEMPERATURE          11
#define P_DOWN_LIMIT_VOLTAGE         12
#define P_UP_LIMIT_VOLTAGE           13
#define P_MAX_TORQUE_L               14
#define P_MAX_TORQUE_H               15
#define P_RETURN_LEVEL               16
#define P_ALARM_LED                  17
#define P_ALARM_SHUTDOWN             18
#define P_OPERATING_MODE             19
#define P_DOWN_CALIBRATION_L         20
#define P_DOWN_CALIBRATION_H         21
#define P_UP_CALIBRATION_L           22
#define P_UP_CALIBRATION_H           23
#define P_TORQUE_ENABLE             (24)
#define P_LED                       (25)
#define P_CW_COMPLIANCE_MARGIN      (26)
#define P_CCW_COMPLIANCE_MARGIN     (27)
#define P_CW_COMPLIANCE_SLOPE       (28)
#define P_CCW_COMPLIANCE_SLOPE      (29)
#define P_GOAL_POSITION_L           (30)
#define P_GOAL_POSITION_H           (31)
#define P_GOAL_SPEED_L              (32)
#define P_GOAL_SPEED_H              (33)
#define P_TORQUE_LIMIT_L            (34)
#define P_TORQUE_LIMIT_H            (35)
#define P_PRESENT_POSITION_L        (36)
#define P_PRESENT_POSITION_H        (37)
#define P_PRESENT_SPEED_L           (38)
#define P_PRESENT_SPEED_H           (39)
#define P_PRESENT_LOAD_L            (40)
#define P_PRESENT_LOAD_H            (41)
#define P_PRESENT_VOLTAGE           (42)
#define P_PRESENT_TEMPERATURE       (43)
#define  P_REGISTERED_INSTRUCTION   (44)
#define  P_PAUSE_TIME		        (45)
#define  P_MOVING		            (46)
#define  P_LOCK		    	        (47) 
#define  P_PUNCH_L		            (48)
#define  P_PUNCH_H	            	(49)



//----instruction
#define  INST_PING		0X01
#define  INST_READ		0X02
#define  INST_WRITE		0X03
#define  INST_REG_WRITE		0X04
#define  INST_ACTION		0X05
#define  INST_RESET		0X06
#define  INST_DIGITAL_RESET	0X07
#define  INST_SYSTEM_READ	0X0C
#define  INST_SYSTEM_WRITE	0X0D
#define  INST_SYNC_WRITE	0X83
#define  INST_SYNC_REG_WRITE	0X84

void TxD(unsigned char MoterID ,unsigned char Length);
void MOTOR_Move(unsigned char MoterID ,unsigned int Position,unsigned int Speed);
void Multi_Move0(unsigned char N);
void MOTOR_Move_With_RxTx_Control(unsigned char MoterID ,unsigned int Position,unsigned int Speed);


#endif /* AX-12_H_ */
