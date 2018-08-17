#include "Globle.h"

u8 LD_Current_Set1=0,LD_Current1=0,LD_Current_Set2=0,LD_Current2=0;
u8 LD_MOS_V1=0,LD_MOS_V2=0,EX_AD_ISet=0;
u16 SL_Frequence=0,SL_Duty=0;					 
u16 Reg_Error=0,Reg_Status=0;
u16 FPGA_ADC_Data[8][26]={0};
u8 Work_Cmd=0;//出光命令
u16 OPP_Power=0;//光功率
u8 Field_Cmd=0;
u8 Error_Cmd=0;
u16 Error_Code=0;
u8 Status_Code=0;
u8 Fault_Tab[15]={0};
u8 Status_Tab[8]={0};
u16 CCS1_MAXADC_VALUE=0x8AB2,CCS2_MAXADC_VALUE=0x9AB2,OPP_MAXADC_VALUE=0x8400;
u16 ERR_CHECK_VALUE=0x02Bf;
u16 ANG_KAD_VALUE=922;
u8 Fault_Type=0,Fault_Cmd=0;
u16 FPGA_ADC_TAB[5]={0};
u8 FPGA_RedLaser_Cmd=0;
u16 LD_Frequence=0;
u8 LD_Duty=0;

void LD_Current_Set(u16 Num , u8 Current)//电流十倍关系
{
		u16 DAC_Value,Temp;	
	
	  DAC_WR_Done=0;	
	
		Temp=(u16)Current*288/10;
		if(Temp>4095) Temp=4095;
		DAC_Value=(Num<<12)+Temp;

	  Sample_Mode_Set(SamPassive);
		Delay_1ms(1);
	  FSMC_WRITE(ADDR_CCS_DACSET,DAC_Value);
		Delay_1ms(1);	
		Sample_Mode_Set(SamActStable);		
}

void LD_Offset_Set(u16 Num , u8 Current)//电流十倍关系
{
		u16 DAC_Value,Temp;
	
		Temp=(u16)Current*6930/10;
		if(Temp>4095) Temp=4095;
		DAC_Value=( Num<<12 )+Temp;
	
	  Sample_Mode_Set(SamPassive);
		Delay_1ms(1);
	  FSMC_WRITE(ADDR_CCS_DACOFFSET,DAC_Value);
		Delay_1ms(1);	
		Sample_Mode_Set(SamActStable);	
}

void LD_PWM_Set(u16 Frequence,u8 Duty)//MOD_SEL SW READY
{			  
	u32 Temp=0,Period_Value=0,Duty_Value=0;
	
	if(Frequence<31) Frequence=31;
	Temp=64000000/Frequence;
	Period_Value=Temp&0xffff;
	Duty_Value=(Duty&0x7f)+(((Temp>>16)&0x1f)*128);
	FSMC_WRITE(ADDR_PERIODL,Period_Value);		//设定周期
	FSMC_WRITE(ADDR_PERIODH_DUTY,Duty_Value);
}


void Read_FPGA_ADC_Data()
{
	u8 i,j;
	for(i=0;i<8;i++)
	{
			for(j=0;j<25;j++)
			{
				FPGA_ADC_Data[i][j]=(FSMC_READ(((ADDR_IDATA_START)+j+(i*25))))&0X0FFF;
			}
	}
}

void LD_Parameter_Check()
{
	u8 i,j,k;	
	u16 temp1[30],temp2[30],temp3[30],temp;
  
	
	for(k=0;k<23;k++) { temp1[k]=FPGA_ADC_Data[0][k]; temp2[k]=FPGA_ADC_Data[1][k];temp3[k]=FPGA_ADC_Data[6][k];}
	for(i=1;i<23;i++)
	for(j=0;j<(23-i);j++)	 
	{ 
	  exch(&temp1[j],&temp1[j+1]); 
	  exch(&temp2[j],&temp2[j+1]); 
	  exch(&temp3[j],&temp3[j+1]); 
	}
	for(i=0;i<5;i++) FPGA_ADC_TAB[i]=0;
	for(k=0;k<10;k++){ FPGA_ADC_TAB[0]+=temp1[k+7]; FPGA_ADC_TAB[1]+=temp2[k+7]; FPGA_ADC_TAB[2]+=temp3[k+7];  }
	FPGA_ADC_TAB[0]/=10;//12.5A对应2780
	FPGA_ADC_TAB[1]/=10;
	FPGA_ADC_TAB[2]/=10;
	FPGA_ADC_TAB[3]=(FPGA_ADC_Data[0][23]+FPGA_ADC_Data[0][24])/2;
  FPGA_ADC_TAB[4]=(FPGA_ADC_Data[1][23]+FPGA_ADC_Data[1][24])/2;
	
	
	LD_Current1=FPGA_ADC_TAB[0]*10/218;
	LD_Current2=FPGA_ADC_TAB[1]*10/218;
	OPP_Power=FPGA_ADC_TAB[2];
	LD_MOS_V1=FPGA_ADC_TAB[3]*38/1000;
	LD_MOS_V2=FPGA_ADC_TAB[4]*39/1000;
	
	temp=FSMC_READ(ADDR_ANG_DACSET);
  EX_AD_ISet=temp*144/4095;
		
	Read_FPGA_ADC_Data();
}

