/*************************************************************************
    >文件名称: fork3.c
    >程序功能:孤儿进程-父进程在子进程前执行完毕，之后该子进程被init进程收养
    >注意事项：
    >创建时间: 2014年12月10日 星期三 20时53分55秒
    >保持好奇，虚心接受
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#define FALSE 0
#define TRUE 1
#define OK 1
#define ERROR 0
#define MAXSIZE 100


int main(int argc, char *argv[])
{
	pid_t pid;

	int k = 5;
	pid = fork();
	switch(pid)
	{
		case 0:
			while(1)
			{
				printf("子进程 is running, PID 为%d, his parent's PID 为%d\n", getpid(), getppid());
				sleep(1);
				//k--;
				if(k == 0)
					exit(0);
				k--;
			}
		case -1:
			perror("Process creation failed\n");
			exit(-1);
		default:
			printf("父进程正在执行，PID为%d", getpid());
			exit(0);
	}

	return 0;
}
