/*************************************************************************
    >文件名称: my_chmod.c
    >程序功能:
    >注意事项：
    >创建时间: 2014年12月05日 星期五 21时07分33秒
    >保持好奇，虚心接受
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#define FALSE 0
#define TRUE 1
#define OK 1
#define ERROR 0
#define MAXSIZE 100

int main(int argc, char **argv)
{
	int mode;	//权限
	int mode_u;	//所有者权限
	int mode_g;	//所在组用户权限
	int mode_o;	//其他人组用户权限
	char *path;	//文件描述符

	/*检验参数个数是否合法*/
	if(argc < 3)
	{
		printf("参数个数有误，请检查\n");
		exit(0);
	}

	/*获取命令行参数*/
	mode = atoi(argv[1]);
	if(mode > 777 || mode < 0)
	{
		printf("参数数值有误，请检查\n");
		exit(0);
	}

	mode_u = mode/100;
	mode_g = (mode - (mode_u * 100))/10;
	//mode_o = (mode * 8 * 8) + (mode_g * 8) + mode_o;
	mode_o = mode - (mode_g * 10 + mode_u * 100);
	mode = (mode_u * 8 * 8) + (mode_g * 8) + mode_o;
	path = argv[2];

	if(chmod(path, mode) == -1)
	{
		perror("chmod error\n");
		exit(1);
	}


	//printf("%d%s",argc, argv[0]);
	return 0;
}
