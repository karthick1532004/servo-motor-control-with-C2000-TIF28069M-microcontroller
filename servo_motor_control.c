#include "DSP28x_Project.h"

void pwm_gpio_setup_servo(void);
void pwm_setup_servo(void);
Uint16 maxcmp = 50985;// for 180 degree
Uint16 mincmp = 53817;// for 0 degree
Uint16 cmp = 0;
delay_ms_pwm(Uint16 ms)
{
    double j;
       for (j = 0; j < ms; j++)
       {

       }
}

void main(){
    InitSysCtrl();
    DINT;
    InitPieCtrl();
    IER = 0x0000;
    IFR = 0x0000;
    InitPieVectTable();
    EALLOW;  // This is needed to write to EALLOW protected register
    pwm_gpio_setup_servo();
    pwm_setup_servo();

    //for(cmp = maxcmp; cmp <= mincmp;cmp++){
      //  EPwm1Regs.CMPA.half.CMPA = cmp;
        //delay_ms_pwm(20000);





}

void pwm_gpio_setup_servo(){

    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;

}

void pwm_setup_servo(){
    //intialization of pwm
                EPwm1Regs.TBPRD = 56650; // Period = 601 TBCLK counts
                EPwm1Regs.CMPA.half.CMPA = 52400; // Compare A = 350 TBCLK counts
                EPwm1Regs.CMPB = 0; // Compare B = 200 TBCLK counts
                //EPwm1Regs. = 0; // Set Phase register to zero
                EPwm1Regs.TBCTR = 0;
                EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;
                EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;
                EPwm1Regs.TBCTL.bit.PRDLD = TB_SHADOW;
                EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE;
                EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1; // TBCLK = SYSCLK
                EPwm1Regs.TBCTL.bit.CLKDIV = 100;
                EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
                EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
                EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; // load on CTR = Zero
                EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO; // load on CTR = Zero
                EPwm1Regs.AQCTLA.bit.CAU = AQ_SET;
                EPwm1Regs.AQCTLA.bit.CAD = AQ_CLEAR;
                //EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;
                //EPwm1Regs.AQCTLA.bit.CAU = AQ_CLEAR;
                EPwm1Regs.AQCTLB.bit.ZRO = AQ_SET;
                EPwm1Regs.AQCTLB.bit.CBU = AQ_CLEAR;
}
