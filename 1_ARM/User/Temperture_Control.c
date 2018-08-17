#include "Temperture_Control.h"
#include "Globle.h"
#include "Timer.h" 

u16 LDtemperature=0,Tem_Set_Value1=3000,Tem_Set_Value2=1000;//实际温度值的10倍,温度初始化为38℃；
u16 Hold_Time1=25,Hold_Time2=10;

u16 LDtemperature2=0;
u8 Temperture_Fault=0;//LD温度故障
u16 Tem_Tab[12]={0};
u16 PT100_Tab[12]={0};
u32 R_Value=0;

int32_t EK=0,EK1=0;
int32_t Kp=70,Ki=12,Kd=200;
int32_t Pterm=0,Iterm=0,Dterm=0;
int32_t UK=0;
u16 PWM_Value=0;
u16 PV=0,IV=0,DV=0;

u16 PWM_Edge1=2000,PWM_Edge2=2000,PWM_Edge3=2000;

u8 Current_State=0;
u8 Tem_Cmd=0;

u16 RTD_TAB_PT100[211] =   
{
1852,2068,2283,2497,2710,2922,3134,3344,3554,3764,        // -200 ~ -155   10
3972,4180,4388,4594,4800,5006,5211,5415,5619,5823,           // -150 ~ -105
6026,6228,6430,6631,6833,7033,7233,7433,7633,7832,        // -100 ~ -55
8031,8229,8427,8625,8822,9019,9216,9412,9609,9804,        //        -50 ~ -5
10000,10195,10390,10585,10779,10973,11167,11361,11554,11747,         // 0   ~ 45
11940,12132,12324,12516,12708,12899,13090,13280,13471,13661,        // 50  ~ 95
13851,14040,14229,14418,14607,14795,14983,15171,15358,15546,        // 100 ~ 145
15733,15919,16105,16291,16477,16663,16848,17033,17217,17402,        // 150 ~ 195
17586,17769,17953,18136,18319,18501,18684,18866,19047,19229,        // 200 ~ 245
19410,19591,19771,19951,20131,20311,20490,20670,20848,21027,        // 250 ~ 295
21205,21383,21561,21738,21915,22092,22268,22445,22621,22796,        // 300 ~ 345
22972,23147,23321,23496,23670,23844,24018,24191,24364,24537,        // 350 ~ 395
24709,24881,25053,25225,25396,25567,25738,25908,26078,26248,        // 400 ~ 445
26418,26587,26756,26925,27093,27261,27429,27597,27764,27931,        // 450 ~ 495
28098,28264,28430,28596,28762,28927,29092,29256,29421,29585,        // 500 ~ 545
29749,29912,30075,30238,30401,30563,30725,30887,31049,31210,        // 550 ~ 595
31371,31531,31692,31852,32012,32171,32330,32489,32648,32806,        // 600 ~ 645
32964,33122,33279,33436,33593,33750,33906,34062,34218,34373,        // 650 ~ 695
34528,34683,34838,34992,35146,35300,35453,35606,35759,35912,        // 700 ~ 745
36064,36216,36367,36519,36670,36821,36971,37121,37271,37421,        // 750 ~ 795
37570,37719,37868,38017,38165,38313,38460,38608,38755,38902,        // 800 ~ 845
39048        // 850
};



u16 CalculateTemperature(u16 fR)
{
    u16 fTem;
    u16 fLowRValue;
    u16 fHighRValue;        
    u16 iTem;
    u8 i;
	u8 cBottom, cTop;

    cBottom = 0; 
    cTop    = 210;
    if (fR < RTD_TAB_PT100[40])  return 0;           
	else  if (fR > RTD_TAB_PT100[210]) return 850;       
	else 
	{
        for (i=105; (cTop-cBottom)!=1; )        // 2?????
        {
                if (fR < RTD_TAB_PT100[i])
                {
                        cTop = i;
                        i = (cTop + cBottom) / 2;
                }
                else if (fR > RTD_TAB_PT100[i])
                {
                        cBottom = i;
                        i = (cTop + cBottom) / 2;
                }
                else
                {
                        iTem = (u16)i * 50 - 2000;
                        fTem = (u16)iTem;

                        return fTem;
                }
        }

        iTem = (u16)i * 5 - 200;

        fLowRValue  = RTD_TAB_PT100[cBottom];
        fHighRValue = RTD_TAB_PT100[cTop];

        //fTem = ( ((fR - fLowRValue)*5) / (fHighRValue - fLowRValue) ) + iTem;       
		fTem = ( ((fR - fLowRValue)*50) / (fHighRValue - fLowRValue) ) + iTem*10;
        return fTem;
	}
}

u16 Data_Filter(u16 *Tab)
{
	u8 jadc0=0,k=0;
	u16 temp1[10];
	u32 result_acc1=0;
	
	for(k=0;k<10;k++)  
	{ 
		temp1[k]=Tab[k];  
	}
	
	for(jadc0=1;jadc0<10;jadc0++)//防脉冲干扰平均值滤波法
	for(k=0;k<(10-jadc0);k++)	 
	{ 
		exch(&temp1[k],&temp1[k+1]); 
	}
	
	for(jadc0=0;jadc0<6;jadc0++)
	{ 
		result_acc1+=temp1[jadc0+2];
	}
	
	result_acc1/=6;	
	return  result_acc1;
}



