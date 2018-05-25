#ifndef GYRO_H
#define	GYRO_H

#define XG_OFFS_TC 0x00
#define YG_OFFS_TC 0x01
#define ZG_OFFS_TC 0x02
#define X_FINE_GAIN 0x03
#define Y_FINE_GAIN 0x04
#define Z_FINE_GAIN 0x05
#define XA_OFFS_H 0x06 
#define XA_OFFS_L_TC 0x07
#define YA_OFFS_H 0x08 
#define YA_OFFS_L_TC 0x09
#define ZA_OFFS_H 0x0A 
#define ZA_OFFS_L_TC 0x0B
#define XG_OFFS_USRH 0x13
#define XG_OFFS_USRL 0x14
#define YG_OFFS_USRH 0x15
#define YG_OFFS_USRL 0x16
#define ZG_OFFS_USRH 0x17
#define ZG_OFFS_USRL 0x18
#define SMPLRT_DIV 0x19
#define CONFIG 0x1A
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1C
#define FF_THR 0x1D
#define FF_DUR 0x1E
#define MOT_THR 0x1F
#define MOT_DUR 0x20
#define ZRMOT_THR 0x21
#define ZRMOT_DUR 0x22
#define FIFO_EN 0x23
#define I2C_MST_CTRL 0x24
#define I2C_SLV0_ADDR 0x25
#define I2C_SLV0_REG 0x26
#define I2C_SLV0_CTRL 0x27
#define I2C_SLV1_ADDR 0x28
#define I2C_SLV1_REG 0x29
#define I2C_SLV1_CTRL 0x2A
#define I2C_SLV2_ADDR 0x2B
#define I2C_SLV2_REG 0x2C
#define I2C_SLV2_CTRL 0x2D
#define I2C_SLV3_ADDR 0x2E
#define I2C_SLV3_REG 0x2F
#define I2C_SLV3_CTRL 0x30
#define I2C_SLV4_ADDR 0x31
#define I2C_SLV4_REG 0x32
#define I2C_SLV4_DO 0x33
#define I2C_SLV4_CTRL 0x34
#define I2C_SLV4_DI 0x35
#define I2C_MST_STATUS 0x36
#define INT_PIN_CFG 0x37
#define INT_ENABLE 0x38
#define DMP_INT_STATUS 0x39
#define INT_STATUS 0x3A
#define ACCEL_XOUT_H 0x3B
#define ACCEL_XOUT_L 0x3C
#define ACCEL_YOUT_H 0x3D
#define ACCEL_YOUT_L 0x3E
#define ACCEL_ZOUT_H 0x3F
#define ACCEL_ZOUT_L 0x40
#define TEMP_OUT_H 0x41
#define TEMP_OUT_L 0x42
#define GYRO_XOUT_H 0x43
#define GYRO_XOUT_L 0x44
#define GYRO_YOUT_H 0x45
#define GYRO_YOUT_L 0x46
#define GYRO_ZOUT_H 0x47
#define GYRO_ZOUT_L 0x48
#define EXT_SENS_DATA_00 0x49
#define EXT_SENS_DATA_01 0x4A
#define EXT_SENS_DATA_02 0x4B
#define EXT_SENS_DATA_03 0x4C
#define EXT_SENS_DATA_04 0x4D
#define EXT_SENS_DATA_05 0x4E
#define EXT_SENS_DATA_06 0x4F
#define EXT_SENS_DATA_07 0x50
#define EXT_SENS_DATA_08 0x51
#define EXT_SENS_DATA_09 0x52
#define EXT_SENS_DATA_10 0x53
#define EXT_SENS_DATA_11 0x54
#define EXT_SENS_DATA_12 0x55
#define EXT_SENS_DATA_13 0x56
#define EXT_SENS_DATA_14 0x57
#define EXT_SENS_DATA_15 0x58
#define EXT_SENS_DATA_16 0x59
#define EXT_SENS_DATA_17 0x5A
#define EXT_SENS_DATA_18 0x5B
#define EXT_SENS_DATA_19 0x5C
#define EXT_SENS_DATA_20 0x5D
#define EXT_SENS_DATA_21 0x5E
#define EXT_SENS_DATA_22 0x5F
#define EXT_SENS_DATA_23 0x60
#define MOT_DETECT_STATUS 0x61
#define I2C_SLV0_DO 0x63
#define I2C_SLV1_DO 0x64
#define I2C_SLV2_DO 0x65
#define I2C_SLV3_DO 0x66
#define I2C_MST_DELAY_CTRL 0x67
#define SIGNAL_PATH_RESET 0x68
#define MOT_DETECT_CTRL 0x69
#define USER_CTRL 0x6A
#define PWR_MGMT_1 0x6B
#define PWR_MGMT_2 0x6C
#define BANK_SEL 0x6D
#define MEM_START_ADDR 0x6E
#define MEM_R_W 0x6F
#define DMP_CFG_1 0x70
#define DMP_CFG_2 0x71
#define FIFO_COUNTH 0x72
#define FIFO_COUNTL 0x73
#define FIFO_R_W 0x74
#define WHO_AM_I 0x75

