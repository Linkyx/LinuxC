/*************************************************************************
    >文件名称: fork.c
    >程序功能:检验fork函数返回值
    >注意事项：
    >创建时间: 2014年12月10日 星期三 19时50分30秒
    >保持好奇，虚心接受
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
#define OK 1
#define ERROR 0
#define MAXSIZE 100


int main(int argc, char *argv[])
{
	pid_t pid;	//pid_t为头文件<sys.types.h>中int的宏定义

	printf("Process Creation Study\n");
	pid = fork();

	switch(pid)
	{
		case 0:
			printf("Child process is running,CurPid is %d, ParentPid is %d\n",pid, getppid());
			break;
		case -1:
			printf("Process creation faild\n");
			break;
		default:
			printf("Parent process is running, ChildPid is %d, MyPid is %d\n", pid, getpid());
			break;
	}

	exit(0);
}
