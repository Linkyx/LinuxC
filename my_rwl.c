/*************************************************************************
    >文件名称: my_rwl.c
    >程序功能:
    >注意事项：
    >创建时间: 2014年12月07日 星期日 18时54分54秒
    >保持好奇，虚心接受
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#define FALSE 0
#define TRUE 1
#define OK 1
#define ERROR 0
#define MAXSIZE 100
void my_err(const char* err_string, int line);
int my_read(int fd)
{
	int len = 0;		//记录当前的读写位置
	int ret = 0;		//记录从文件中读取的字节数
	int i = 0;
	char read_buf[64];	//读取的文件内容

	/*获取文件长度并保持文件读写指针在文件开始处*/
	if(lseek(fd, 0, SEEK_END) == -1)
	{
		my_err("lseek", __LINE__);
	}

	if(len = lseek(fd, 0, SEEK_CUR) == -1)
	{
		my_err("lseek", __LINE__);
	}

	if(lseek(fd, 0, SEEK_SET) == -1)
	{
		my_err("lseek", __LINE__);
	}


	printf("len:%d\n", len);
	/*读取数据*/
	if(ret = read(fd, read_buf, len) < 0)
	{
		my_err("read", __LINE__);
	}

	/*打印数据*/
	for(i = 0; i<len; i++)
	{
		printf("%c", read_buf[i]);
	}
	printf("\n");

	return ret;
}


/*自定义的错误处理函数*/
void my_err(const char *err_string, int line)
{
	fprintf(stderr,"line: %d ", line);
	perror(err_string);
	exit(1);
}

int main(int argc, char *argv[])
{
	int fd = 0;		//文件描述符
	char write_buf[32] = "Hello World!";


	/*在当前目录下创建文件example.c*/
	if((fd = open("example.c", O_RDWR|O_CREAT|O_TRUNC, S_IRWXU)) == -1)
	{
		my_err("open", __LINE__);
	}
	else
	{
		printf("Creat example.c success\n");
	}


	/*写数据*/
	if(write(fd, write_buf, strlen(write_buf)) != strlen(write_buf))
	{
		my_err("write", __LINE__);
	}
	my_read(fd);


	/*演示文件的间隔*/
	printf("_______________\n");
	if(lseek(fd, 20, SEEK_END) == -1)
	{
		my_err("lseek", __LINE__);
	}
	if(write(fd, write_buf, strlen(write_buf) != strlen(write_buf)) == -1)
	{
		my_err("write", __LINE__);
	}
	my_read(fd);
	close(fd);
	return 0;

}
