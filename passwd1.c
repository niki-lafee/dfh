#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>

void init()//初始化函数库
{
	initscr();//curses库函数，开启curses模式
	cbreak();//除了一些特殊按键，其他按键操作立刻被读取
	nl();
	noecho();//输入字元的时候不显示在屏幕上
	intrflush(stdscr,FALSE);
	keypad(stdscr,TRUE);//开启kaypad模式，将可以使用一些特殊的键盘字元，例如方向按键
	refresh();//清除屏幕
}
int getpasswd(char* passwd, int size)
{
	int c;
	int n = 0;
	init();

	box(stdscr,'|','=');

	move(LINES/2-5,COLS/2-20);
	printw("idina后台管理系统v1.0");
	move(LINES/2,COLS/2-20);
	printw("Please Input password:");
	do
	{
		c = getch();

		if(c == KEY_BACKSPACE && n != 0)
		{
			echochar('\b');
			echochar('\x20');
			echochar('\b');
			n--;
		}
		else if( n== 0 && c ==KEY_BACKSPACE);
		else if ( c != '\n')
		{
			echochar('*');//printw("*");
			passwd[n++] = c;
		}
	}while(c != '\n' && n < (size - 1));
	passwd[n] = '\0';

	refresh();
	endwin();

	return n;
}

int main(void)
{
	char passwd[20];
	int n;

	n=getpasswd(passwd, sizeof(passwd));
  
	printf("\nYour passwd is:%s\n", passwd);

	return 0;
}