void LD_Threshold_Set()
{
	u16 temp;
	Sample_Mode_Set(SamPassive);
	FSMC_WRITE(ADDR_IDLE_ADC,0x00ff);// CCS_IDLE最大1A
	FSMC_WRITE(ADDR_CCS_MAXADC,CCS1_MAXADC_VALUE);// CCS1最大值12.5A
	FSMC_WRITE(ADDR_CCS_MAXADC,CCS2_MAXADC_VALUE);// CCS2最大值12.5A	
	FSMC_WRITE(ADDR_OPP_MAXADC,OPP_MAXADC_VALUE);// OPP最大值12.5A	
	
	temp=FSMC_READ(ADDR_CCS_MAXADC);
	
	Sample_Mode_Set(SamActStable);	
}


void Work_Control(u8 cmd)
{
	if(cmd==1)//工作
	{	
		LD_Ready_Set(1);
		TDK_Power_Set(1);
		Delay_1ms(10);
		LD_Offset_Set(1,20);
		LD_Offset_Set(2,20);		                                      
	}
	else if(cmd==0)//停止
	{		
		LD_Ready_Set(0);
		LD_Offset_Set(1,0);
		LD_Offset_Set(2,0);	
		//TDK_Power_Set(0);
	}
}

void Fault_Check_Set(u8 Fault,u8 Cmd)
{
	u16 temp;
	switch (Fault)
	{
		case 0:{ if(Cmd==1) ERR_CHECK_VALUE|=0x4000;else ERR_CHECK_VALUE&=~0x4000; break; }//QBHLOCK
		case 1:{ if(Cmd==1) ERR_CHECK_VALUE|=0x1000;else ERR_CHECK_VALUE&=~0x1000; break; }//INTERLOCK
		case 2:{ if(Cmd==1) ERR_CHECK_VALUE|=0x0800;else ERR_CHECK_VALUE&=~0x0800; break; }//OPPLIM
		case 3:{ if(Cmd==1) ERR_CHECK_VALUE|=0x0200;else ERR_CHECK_VALUE&=~0x0200; break; }//CCSLIM
		case 4:{ if(Cmd==1) ERR_CHECK_VALUE|=0x0100;else ERR_CHECK_VALUE&=~0x0100; break; }//WMT
		case 5:{ if(Cmd==1) ERR_CHECK_VALUE|=0x0080;else ERR_CHECK_VALUE&=~0x0080; break; }//IDLE_CCS
		case 6:{ if(Cmd==1) ERR_CHECK_VALUE|=0x0008;else ERR_CHECK_VALUE&=~0x0008; break; }//OPP_WARN
		case 7:{ if(Cmd==1) ERR_CHECK_VALUE|=0x0004;else ERR_CHECK_VALUE&=~0x0004; break; }//CCS_WARN
		case 8:{ if(Cmd==1) ERR_CHECK_VALUE|=0x8000;else ERR_CHECK_VALUE&=~0x8000; break; }//温度
		case 9:{ if(Cmd==1) ERR_CHECK_VALUE|=0x2000;else ERR_CHECK_VALUE&=~0x2000; break; }//AC220V
		default:break;
	}
	temp=ERR_CHECK_VALUE&0X5FFF;//剔除MPIOG_ERR,KEYLOCK_ERR
	FSMC_WRITE(ADDR_ERR_CHECK,temp);
}