void I2C_Ready()
{
    while(!SSPIF);                  /* Wait for operation complete */
    SSPIF=0;                        /*clear SSPIF interrupt flag*/
}

char I2C_Stop()
{
    PEN = 1;                        /* Initiate STOP condition */
    while(PEN);                     /* Wait for end of STOP condition */
    SSPIF = 0;
    if(!SSPSTATbits.P);             /* Return 0 if STOP failed */
    return 0;
}

char I2C_Write(unsigned char data)
{
      SSPBUF = data;                /* Write data to SSPBUF */
      I2C_Ready();
      if (ACKSTAT)                  /* Return 2 if acknowledgment received else 1 */
        return 1;
      else
        return 2;
}

char I2C_Start(char slave_write_address)
{   
    SSPCON2bits.SEN = 1;            /* Send START condition */
    while(SSPCON2bits.SEN);         /* Wait for completion of START */
    SSPIF=0;
    if(!SSPSTATbits.S)              /* Return 0 if START is failed */
    return 0;
    return (I2C_Write(slave_write_address)); /* Write slave device address with write to communicate */
}

void I2C_Start_Wait(char slave_write_address)
{
  while(1)
  {   
    SSPCON2bits.SEN = 1;            /* Send START condition */
    while(SSPCON2bits.SEN);         /* Wait for completion of START */
    SSPIF = 0;
    if(!SSPSTATbits.S)              /* Continue if START is failed */
        continue;
    I2C_Write(slave_write_address); /* Write slave device address with write to communicate */
    if(ACKSTAT)                     /* Check whether Acknowledgment received or not */
    {
        I2C_Stop();                 /* If not then initiate STOP and continue */
        continue;
    }    
    break;                          /* If yes then break loop */
  }
}

char I2C_Repeated_Start(char slave_read_address)
{
    RSEN = 1;                       /* Send REPEATED START condition */
    while(SSPCON2bits.RSEN);        /* Wait for completion of REPEATED START condition */
    SSPIF = 0;
    if(!SSPSTATbits.S)              /* Return 0 if REPEATED START is failed */
    return 0;
    I2C_Write(slave_read_address);  /* Write slave device address with read to communicate */
    if (ACKSTAT)                    /* Return 2 if acknowledgment received else 1 */
     return 1;
    else
     return 2;
}

void I2C_Ack()
{
    ACKDT = 0;  					/* Acknowledge data 1:NACK,0:ACK */
	ACKEN = 1;        				/* Enable ACK to send */
    while(ACKEN);
}

void I2C_Nack()
{
    ACKDT = 1;          			/* Not Acknowledge data 1:NACK,0:ACK */
	ACKEN = 1;              		/* Enable ACK to send */	          
    while(ACKEN);
}
char I2C_Read(char flag)            /* Read data from slave devices with 0=Ack & 1=Nack */
{
    char buffer;
    RCEN = 1;                       /* Enable receive */
    while(!SSPSTATbits.BF);         /* Wait for buffer full flag which set after complete byte receive */
    buffer = SSPBUF;                /* Copy SSPBUF to buffer */
    if(flag==0)
        I2C_Ack();                  /* Send acknowledgment */
    else
        I2C_Nack();                 /* Send negative acknowledgment */
    I2C_Ready();
    return(buffer);
}


void MPU6050_Init()										/* Gyro initialization function */
{
	__delay_ms(150);		/* Power up time >100ms */
	I2C_Start_Wait(0xD0);	/* Start with device write address */
	I2C_Write(SMPLRT_DIV);	/* Write to sample rate register */
	I2C_Write(0x07);	/* 1KHz sample rate */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(PWR_MGMT_1);	/* Write to power management register */
	I2C_Write(0x01);	/* X axis gyroscope reference frequency */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(CONFIG);	/* Write to Configuration register */
	I2C_Write(0x00);	/* Fs = 8KHz */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(GYRO_CONFIG);	/* Write to Gyro configuration register */
	I2C_Write(0x18);	/* Full scale range +/- 2000 degree/C */
	I2C_Stop();

	I2C_Start_Wait(0xD0);
	I2C_Write(INT_ENABLE);	/* Write to interrupt enable register */
	I2C_Write(0x01);
	I2C_Stop();

}

void MPU_Start_Loc()

{
	I2C_Start_Wait(0xD0);								/* I2C start with device write address */
	I2C_Write(ACCEL_XOUT_H);							/* Write start location address from where to read */ 
	I2C_Repeated_Start(0xD1);							/* I2C start with device read address */
}


#endif	/* GYRO_H */

