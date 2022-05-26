/*******************************************************************************
 *				 _ _                                             _ _
				|   |                                           (_ _)
				|   |        _ _     _ _   _ _ _ _ _ _ _ _ _ _   _ _
				|   |       |   |   |   | |    _ _     _ _    | |   |
				|   |       |   |   |   | |   |   |   |   |   | |   |
				|   |       |   |   |   | |   |   |   |   |   | |   |
				|   |_ _ _  |   |_ _|   | |   |   |   |   |   | |   |
				|_ _ _ _ _| |_ _ _ _ _ _| |_ _|   |_ _|   |_ _| |_ _|
								(C)2022 Lumi
 * Copyright (c) 2022
 * Lumi, JSC.
 * All Rights Reserved
 *
 * File name: Example.h
 *
 * Description:
 *
 *
 * Last Changed By:  $Author: trungnt $
 * Revision:         $Revision: $
 * Last Changed:     $Date: $April 15, 2022
 *
 * Code sample:
 ******************************************************************************/
/******************************************************************************/
/*                              INCLUDE FILES                                 */
/******************************************************************************/


/******************************************************************************/
/*                     PRIVATE TYPES and DEFINITIONS                         */
/******************************************************************************/


/******************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                         */
/******************************************************************************/


/******************************************************************************/
/*                              PRIVATE DATA                                  */
/******************************************************************************/

/******************************************************************************/
/*                              EXPORTED DATA                                 */
/******************************************************************************/

/******************************************************************************/
/*                            PRIVATE FUNCTIONS                               */
/******************************************************************************/

/******************************************************************************/
/*                            EXPORTED FUNCTIONS                              */
/******************************************************************************/

/******************************************************************************/

bool_t boIsFound = TRUE;	//bo[Tên biến]
u8_t byRepeat;	//by[Tên biến]
i8_t ibRepeat;	//ib[Tên biến]
u16_t wValue;	//w[Tên biến]
i16_t iwValue;	//iw[Tên biến]
u32_t dwValue;	//dw[Tên biến]
i32_t iValue;	//
i32_t idwValue;	//idw[Tên biến] hoặc i[Tên biến]
u64_t lwValue;	//Ít dùng
i64_t ilValue;

Các loại biến
Extern/Global : g_[Kiểu][Tên biến]
	u8_t g_byRepeat;

Con trỏ : bắt đầu bằng chữ p[Kiểu][Tên biến]
u8_p pbyBuffer;
i8_t pibBuffer;
u16_t pwBuffer;
u32_t pdwBuffer;

Vấn đề dùng tab và space
Cách thay đổi tab to indentation(space)
C / C++
1. Click Window » Preferences
2. Expand C/C++ » Code Style
3. Click Formatter
4. Click the New button to create a new profile, then OK to continue
5. Click the Indentation tab
6. Under General Settings, set Tab policy to: Spaces only
7. Click OK ad nauseam to apply the changes.

void noiChuoi(char str1[], char str2[], char str3[]){
	int c1 = 0;
	int c2 = 0;
	while(str1[c1]){
		c1 ++;
	}
	while(str2[c2]){
		c2 ++;
	}
	for(int i = 0; i < c1; i ++){
		str3[i] = str1[i];
	}
	for(int i = 0; i < c2; i ++){
		str3[i + c1] = str2[i];
	}
}

void noiChuoi(char firstStr[], char secondStr[], char desStr[]){
	int firstStrLen = 0;
	int secondStrLen = 0;
	while(str1[firstStrLen]){
		firstStrLen ++;
	}
	while(str2[secondStrLen]){
		secondStrLen ++;
	}
	for(int i = 0; i < firstStrLen; i ++){
		desStr[i] = firstStr[i];
	}
	for(int i = 0; i < secondStrLen; i ++){
		desStr[i + firstStrLen] = secondStr[i];
	}
}

int a = 0;
switch( b ){
	case 0:
		a = 1;
		break;
	case 2:
		a = 7;
		break;
	case 0xFF:
		a = -1;
		break;
	default:
		a = -2;
		break;
}