void Tem_Process(void)
{   
	u32 AD_Value=0,temp;
	static u16 PT_V1=0,PT_V2=0;
	static u8 rank=0;
	static u16 Temp_value=0,Last_Temp_value=0,flag=0;
	int16_t D_value;
	u16 Temp_PWM=0;

	AD_Value=Data_Filter(Tem_Tab);
	if(PT_Flag==0)	//采样V1
	{
		PT_V1 =	AD_Value*3628/4095;//基准电压3V，PT_V1为实际的十倍
		PT100_PIN_SET(1);
		Delay_1ms(1);
		ADC_DMACmd(ADC1, ENABLE);  
		PT_Flag=1;
	}
	else if(PT_Flag==1)	//采样V2
	{
		PT_V2 =	AD_Value*3628/4095;//基准电压3V，PT_V1为实际的十倍
		PT100_PIN_SET(0);
		Delay_1ms(1);
				
		temp=1001000*(2*PT_V1-PT_V2)/(30000-PT_V2);		
		PT100_Tab[rank++]=temp;
		if(rank==10)
		{
			R_Value=Data_Filter(PT100_Tab);
		    LDtemperature=CalculateTemperature(R_Value);
		/*	if(	flag==0 ) 
			{
				Last_Temp_value=Temp_value;
				flag=1;
			}
 
			D_value=(int16_t)Last_Temp_value-(int16_t)Temp_value;
			if(D_value>500)
			{
				LD_PWM_Set(0);
				ADC_Cmd(ADC1, DISABLE);
				ADC_DMACmd(ADC1, DISABLE);
				while(1);
			 	
			}
			else 
			{
				LDtemperature=Temp_value;
			 	Last_Temp_value=Temp_value;	
			}*/
			//Tem_State_Control();
			
			Temp_PWM=Tem_PID_Control(Tem_Set_Value1,LDtemperature); 
		    if(Fault_Code==0&&Tem_Cmd==1)	LD_PWM_Set(Temp_PWM);
			else  LD_PWM_Set(0);
					
			rank=0;
		}
		ADC_DMACmd(ADC1, ENABLE);
		PT_Flag=0;
	}
}



void Tem_State_Control(void)
{
	int16_t Dvalue=0;
	static u16 Temp_PWM=0;

    if(Current_State==0)
	{				
		Dvalue=(int16_t)Tem_Set_Value1-(int16_t)LDtemperature;
		if(Dvalue>-15&&Dvalue<15) 
		Current_State=1;
		else Current_State=0;
	}
	else if(Current_State==1)
	{
		if(Tem_State_Count==Hold_Time1) 
		{
			Current_State=2;
			Tem_State_Count=0;
		}
		else Current_State=1;
	}
	else if(Current_State==2)
	{				
		Dvalue=(int16_t)Tem_Set_Value2-(int16_t)LDtemperature;
		if(Dvalue>-15&&Dvalue<15) 
		Current_State=3;
		else Current_State=2;
	}
	else if(Current_State==3)
	{				
		if(Tem_State_Count==Hold_Time2)
		{
		 	Current_State=4;
			Tem_State_Count=0;
		}
		else Current_State=3;
	}
	else if(Current_State==4)
	{				
		Dvalue=(int16_t)Tem_Set_Value2-(int16_t)LDtemperature;
		if(Dvalue>200)
		{
		 	Current_State=0;
		}
		else Current_State=4;
	}

	if(Current_State<2) Temp_PWM=Tem_PID_Control(Tem_Set_Value1,LDtemperature);
	else if(Current_State<4) Temp_PWM=Tem_PID_Control(Tem_Set_Value2,LDtemperature); 
	else if(Current_State==4) Temp_PWM=Tem_PID_Control(0,LDtemperature); 

	LD_PWM_Set(Temp_PWM);	
}


u16 Tem_PID_Control(u16 Tem_Set,u16 Tem_Value)
{
	static flag=0;
	//Tem_Set=Tem_Set+10;

	EK=Tem_Set-Tem_Value;//温度偏差 
	if(EK<30) 
	{
		Kd=0;
		Ki=12;
	}
	else 
	{
		Kd=500;
		Ki=0;	
	}
	Pterm=Kp*EK;
	Iterm+=Ki*EK/10;
	if(Iterm>2000) Iterm=2000;
	Dterm=Kd*(EK-EK1); 		 
	UK=Pterm+Iterm+Dterm;



	if(UK>10000) UK=10000;  
	else if(UK<0)UK=0;	

	EK1=EK; 

	PWM_Value=UK;//加热
	return PWM_Value; 
}
									   	


/*数据交换子程序*/
void exch(u16 *b1,u16 *b2)
{
 u16 z;
 if(*b1>*b2)
   {
	 z=*b1;
	 *b1=*b2;
	 *b2=z;
	}
}

