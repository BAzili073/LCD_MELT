#include "stm32l053xx.h"
#include "stm32l0xx_hal.h"
#include "LCD_func.h"
#include "defines.h"
#include "TIMs.h"

#define MTLCD_DB0_PORT GPIOA
#define MTLCD_DB0_PIN GPIO_PIN_15
#define MTLCD_DB1_PORT GPIOA
#define MTLCD_DB1_PIN GPIO_PIN_0
#define MTLCD_DB2_PORT GPIOB
#define MTLCD_DB2_PIN GPIO_PIN_0
#define MTLCD_DB3_PORT GPIOB
#define MTLCD_DB3_PIN GPIO_PIN_1
#define MTLCD_DB4_PORT GPIOB
#define MTLCD_DB4_PIN GPIO_PIN_2
#define MTLCD_DB5_PORT GPIOA
#define MTLCD_DB5_PIN GPIO_PIN_10
#define MTLCD_DB6_PORT GPIOA
#define MTLCD_DB6_PIN GPIO_PIN_9
#define MTLCD_DB7_PORT GPIOA
#define MTLCD_DB7_PIN GPIO_PIN_8
#define MTLCD_A0_PORT GPIOB
#define MTLCD_A0_PIN GPIO_PIN_5
#define MTLCD_RW_PORT GPIOB
#define MTLCD_RW_PIN GPIO_PIN_4
#define MTLCD_E_PORT GPIOB
#define MTLCD_E_PIN GPIO_PIN_3
#define MTLCD_E1_PORT GPIOB
#define MTLCD_E1_PIN GPIO_PIN_15
#define MTLCD_E2_PORT GPIOB
#define MTLCD_E2_PIN GPIO_PIN_14
#define MTLCD_RES_PORT GPIOB
#define MTLCD_RES_PIN GPIO_PIN_13



void MTLCD_set_DB_port(unsigned char cmd);
void MTLCD_accept_DB_port();
void MTLCD_set_DB_port(unsigned char cmd);

void MTLCD_accept_DB_port(){
	  GPIO_HIGH(MTLCD_E_PORT,MTLCD_E_PIN); //cmd_port |= (1<<E);//устанавливаем "1" на E
	  while_time(1);
	  GPIO_LOW(MTLCD_E_PORT,MTLCD_E_PIN);// cmd_port &= ~(1<<E);// сбрасываем Е
	  while_time(1);
}


void MTLCD_set_DB_port(unsigned char cmd){
(cmd&(1<<0)) ? (GPIO_HIGH(MTLCD_DB0_PORT,MTLCD_DB0_PIN)) : (GPIO_LOW(MTLCD_DB0_PORT,MTLCD_DB0_PIN));
(cmd&(1<<1)) ? (GPIO_HIGH(MTLCD_DB1_PORT,MTLCD_DB1_PIN)) : (GPIO_LOW(MTLCD_DB1_PORT,MTLCD_DB1_PIN));
(cmd&(1<<2)) ? (GPIO_HIGH(MTLCD_DB2_PORT,MTLCD_DB2_PIN)) : (GPIO_LOW(MTLCD_DB2_PORT,MTLCD_DB2_PIN));
(cmd&(1<<3)) ? (GPIO_HIGH(MTLCD_DB3_PORT,MTLCD_DB3_PIN)) : (GPIO_LOW(MTLCD_DB3_PORT,MTLCD_DB3_PIN));
(cmd&(1<<4)) ? (GPIO_HIGH(MTLCD_DB4_PORT,MTLCD_DB4_PIN)) : (GPIO_LOW(MTLCD_DB4_PORT,MTLCD_DB4_PIN));
(cmd&(1<<5)) ? (GPIO_HIGH(MTLCD_DB5_PORT,MTLCD_DB5_PIN)) : (GPIO_LOW(MTLCD_DB5_PORT,MTLCD_DB5_PIN));
(cmd&(1<<6)) ? (GPIO_HIGH(MTLCD_DB6_PORT,MTLCD_DB6_PIN)) : (GPIO_LOW(MTLCD_DB6_PORT,MTLCD_DB6_PIN));
(cmd&(1<<7)) ? (GPIO_HIGH(MTLCD_DB7_PORT,MTLCD_DB7_PIN)) : (GPIO_LOW(MTLCD_DB7_PORT,MTLCD_DB7_PIN));
}

void MTLCD_CMD(unsigned char cmd){
  while_time(1);
  MTLCD_set_DB_port(cmd);
  //MTLCD_DB_PORT -> ODR |= (cmd << 9);// data_port = cmd;//выводим команду на DB0-DB7
  while_time(1);
  MTLCD_accept_DB_port();
  }

void MTLCD_DATA(unsigned char data){
  while_time(1);
  MTLCD_set_DB_port(data); //  data_port = data;//данные на DB0-DB7
  while_time(1);
  GPIO_HIGH(MTLCD_A0_PORT,MTLCD_A0_PIN);// cmd_port |= (1<<DI);//устанавливаем "1" на DI - передаются данные
  while_time(1);
  MTLCD_accept_DB_port();
  GPIO_LOW(MTLCD_A0_PORT,MTLCD_A0_PIN);//cmd_port &= ~(1<<DI);// сбрасываем DI
  while_time(1);
 }


