/*
 * =====================================================================================
 *
 *       Filename:  my_rwl.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月15日 15时53分01秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lafee, wisdomandmircle@gmail.com
 *        Company:  Class 1301 of Software Engineering
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void my_err (const char *err_string, int line); 	//自定义的错误处理函数
int my_read (int fd); 					//自定义的读取数据函数

int main(int argc, char *argv[])
{
	int fd;
	char write_buf[32] = "Hello world!";

	//在当前目录下创建文件example_63.c
	//if ((fd = creat ("example_63.c", S_IRWXU)) == -1) {
	if ((fd = open ("example_63.c", O_RDWR|O_CREAT|O_TRUNC, S_IRWXU)) == -1) {
	
		my_err ("open", errno);
	
	}

	else {
	
		printf ("create filr success!\n");
	
	}

	//写数据
	if (write (fd, write_buf, strlen(write_buf)) != strlen(write_buf)) {
	
		my_err ("write", errno);
	
	}

	my_read (fd);

	//演示文件间隔
	printf ("/*------------------------*/\n");

	if (lseek (fd, 10, SEEK_END) == -1) {
	
		my_err ("lseek", errno);
	
	}
	if (write (fd, write_buf, strlen(write_buf)) != strlen(write_buf)) {
	
		my_err ("write", errno);
	
	}

	my_read (fd);

	close (fd);

	return EXIT_SUCCESS;
}

//自定义的错误处理函数
void my_err (const char *err_string, int line) {

	fprintf (stderr, "line:%d ", line);
	perror (err_string);
	exit (1);

}

//自定义的读取数据函数
int my_read (int fd) {

	int len;
	int ret;
	int i;
	char read_buf[64];

	//获取文件长度并保存文件读写指针在文件开始处
	if (lseek(fd, 0, SEEK_END) == -1) {
	
		my_err ("lseek", errno);
	
	}

	if ((len = lseek (fd, 0, SEEK_CUR)) == -1) {
	
		my_err ("lseek", errno);
	
	}

	if ((lseek (fd, 0, SEEK_SET)) == -1) {
	
		my_err ("lseek", errno);
	
	}

	printf ("len:%d\n", len);

	//读数据
	if ((ret = read(fd, read_buf, len)) < 0) {
	
		my_err ("read", errno);
	
	}

	//打印数据
	for (i = 0; i < len; i++) {
	
		printf ("%c", read_buf[i]);
	
	}

	printf ("\n");

	return ret;
}
