#include "Globle.h"
u16 Reg_Value=0;
u16 LDtemperature=0;
u16 AC_Power=0;
u16 RedLaser_PWM_Value=200;
u8 Run_Mode=0;//0:工作模式，1：调试模式
u8 PWM_Mode=2;//2:AD模式，3：RS232模式

const u16 NTCTAB[]={  //NTC转换值
    3426,3284,3149,3018,2895,2777,2664,2558,2454,2353,
	  2271,2192,2114,2039,1968,1898,1831,1767,1704,1646,
	  1614,1587,1531,1426,1375,1328,1280,1235,1193,1150,
	  1109,1071,1033,996,962,928,895,864,834,803,
	  776,749,722,697,672,648,626,604,582,562,
	  541,522,505,487,469,453,438,421,406,393,
	  379,365,353,339
	  };

void Delay_1us(__IO u16 i){ 
	u16 j;
	while(i--){
		for(j=0;j<7;j++);
	}		  
}
void Delay_1ms(__IO u16 i){ 
	u16 j;
	while(i--){
		for(j=0;j<8000;j++);
	}		  
}

void PORT_Init(void)
{			
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE, ENABLE);										   	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   			
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;    
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;			
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_10;				
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 |GPIO_Pin_9;				
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 |GPIO_Pin_6;				
	GPIO_Init(GPIOD, &GPIO_InitStructure);	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   			
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;    
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;	/*选择要控制的GPIOB引脚*/						
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;	/*选择要控制的GPIOB引脚*/						
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	RedLaser_PIN_SET(1);
	GPIO_SetBits(GPIOB,GPIO_Pin_8); 	
	GPIO_SetBits(GPIOB,GPIO_Pin_10); 	//选择SHT12的通信方式为IIC
} 

void NVIC_Configuration(void)
{
		NVIC_InitTypeDef NVIC_InitStructure;
	  
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);	 //16种抢占优先级，0种响应优先
	
  	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  	NVIC_Init(&NVIC_InitStructure);  	

	  NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;	  
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_Init(&NVIC_InitStructure);
	
		NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;	 
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
		NVIC_Init(&NVIC_InitStructure);	
		
		NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel1_IRQn;	 
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
		NVIC_Init(&NVIC_InitStructure);		
	
    NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 4;	 //5
    NVIC_Init(&NVIC_InitStructure);
  													
    NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn;	  
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;	  
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 6;
    NVIC_Init(&NVIC_InitStructure);

}


void Globle_Init(void)
{
	u16 temp;
	FPGA_RST_SET(0);
	Delay_1ms(10);
	FPGA_RST_SET(1);
	
	LD_Offset_Set(1,0);
	LD_Offset_Set(2,0);
	Work_LED_SET(1);
	Fault_LED_SET(1);
	WMT_Set(1);
	
	Read_Parameter_ToRAM();
	LD_Threshold_Set();	
	temp=ERR_CHECK_VALUE&0X5FFF;//剔除MPIOG_ERR,KEYLOCK_ERR
	FSMC_WRITE(ADDR_ERR_CHECK,temp);// 	屏蔽砖电源，keylock QBHLOCK INTERLOCK TOTAL_POWER_ERR iOPP_FLICK错误
	FSMC_WRITE(ADDR_ANG_KAD,ANG_KAD_VALUE);
	LD_PWM_Set(LD_Frequence,LD_Duty);
	
	Run_Mode_Set(Run_Mode);
	PWM_Mode_Set(PWM_Mode);//AD模式
	FSMC_WRITE(ADDR_TYP_VER,0x2051);//使能FPGA

	Panel_LED1_SET(1);//红灯
	Panel_LED2_SET(0);//绿灯
  
	RedLaser_PIN_SET(0);//红光打开
}
uint8_t Read_IO_State(GPIO_TypeDef* GPIOx,u16 GPIO_Pin_x)
{			
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin_x) == 1 ) 
	{	   
		//Delay_1us(1000);		
		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin_x) == 1 )  
		{	 
			//while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin_x) == 1);   
			return 	1;	 
		}
		else
			return 0;
	}
	else
		return 0;
}


void Key_Scan()
{
	static u8 Run_Mode_Regr=0;
	
	if( Read_IO_State(GPIOC,GPIO_Pin_14)==0)	Run_Mode=1;
	else Run_Mode=0;//LASER	
	if(Run_Mode_Regr^Run_Mode) Run_Mode_Set(Run_Mode);
	
	Run_Mode_Regr=Run_Mode;
}


void Tem_AC220_Check()
{
	u8 i,j,k;	
	u16 temp1[10],temp2[10];
  u16 result_acc[3]={0};
	for(k=0;k<10;k++) { temp1[k]=ADC_Tab[0][k]; temp2[k]=ADC_Tab[1][k];}
	for(i=1;i<10;i++)
	for(j=0;j<(10-i);j++)	 
	{ 
	  exch(&temp1[j],&temp1[j+1]); 
	  exch(&temp2[j],&temp2[j+1]); 
	}
	for(k=0;k<5;k++){ result_acc[0]+=temp1[k+3]; result_acc[1]+=temp2[k+3]; }
	result_acc[0]/=5;
	result_acc[1]/=5;
	LDtemperature=LinearInsert(result_acc[0],NTCTAB);
	AC_Power=(u32)result_acc[1]*175/2357;
}



u16 LinearInsert(u16 tempresult,const u16 *TABLE)
{
 u16 temp;
 u16 array[3];
 if(tempresult <= NTCTAB[0]) //比最低温度值高
   {
    if(tempresult >= NTCTAB[63]) //比最高温度值低
      {
       Lookup_TAB(tempresult,TABLE,array); //折半查表
       if(tempresult == array[0]) temp = (array[2]+2)*Q_Data;//温度值乘以64
       else temp = (array[2]+2)*Q_Data-(tempresult-array[1])*Q_Data/(array[0]-array[1]);//包含小数部分
      }
    else temp = 4160; //上溢出标志+65度
    }
 else temp =128; //下溢出标志+2度  
 temp=temp*10/Q_Data;//温度值的10倍
 return(temp);
}

void Lookup_TAB(u16 resultADC, const u16 *TABLE,u16 *aptr)
{
 u8 i;
 u8 Hptr=63; //高端变量
 u8 Lptr=0; //低端变量
 u8 ptr; //查数变量 
 for(i=0;i<7;i++) //搜索全表,2的7次方为64，最多7次即可搜索完毕
   {
    ptr = Lptr+(Hptr-Lptr)/2;
    if(TABLE[ptr]<resultADC) Hptr = ptr;
    else if(TABLE[ptr]>resultADC) Lptr = ptr;
    else //查到相等的节点
     {
      *aptr = TABLE[ptr]; //Y1
      *(aptr+1) = TABLE[ptr+1]; //Y2
      *(aptr+2) = ptr+1;//X2
      break;
     }
    if(Hptr-Lptr==1) //查到节点的范围
      {
       *aptr = TABLE[Lptr]; //Y1
       *(aptr+1) = TABLE[Hptr]; //Y2
       *(aptr+2) = Lptr+1;//X2
       break;
      }
   }    
}

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


/*********************************************END OF FILE**********************/




























