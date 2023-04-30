#include <REGX52.H>
#include "S1.h"
#include "LCD1602.h"

unsigned char b,i;

unsigned char MatrixKey()
{
	unsigned char KeyNumber;
	P1=0xf0;
	if(P1!=0xf0)
	{
		Delay(10);
		if(P1!=0xf0)
		{
			P1=0x0f;
			switch(P1)//列
			{
				case(0x07):KeyNumber=1;break;
				case(0x0b):KeyNumber=2;break;
				case(0x0d):KeyNumber=3;break;
				case(0x0e):KeyNumber=4;break;
			}
			P1=0xf0;
			switch(P1)//行
			{
				case(0x70):KeyNumber=KeyNumber;break;
				case(0xb0):KeyNumber=KeyNumber+4;break;
				case(0xd0):KeyNumber=KeyNumber+8;break;
				case(0xe0):KeyNumber=KeyNumber+12;break;
			}
			while(P1!=0xf0);
			b++;
		}
	}
	
	return KeyNumber;
}

void main()
{
	unsigned char n,a=1;
	unsigned int Password;
	unsigned int pw=202;//密码
	LCD_Init();
	LCD_ShowString(1,1,"Enter Password");
	LCD_ShowChar(2,1,'_');
	LCD_ShowChar(2,2,'_');
	LCD_ShowChar(2,3,'_');
	LCD_ShowChar(2,4,'_');
	
	while(1)
	{
		
		n=MatrixKey();
		
		if(n<=10)
		{
			if(i!=b)
			{
				if(a<=4)
				{
					
					Password=Password*10;
					Password=n%10+Password;
					LCD_ShowNum(2,a,n,1);
					a++;
				}
				b=0;
			}
			
			
			if(a==5){LCD_ShowString(2,7,"CFM(S11)");}
				
		}

		if(n==11)//判断密码是否正确
		{
			
			if(Password==pw)
			{
				LCD_Init();
				LCD_ShowString(1,1,"PASS         -->");
				LCD_ShowString(2,1,"Close the door 5");
				Delay(1000);
				LCD_ShowString(2,1,"Close the door 4");
				Delay(1000);
				LCD_ShowString(2,1,"Close the door 3");
				Delay(1000);
				LCD_ShowString(2,1,"Close the door 2");
				Delay(1000);
				LCD_ShowString(2,1,"Close the door 1");
				Delay(1000);
				Password=0;
				b=0;
				a=1;
				LCD_Init();
				LCD_ShowString(1,1,"Enter Password");
				LCD_ShowChar(2,1,'_');
				LCD_ShowChar(2,2,'_');
				LCD_ShowChar(2,3,'_');
				LCD_ShowChar(2,4,'_');
			}
			else
			{
				LCD_Init();
				LCD_ShowString(1,1,"Enter Password");
				LCD_ShowString(2,1,"Error!");
				Password=0;
				b=0;
				a=1;
				Delay(1500);
				LCD_Init();
				LCD_ShowString(1,1,"Enter Password");
				LCD_ShowChar(2,1,'_');
				LCD_ShowChar(2,2,'_');
				LCD_ShowChar(2,3,'_');
				LCD_ShowChar(2,4,'_');
			}
		}
		if(n==12)//退位重新输入
		{
			a--;
			LCD_ShowChar(2,a,'_');
			Password=Password/10;
			b=0;
			LCD_ShowString(2,7,"        ");
		}
		if(n==16)//更改密码
		{
			LCD_Init();
			LCD_ShowString(1,1,"Old password");
			LCD_ShowChar(2,1,'_');
			LCD_ShowChar(2,2,'_');
			LCD_ShowChar(2,3,'_');
			LCD_ShowChar(2,4,'_');
			a=1;
			Password=0;
			n=0;
			while(1)//输入原密码
			{
				n=MatrixKey();
				if(n<=10)
				{
					if(i!=b)
					{
						if(a<=4)
						{
							
							Password=Password*10;
							Password=n%10+Password;
							LCD_ShowNum(2,a,n,1);
							a++;
						}
						b=0;
					}
				}
				if(a==5){break;}
			}
			if(Password==pw)//如果密码正确，输新原密码
			{
				LCD_Init();
				LCD_ShowString(1,1,"New Password");
				LCD_ShowChar(2,1,'_');
				LCD_ShowChar(2,2,'_');
				LCD_ShowChar(2,3,'_');
				LCD_ShowChar(2,4,'_');
				a=1;
				Password=0;
				n=0;
				while(1)
				{
					n=MatrixKey();
					if(n<=10)
					{
						if(i!=b)
						{
							if(a<=4)
							{
								
								Password=Password*10;
								Password=n%10+Password;
								LCD_ShowNum(2,a,n,1);
								a++;
							}
							b=0;
						}
					}
					if(a==5){break;}
				}
				pw=Password;
				LCD_Init();
				LCD_ShowString(1,1,"New Password");
				LCD_ShowString(2,1,"OK!");
				Delay(1000);
				LCD_Init();
				LCD_ShowString(1,1,"Enter Password");
				LCD_ShowChar(2,1,'_');
				LCD_ShowChar(2,2,'_');
				LCD_ShowChar(2,3,'_');
				LCD_ShowChar(2,4,'_');
				a=1;
				Password=0;
			}
			else
			{
				LCD_Init();
				LCD_ShowString(1,1,"Original password");
				LCD_ShowString(2,1,"Error!");
				Password=0;
				b=0;
				a=1;
				Delay(1500);
				LCD_Init();
				LCD_ShowString(1,1,"Enter Password");
				LCD_ShowChar(2,1,'_');
				LCD_ShowChar(2,2,'_');
				LCD_ShowChar(2,3,'_');
				LCD_ShowChar(2,4,'_');
			}
		}
	
	}//while(1)


}//main