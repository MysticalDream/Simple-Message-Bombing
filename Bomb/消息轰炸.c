/*
*Copyright ©2021.All Rights Reserved.
*功能：复制一段你要发送的文字，打开你要轰炸的聊天窗口，点开此程序按提示操作即可。微信和QQ略有不同QQ需要指定备注。
*/
/*
*复制一段你要发送的文字，打开你要轰炸的聊天窗口，点开此程序按提示操作即可。微信和QQ略有不同QQ需要指定备注。
*/
#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<stdlib.h>
#define LENGTH 5//该数是函数selectcharacter中STRING的长度加一
#define STRING 1234//需要判断的字符串集合，可以根据需要修改
#define MAX 30//轰炸次数
#define STR1(x) STR2(x)
#define STR2(x) #x
/*微信轰炸*/
void bombingwechat(int count1);
/*QQ轰炸*/
void bombingqq(int count2);
/*判断输入选择，可以不用考虑此函数，因为这不是这个程序的重点*/
char selectcharacter();
 int main(int argc,char *argv[])
 {
	char choose;
 	int count;
	int flag;
	system("MODE CON COLS=100 LINES=30");
	do{
		flag=1;
		count=0;
		printf("请输入轰炸应用\n1.QQ\t2.微信\t3.退出\t4.使用帮助(在该程序中的确认键即回车键（enter）)\n");
	    printf("请输入数字：");
		/*可以不考虑此处*/
	    choose=selectcharacter();
	    switch(choose)
	   {
	    case '1':
			do{
				/*限制输入防止被禁*/
			printf("请输入轰炸次数:");
	       flag= scanf("%d",&count);
			if(count>MAX)
				printf("请控制在30次以内\n");
			else if(!flag||!(~flag))
				printf("请输入数字\n");
			else/*QQ轰炸函数*/
				bombingqq(count);
			rewind(stdin);
			}while(count>MAX||(!flag||!(~flag)));
		      break;
	    case '2':
			do{
				/*限制输入防止被禁*/
			printf("请输入轰炸次数:");
	       flag= scanf("%d",&count);
			if(count>MAX)
				printf("请控制在30次以内\n");
			else if(!flag||!(~flag))
				printf("请输入数字\n");
			else/*微信轰炸函数*/
				bombingwechat(count);
			rewind(stdin);
			}while(count>MAX||(!flag||!(~flag)));
		      break;
		 /*退出*/
		case -1:printf("输入的数字不在列表请重新输入\n\n");
			        break;
	    case '3':exit(0);
		case '4':printf("\
\n帮助\n在该程序中确认键即回车键（enter）\n\
步骤一：使用该程序需要先复制一段你要发送的内容。\n\
步骤二：打开QQ或者微信（不要关闭）。\n\
步骤三：进入到你要发送复制内容的好友聊天对话框界面，然后打开此程。\n\
步骤四：在程序中输入要发送的次数后，按回车键（enter）即可。\
(特别说明QQ还需要输入要轰炸对象的备注)\n\n");
	   }
	   }while(choose!='3');
    return 0;
 }
 void bombingwechat(int count1)
 {
	 /*窗口标题名*/
	 wchar_t str[]=L"微信";//TODO：该处在C-Free5的MinGW中编译不了，字符编码的问题没有解决。
	 /*窗口句柄*/
 	HWND A;
	/*窗口类名*/
	wchar_t wStr[]=L"WeChatMainWndForPC";
	/*获得窗口句柄*/
#ifdef UNICODE//TODO：该处有些机器有错误要改进
	 A=FindWindow(wStr,str);
#else
	A=FindWindow("WeChatMainWndForPC","微信");
#endif
	 /*判断是否找到窗口*/
	if(A==NULL)
	{
		puts("不好意思，没找到WeChat");
		return;
	}
	SetForegroundWindow(A);/*将窗口设置到前台*/
	printf("窗口句柄：%#X\n",A);
 	while(count1--)
 	{	
		/*下面是模拟键盘敲击*/
 		keybd_event(VK_CONTROL,0,0,0);/*按下ctrl键*/
 		keybd_event('V',0,0,0);/*按下V键*/
 		keybd_event('V',0,KEYEVENTF_KEYUP,0);/*松开V键*/
 		keybd_event(VK_CONTROL,0,KEYEVENTF_KEYUP,0);/*松开ctrl键*/
		keybd_event(VK_RETURN,0,0,0);/*按下enter键*/
		keybd_event(VK_RETURN,0,KEYEVENTF_KEYUP,0);/*松开enter键*/
 		Sleep(100);/*延迟100毫秒，避免频繁输入*/
 	}
    printf("\n轰炸完成\n");
 }
 void bombingqq(int count2)
 {
	 char name[100];
	wchar_t *str;
	wchar_t wStr[]=L"TXGuiFoundation";
 	HWND A;
	wchar_t* convert(const char *str);
	printf("请输入轰炸对象QQ备注：");
	scanf("%99s",name);
#ifdef UNICODE//TODO：该处有些机器有错误要改进
	str=convert(name);
	 A=FindWindow(wStr,str);
#else
	  A=FindWindow("TXGuiFoundation",name);
#endif
	if(A==NULL)
	{
		puts("不好意思，没找到QQ");
		return;
	}
	SetForegroundWindow(A);/*将窗口设置到前台*/
	printf("窗口句柄：%#X\n",A);
 	while(count2--)
 	{		
 		/*下面是模拟键盘敲击*/
 		keybd_event(VK_CONTROL,0,0,0);/*按下ctrl键*/
 		keybd_event('V',0,0,0);/*按下V键*/
 		keybd_event('V',0,KEYEVENTF_KEYUP,0);/*松开V键*/
 		keybd_event(VK_CONTROL,0,KEYEVENTF_KEYUP,0);/*松开ctrl键*/
		keybd_event(VK_RETURN,0,0,0);/*按下enter键*/
		keybd_event(VK_RETURN,0,KEYEVENTF_KEYUP,0);/*松开enter键*/
 		Sleep(100);/*延迟100毫秒，避免频繁输入*/
 	}
    printf("\n轰炸完成\n");
 }
 /*判断输入的函数，不是函数的主要部分，可以忽略*/
 char selectcharacter()
{
	char buffer[3]="\0",array0[LENGTH]=STR1(STRING);
	int counter=0;
	scanf("%2s",buffer);
                rewind(stdin);
	do{
        if((buffer[0]==array0[counter])&&buffer[1]=='\0')
	    return buffer[0];
                    counter++;
	}while(counter<LENGTH);
	return -1;
}
 /*该函数是将char 转为wchar_t类型*/
 wchar_t* convert(const char *str)
{
    int length = strlen(str)+1;
    wchar_t *t = (wchar_t*)malloc(sizeof(wchar_t)*length);
    memset(t,0,length*sizeof(wchar_t));
    MultiByteToWideChar(CP_ACP,0,str,strlen(str),t,length);
    return t;
}