void MTLCD_Init(){
	GPIO_InitTypeDef initSrtuct;

				initSrtuct.Mode = GPIO_MODE_OUTPUT_PP;
				initSrtuct.Pin = MTLCD_A0_PIN | MTLCD_E1_PIN | MTLCD_E2_PIN | MTLCD_E_PIN | MTLCD_RES_PIN | MTLCD_RW_PIN;
				initSrtuct.Pull = GPIO_NOPULL;
				initSrtuct.Speed = GPIO_SPEED_HIGH;
				HAL_GPIO_Init(GPIOB, &initSrtuct);

				initSrtuct.Mode = GPIO_MODE_OUTPUT_PP;
				initSrtuct.Pin = MTLCD_DB0_PIN ;
				initSrtuct.Pull = GPIO_NOPULL;
				initSrtuct.Speed = GPIO_SPEED_HIGH;
				HAL_GPIO_Init(MTLCD_DB0_PORT, &initSrtuct);

				initSrtuct.Mode = GPIO_MODE_OUTPUT_PP;
				initSrtuct.Pin = MTLCD_DB1_PIN ;
				initSrtuct.Pull = GPIO_NOPULL;
				initSrtuct.Speed = GPIO_SPEED_HIGH;
				HAL_GPIO_Init(MTLCD_DB1_PORT, &initSrtuct);

				initSrtuct.Mode = GPIO_MODE_OUTPUT_PP;
				initSrtuct.Pin = MTLCD_DB2_PIN ;
				initSrtuct.Pull = GPIO_NOPULL;
				initSrtuct.Speed = GPIO_SPEED_HIGH;
				HAL_GPIO_Init(MTLCD_DB2_PORT, &initSrtuct);

				initSrtuct.Mode = GPIO_MODE_OUTPUT_PP;
				initSrtuct.Pin = MTLCD_DB3_PIN ;
				initSrtuct.Pull = GPIO_NOPULL;
				initSrtuct.Speed = GPIO_SPEED_HIGH;
				HAL_GPIO_Init(MTLCD_DB3_PORT, &initSrtuct);

				initSrtuct.Mode = GPIO_MODE_OUTPUT_PP;
				initSrtuct.Pin = MTLCD_DB4_PIN ;
				initSrtuct.Pull = GPIO_NOPULL;
				initSrtuct.Speed = GPIO_SPEED_HIGH;
				HAL_GPIO_Init(MTLCD_DB4_PORT, &initSrtuct);

				initSrtuct.Mode = GPIO_MODE_OUTPUT_PP;
				initSrtuct.Pin = MTLCD_DB5_PIN ;
				initSrtuct.Pull = GPIO_NOPULL;
				initSrtuct.Speed = GPIO_SPEED_HIGH;
				HAL_GPIO_Init(MTLCD_DB5_PORT, &initSrtuct);

				initSrtuct.Mode = GPIO_MODE_OUTPUT_PP;
				initSrtuct.Pin = MTLCD_DB6_PIN ;
				initSrtuct.Pull = GPIO_NOPULL;
				initSrtuct.Speed = GPIO_SPEED_HIGH;
				HAL_GPIO_Init(MTLCD_DB6_PORT, &initSrtuct);

				initSrtuct.Mode = GPIO_MODE_OUTPUT_PP;
				initSrtuct.Pin = MTLCD_DB7_PIN ;
				initSrtuct.Pull = GPIO_NOPULL;
				initSrtuct.Speed = GPIO_SPEED_HIGH;
				HAL_GPIO_Init(MTLCD_DB7_PORT, &initSrtuct);

  GPIO_LOW(GPIOA,0b11111111);
  GPIO_LOW(MTLCD_RW_PORT,MTLCD_RW_PIN);
  GPIO_LOW(MTLCD_A0_PORT,MTLCD_A0_PIN);

  GPIO_LOW(MTLCD_RES_PORT,MTLCD_RES_PIN);
  while_time(2);
  GPIO_HIGH(MTLCD_RES_PORT,MTLCD_RES_PIN);
  while_time(12);
//  cmd_port &=~((1<<CS2)|(1<<CS1));
//  cmd_port |= (1<<CS2);
//  lcd_cmd(0x3F);
//  cmd_port &=~((1<<CS2)|(1<<CS1));
//  cmd_port |= (1<<CS1);
//  lcd_cmd(0x3F);
}

void MTLCD_OnOff(char status){
	MTLCD_CMD(0xFF);
	 MTLCD_CMD((0x3E | status));
}

void MTLCD_set_x(unsigned char pos_x){
  MTLCD_set_DB_port(pos_x|0xB8);//Координата X
  while_time(1);
  MTLCD_accept_DB_port();
}

void MTLCD_set_y(unsigned char pos_y){
  MTLCD_set_DB_port(pos_y|0x40);//Координата Y
  while_time(1);
  MTLCD_accept_DB_port();
}


void MTLCD_CLR(){
	GPIO_HIGH(MTLCD_E1_PORT,MTLCD_E1_PIN);
	GPIO_HIGH(MTLCD_E2_PORT,MTLCD_E2_PIN);
  for(unsigned char i=0; i<8; i++){
	  MTLCD_CMD(0xB8+i);
   for(unsigned char j=0; j<64; j++){
	   MTLCD_CMD(0x40+j);
	   MTLCD_DATA(0x00);//записываем везде 0
    }
  }
	GPIO_LOW(MTLCD_E1_PORT,MTLCD_E1_PIN);
	GPIO_LOW(MTLCD_E2_PORT,MTLCD_E2_PIN);
}

//void MTLCD_READ_STATUS(){
//	GPIO_HIGH()
//	MTLCD_CMD()
//}
