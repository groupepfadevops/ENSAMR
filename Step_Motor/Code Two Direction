#include "DSP28x_Project.h"

#define PHA_on		GpioDataRegs.GPASET.bit.GPIO8 = 1
#define PHA_off		GpioDataRegs.GPACLEAR.bit.GPIO8 = 1
#define PHB_on		GpioDataRegs.GPASET.bit.GPIO10 = 1
#define PHB_off		GpioDataRegs.GPACLEAR.bit.GPIO10 = 1
#define PHC_on		GpioDataRegs.GPASET.bit.GPIO13 = 1
#define PHC_off		GpioDataRegs.GPACLEAR.bit.GPIO13 = 1
#define PHD_on		GpioDataRegs.GPASET.bit.GPIO14 = 1
#define PHD_off		GpioDataRegs.GPACLEAR.bit.GPIO14 = 1

#define time	2000
#define Num_pas 500

int step = 0;

//GPIO configuration
void Gpio_Config()
{
	EALLOW; 								// Nécessaire pour écrire dans les registres protégés EALLOW
	GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO8 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO8 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO10 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO10 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO13 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO13 = 0;
	GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO14 = 1;
	GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;
	EDIS; 									// Ceci est nécessaire pour désactiver l'écriture dans les registres protégés EALLOW
}

void step_direction(int direction)
{
	if (direction == 0)
	{
		switch(step)
		{
			case 0:
				PHA_on;
				PHB_off;
				PHC_off;
				PHD_off;
				break;
			case 1:
				PHA_off;
				PHB_on;
				PHC_off;
				PHD_off;
				break;
			case 2:
				PHA_off;
				PHB_off;
				PHC_on;
				PHD_off;
				break;
			case 3:
				PHA_off;
				PHB_off;
				PHC_off;
				PHD_on;
				break;
		}
	}else
	{
		switch(step)
		{
			case 0:
				PHA_off;
				PHB_off;
				PHC_off;
				PHD_on;
				break;
			case 1:
				PHA_off;
				PHB_off;
				PHC_on;
				PHD_off;
				break;
			case 2:
				PHA_off;
				PHB_on;
				PHC_off;
				PHD_off;
				break;
			case 3:
				PHA_on;
				PHB_off;
				PHC_off;
				PHD_off;
				break;
		}
	}
	step++;				// number of the position step
	if(step>3)
	{
		step = 0;
	}
}


void main(void)
{
	InitSysCtrl();
	InitFlash();

	Gpio_Config();

	// Disable CPU interrupts and clear all CPU interrupt flags:
	IER = 0x0000;
	IFR = 0x0000;
	int p,n;
	while(1)
	{
		for(p = 0; p < Num_pas; p++){ 		// 1000 steps in the positive direction
			step_direction(0);
			DELAY_US(time);				// time between each step
		}
		for(n = 0; n < Num_pas; n++){      // 1000 steps in the negative direction
			step_direction(1);
			DELAY_US(time);				// time between each step
		}
	}
}
