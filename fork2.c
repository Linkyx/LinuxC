/*************************************************************************
    >文件名称: fork2.c
    >程序功能:检测fork函数子进程父进程执行顺序
    >注意事项：
    >创建时间: 2014年12月10日 星期三 20时37分37秒
    >保持好奇，虚心接受
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
#define OK 1
#define ERROR 0
#define MAXSIZE 100


int main(void)
{
	pid_t pid;
	/*msg存储检验子父进程的检验语句*/
	char *msg;
	int k;

	printf("Process creation study 0.0\n");
	pid = fork();

	switch(pid)
	{
		case 0:
			msg = "Childprocess is runing";
			k = 3;
			break;
		case -1:
			perror("Process creation failed\n");
			break;
		default:
			msg = "Parentprocess is running";
			k = 5;
			break;
	}

	while(k>0)		//k相当于子父进程中的两个变量
	{
		puts(msg);
		sleep(1);
		k--;
	}

	exit(0);

}
