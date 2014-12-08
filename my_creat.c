/*************************************************************************
    >文件名称: my_creat.c
    >程序功能:
    >注意事项：
    >创建时间: 2014年12月06日 星期六 10时48分34秒
    >保持好奇，虚心接受
 ************************************************************************/

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#define FALSE 0
#define TRUE 1
#define OK 1
#define ERROR 0
#define MAXSIZE 100


int main(int argc, char *argv[])
{
	int fd = 0;

	//if((fd = open("test.c", O_CREAT|O_EXCL, S_IWUSR)) == -1)
	if(fd = creat("test.c", S_IWUSR) == -1)
	{
		perror("open");
		exit(1);
	}
	else
	{
		printf("cerat file success\n");
	}


	close(fd);

	return 0;
}