int handleStep = DEVICE_BUSY;
switch(cmdid){
	case CMD_GET_STATUS:
		handleStep = SEND_RESPONSE_TO_HC;
		break;
	case CMD_SET_RELAY:
		handleStep = SEND_RESPONSE_RELAY_SATE_TO_HC;
		break;
	case CMD_DEVICE_IDLE:
		handleStep = SEND_GET_VALUE_TO_DEVICE;
		break;
	default:
		handleStep = DEVICE_BUSY;
		break;
}

//maintainable
uint16_t I2C_GetTemperatureSensor( void )
{
	uint16_t data;
	//Send Start bit
	while (I2C_GetFlagStatus(I2Cx_SENSOR, I2C_FLAG_BUSY));
	I2C_GenerateSTART(I2Cx_SENSOR, ENABLE);
	while (!I2C_CheckEvent(I2Cx_SENSOR, I2C_EVENT_MASTER_MODE_SELECT));
	
	// Send slave address
	I2C_Send7bitAddress(I2Cx_SENSOR, 0x40, direction);
	while (!I2C_CheckEvent(I2Cx_SENSOR, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	
	// Send data byte
	I2C_SendData(I2Cx_SENSOR, 0xE0);
	while (!I2C_CheckEvent(I2Cx_SENSOR, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
	// Generate I2C stop condition
	I2C_GenerateSTOP(I2Cx_SENSOR, ENABLE);
	
	//Send Start bit
	while (I2C_GetFlagStatus(I2Cx_SENSOR, I2C_FLAG_BUSY));
	I2C_GenerateSTART(I2Cx_SENSOR, ENABLE);
	while (!I2C_CheckEvent(I2Cx_SENSOR, I2C_EVENT_MASTER_MODE_SELECT));
	
	// Send slave address
	I2C_Send7bitAddress(I2Cx_SENSOR, 0x40, direction);
	while (!I2C_CheckEvent(I2Cx_SENSOR, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
	
	// Enable ACK of received data
	I2C_AcknowledgeConfig(I2Cx_SENSOR, ENABLE);
	while (!I2C_CheckEvent(I2Cx_SENSOR, I2C_EVENT_MASTER_BYTE_RECEIVED));
	data = I2C_ReceiveData(I2Cx_SENSOR);

	// Enable not ACK of received data
	I2C_AcknowledgeConfig(I2Cx_SENSOR, DISABLE);
	while (!I2C_CheckEvent(I2Cx_SENSOR, I2C_EVENT_MASTER_BYTE_RECEIVED));
	data = ( data << 8) + I2C_ReceiveData(I2Cx_SENSOR);
	
	// Generate I2C stop condition
	I2C_GenerateSTOP(I2Cx_SENSOR, ENABLE);
	return data;
}

uint16_t humiValue = I2C_GetData( 0x40, 0xE0);
uint16_t tempValue = I2C_GetData( 0x80, 0xE3);

uint16_t I2C_GetData(uint8_t address, uint8_t cmdId){
	i2cStart();
	i2cAddressDirection(address);
	i2cTransmit(cmdId);
	i2cStop();
	
	i2cStart();
	i2cAddressDirection(address);
	data = i2c_receive_nack();
	data = (data<<8) + i2c_receive_ack();
	i2cStop();
	return data;
}

uint16_t I2C_GetTemperatureSensor(void)
{
	i2cStart();
	i2cAddressDirection(0x40);
	i2cTransmit(0xE0);
	i2cStop();
	
	i2cStart();
	i2cAddressDirection(0x40);
	data = i2c_receive_nack();
	data = (data<<8) + i2c_receive_ack();
	i2cStop();
	return data;
}

uint16_t I2C_GetHumiditySensor(void)
{
	i2cStart();
	i2cAddressDirection(0x80);
	i2cTransmit(0xE3);
	i2cStop();
	
	i2cStart();
	i2cAddressDirection(0x80);
	data = i2c_receive_nack();
	data = (data<<8) + i2c_receive_ack();
	i2cStop();
	return data;
}


//Initializes random number generantor
srand((uint8_t) time(0));

uint8_t rollDice(){
	return rand()%6 + 1;
}

uint8_t rollDice(){
	return rand()%12 + 1;
}