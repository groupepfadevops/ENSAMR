#include "DSP28x_Project.h"

#define LED1_ON		GpioDataRegs.GPASET.bit.GPIO3 = 0
#define LED1_OFF	GpioDataRegs.GPACLEAR.bit.GPIO3 = 0
#define time	1000000
//GPIO configuration
void Gpio_Config()
{
	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO3 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO3 = 0;
	EDIS;
}

void main(void)
{
	InitSysCtrl();
	InitFlash();
	Gpio_Config();

	// Disable CPU interrupts and clear all CPU interrupt flags:
	IER = 0x0000;
	IFR = 0x0000;

	while(1)
	{
		LED1_OFF;
		DELAY_US(time);
		LED1_ON;
		DELAY_US(time);

	}
}