void Fault_Check()
{
	static u8 TFT_flag=0;
	Reg_Error=FSMC_READ(ADDR_ERROR);
	if(ERR_CHECK_VALUE&0x4000)
	{
		if(Reg_Error&0x4000)	{	Fault_Tab[0]=1;	Error_Code|=0x0001; } else{ Fault_Tab[0]=0; Error_Code&=~0x0001;}//QBH故障
	}
	else 	Fault_Tab[0]=2;

	if(ERR_CHECK_VALUE&0x1000)
	{
		if(Reg_Error&0x1000)	{	Fault_Tab[1]=1;	Error_Code|=0x0002; } else{ Fault_Tab[1]=0; Error_Code&=~0x0002;}//INTERLOCK故障
	}
	else 	Fault_Tab[1]=2;

	if(ERR_CHECK_VALUE&0x0800)
	{
		if(Reg_Error&0x0800)	{	Fault_Tab[2]=1;	Error_Code|=0x0004; } else{ Fault_Tab[2]=0; Error_Code&=~0x0004;}//OPP_LIM故障
	}
	else 	Fault_Tab[2]=2;

	if(ERR_CHECK_VALUE&0x0200)
	{
		if(Reg_Error&0x0200)	{	Fault_Tab[3]=1;	Error_Code|=0x0008; } else{ Fault_Tab[3]=0; Error_Code&=~0x0008;}//CCS_LIM故障
	}
	else 	Fault_Tab[3]=2;

	if(ERR_CHECK_VALUE&0x0100)
	{
			if(Reg_Error&0x0100)	{	Fault_Tab[4]=1;	Error_Code|=0x0010; } else{ Fault_Tab[4]=0; Error_Code&=~0x0010;}//WMT故障
	}
	else 	Fault_Tab[4]=2;
	
	if(ERR_CHECK_VALUE&0x0080)
	{
			if(Reg_Error&0x0080)	{	Fault_Tab[5]=1;	Error_Code|=0x0020; } else{ Fault_Tab[5]=0; Error_Code&=~0x0020;}//CCS_IDLE故障
	}
	else 	Fault_Tab[5]=2;	
	
	
	if(ERR_CHECK_VALUE&0x0008)
	{
			if (Reg_Error&0x0008)	{	Fault_Tab[6]=1;	Error_Code|=0x0040; } else{ Fault_Tab[6]=0; Error_Code&=~0x0040;}//OPP_MAXSAM警告
	}
	else 	Fault_Tab[6]=2;	
	
	if(ERR_CHECK_VALUE&0x0004)
	{
			if(Reg_Error&0x0004)	{	Fault_Tab[7]=1;	Error_Code|=0x0080; } else{ Fault_Tab[7]=0; Error_Code&=~0x0080;}//CCS_MAXSAMP警告
	}
	else 	Fault_Tab[7]=2;		

	if(ERR_CHECK_VALUE&0x8000)
	{
			//if(LDtemperature>350) 	{	Fault_Tab[8]=1;	Error_Code|=0x0100; } else{ Fault_Tab[8]=0; Error_Code&=~0x0100;}//温度故障
	}
	else 	Fault_Tab[8]=2;		
	
	if(ERR_CHECK_VALUE&0x2000)
	{
			if(AC_Power>260) 				{	Fault_Tab[9]=1;	Error_Code|=0x0200; } else{ Fault_Tab[9]=0; Error_Code&=~0x0200;}//供电故障
	}
	else 	Fault_Tab[9]=2;		

	if(	Fault_Tab[3]==1 || Fault_Tab[4]==1 || Fault_Tab[5]==1)
	{
		Fault_LED_SET(0);
		Panel_LED1_SET(0);//红灯
		Panel_LED2_SET(1);//绿灯
	}

	 
}



void Status_Check()
{
	static u16 Reg_Status_Pro=0;
	
	Reg_Status=FSMC_READ(ADDR_STATUS);
	if(Reg_Status^Reg_Status_Pro)
	{
		if(Reg_Status&0x8000)	{	Status_Tab[0]=1;	Status_Code|=0x01; } else{ Status_Tab[0]=0; Status_Code&=~0x01;}//ERROR状态
		if(Reg_Status&0x4000)	{	Status_Tab[1]=1;	Status_Code|=0x02; } else{ Status_Tab[1]=0; Status_Code&=~0x02;}///WARN状态
		if(Reg_Status&0x2000)	{	Status_Tab[2]=1;	Status_Code|=0x04; } else{ Status_Tab[2]=0; Status_Code&=~0x04;}///出光状态	ccs_sw & CCS_RD & (~error_sta);
		if(Reg_Status&0x1000)	{	Status_Tab[3]=1;	Status_Code|=0x08; } else{ Status_Tab[3]=0; Status_Code&=~0x08;}///出光准备状态		CCS_RD;
		if(Reg_Status&0x0800)	{	Status_Tab[4]=1;	Status_Code|=0x10; } else{ Status_Tab[4]=0; Status_Code&=~0x10;}///IDLE状态	~ccs_sw;
	  
		if(Run_Mode==0)//运行模式时
		{
			if(Reg_Status&0x0040)	{	PWM_Mode=3;PWM_Mode_Set(PWM_Mode); }
			else{PWM_Mode=2; PWM_Mode_Set(PWM_Mode);}//PLC_START，此处当作模式选择使用
		}
		if(Reg_Status&0x0100)	{	RedLaser_PIN_SET(0);} else{ RedLaser_PIN_SET(1);}//红光使能				
	}
	
	if(PWM_Mode==3) {	Status_Tab[5]=1;} else{ Status_Tab[5]=0; }//1：内调制，0：AD模式
	if(Run_Mode==1) {	Status_Tab[6]=1;} else{ Status_Tab[6]=0; }//1：调试模式，0：运行模式
	
	Reg_Status_Pro=Reg_Status;
}






























