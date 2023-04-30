//#include <REGX52.H>
//#include "S1.h"

//unsigned char MatrixKey()
//{
//	unsigned char KeyNumber;
//	P1=0xf0;
//	if(P1!=0xf0)
//	{
//		Delay(10);
//		if(P1!=0xf0)
//		{
//			P1=0x0f;
//			switch(P1)//列
//			{
//				case(0x07):KeyNumber=1;break;
//				case(0x0b):KeyNumber=2;break;
//				case(0x0d):KeyNumber=3;break;
//				case(0x0e):KeyNumber=4;break;
//			}
//			P1=0xf0;
//			switch(P1)//行
//			{
//				case(0x70):KeyNumber=KeyNumber;break;
//				case(0xb0):KeyNumber=KeyNumber+4;break;
//				case(0xd0):KeyNumber=KeyNumber+8;break;
//				case(0xe0):KeyNumber=KeyNumber+12;break;
//			}
//			while(P1!=0xf0);
//		}
//	}
//	
//	return KeyNumber;
//}