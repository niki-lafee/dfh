/*
 * =====================================================================================
 *
 *       Filename:  my_ls.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月18日 08时29分12秒
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
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <linux/limits.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <errno.h>

#define PARAM_NONE 0 	//无参数
#define PARAM_A 1 	//-a：显示所有文件
#define PARAM_L 2 	//-l：一行只显示一个文件的详细信息
#define PARAM_M 4 	//-m：横向输出文件名，以","为分隔
#define MAXROWLEN 80 	//一行显示的最多字符数

void my_err (const char *err_string, int line); 	//自定义的错误处理函数，打印出错误所在行的行数和错误信息
void display_attribute (struct stat buf, char *name); 	//获取文件属性
void display_single (int flag_param, char *name); 			//在没有-l 选项时，打印一个文件名，打印时上下对齐
void display (int flag, char *pathname); 		/*
							 * 	根据命令行参数和完整路径名显示目标文件
							 * 	参数flag： 命令行参数
							 * 	参数pathname： 包含了文件的路径名
							 */
void display_dir (int flag_param, char *path); 		//将命令行参数指定的目录下的文件显示出来

int g_leave_len = MAXROWLEN; 		//一行剩余长度，用于输出对齐
int g_maxlen; 				//一行显示的最多字符数

int main(int argc, char **argv)
{
	int i, j, k, num;
	char path[PATH_MAX + 1];
	char param[32]; 			//保存命令行参数，目标文件名和目录名不在此列
	int flag_param = PARAM_NONE; 		//参数种类， -l，-a
	struct stat buf; 			//保存文件状态信息的结构体

	//命令行参数解析，-l, -a, -al, -la, m, am, lm, lam
	j = 0;
	num = 0;
	for (i = 1; i < 9; i++) {
	
		if (argv[i][0] == '-') {
		
			for (k = 1; k < strlen(argv[i]); k++, j++) {
		
				param[j] = argv[i][k]; 		//获取"-"后面的参数保存到数组param中
			
			}

			num++; 		//保存"-"的个数
		
		}
	
	}

	//只支持参数 -a , -m 和 -l，若有其他的，报错
	for (i = 0; i < j; i++) {
	
		if (param[i] == 'a') {
		
			flag_param |= PARAM_A;
			continue;
		
		}

		if (param[i] == 'l') {
		
			flag_param |= PARAM_L;
			continue;
		
		}

		if (param[i] == 'm') {
		
			flag_param |= PARAM_M;
		
		}

		else {
		
			printf ("my_ls: invalid option -%c\n", param[i]);
			exit (1);
		
		}
	
	}
	param[j] = '\0';

	//如果没有输入文件名或目录，就显示当前目录
	if ((num + 1) == argc) {
	
		strcpy (path, "./");
		path[2] = '\0';
		display_dir (flag_param, path);
		return 0;
	
	}

	i = 1;
	do {
	
		//如果不是目标文件名或目录，解析下一个命令行参数
		if (argv[i][0] == '-') {
		
			i++;
			continue;
		
		}

		else {
		
			strcpy (path, argv[i]);

			//如果目标文件名或目录不存在，报错并退出
			if (stat (path, &buf) == -1) {
			
				my_err ("stat", errno);

			}

			if (S_ISDIR (buf.st_mode)) { 	//argv[i]是个目录
			
				//如果目录的最后一个字符不是'/', 就加上'/'
				if (path[strlen(argv[i] - 1)] != '/') {
				
					path[strlen(argv[i])] = '/';
					path[strlen(argv[i]) + 1] = '\0';
				
				}
			
				else {
				
					path[strlen(argv[i])] = '\0';
				
				}

				display_dir (flag_param, path);
			}
		
		}
	
	} while (i < argc);

	return EXIT_SUCCESS;
}

//自定义的错误处理函数，显示出错误所在行
void my_err (const char *err_string, int line) {

	fprintf (stderr, "line: %d\n", line);
	perror (err_string);

	exit (1);

}

//在没有使用 -l 选项时， 打印一个文件名，上下对齐
void display_single (int flag_param, char *name) {

	int i, len;

	//判断是否有 -l 选项
	//若本行不足以打印一个文件
	if  (((flag_param & PARAM_M) == 0) && (g_leave_len < g_maxlen)) {
	
		printf ("\n");
		g_leave_len = MAXROWLEN;
	
	}

	len = strlen (name);
	len = g_maxlen - len;
	printf ("%-s", name);

	for (i = 0; i < len; i++) {
	
		printf (" ");
	
	}

	printf ("  ");

	//其中2表示空2格
	g_leave_len -= (g_maxlen + 2);

}

void display_attribute (struct stat buf, char *name) {

	char buf_time[32];
	struct passwd *psd; 	//从该结构体中获取文件所有者的用户名
	struct group *grp; 	//从该结构体中获取文件所有者所属组的组名

	//获取文件属性并打印
	if (S_ISLNK (buf.st_mode)) { 		//判断是否为符号链接
	
		printf ("l");
	
	}

	else if (S_ISREG (buf.st_mode)) { 	//一般文件？
	
		printf ("-");
	
	}

	else if (S_ISDIR (buf.st_mode)) { 	//目录文件？
	
		printf ("d");
	
	}

	else if (S_ISCHR (buf.st_mode)) { 	//字符设备文件？
	
		printf ("c");
	
	}

	else if (S_ISBLK (buf.st_mode)) { 	//块设备文件？
	
		printf ("b");
	
	}

	else if (S_ISFIFO (buf.st_mode)) { 	//先进先出FIFO？
	
		printf ("f");
	
	}

	else if (S_ISSOCK (buf.st_mode)) { 			//socket?
	
		printf ("s");
	
	}

	//获取并打印文件所有者的权限
	if (buf.st_mode & S_IRUSR) {
	
		printf ("r");
	
	}

	else {
	
		printf ("-");
	
	}

	if (buf.st_mode & S_IWUSR) {
	
		printf ("w");
	
	}

	else {
	
		printf ("-");
	
	}

	if (buf.st_mode & S_IXUSR) {
	
		printf ("x");
	
	}

	else {
	
		printf ("-");
	
	}

	//获取并打印文件所有者同组的用户对该文件的操作权限
	if (buf.st_mode & S_IRGRP) {
	
		printf ("r");
	
	}

	else {

		printf ("-");
	
	}

	if (buf.st_mode & S_IWGRP) {
	
		printf ("w");
	
	}

	else {
	
		printf ("-");
	
	}

	if (buf.st_mode & S_IXGRP) {

		printf ("x");
	
	}

	else {

		printf ("-");
	
	}

	//获取并打印其他用户对该文件的操作权限
	if (buf.st_mode & S_IROTH) {
	
		printf ("r");
	
	}

	else {
	
		printf ("-");

	}

	if (buf.st_mode & S_IWOTH) {
	
		printf ("w");
	
	}

	else {
	
		printf ("-");
	
	}

	if (buf.st_mode & S_IXOTH) {
	
		printf ("x");
	
	}

	else {
	
		printf ("-");
	
	}

	//根据uid与gid获取文件所有者的用户名和组名
	psd = getpwuid (buf.st_uid);
	grp = getgrgid (buf.st_gid);
	printf ("%3d", buf.st_nlink); 	//打印文件的链接数
	printf ("%8s", psd -> pw_name);
	printf ("%8s", grp -> gr_name);

	printf ("%8d", buf.st_size); 	//打印文件的大小
	strcpy (buf_time, ctime (&buf.st_mtime)); 	//获取文件最后一次被修改的时间
	buf_time[strlen (buf_time) - 1] = '\0'; 	//去掉换行符
	printf (" %s", buf_time); 	//打印文件的时间信息


}

/*
 * 	根据命令行参数和完整路径名显示目标文件
 * 	参数flag： 命令行参数
 * 	参数pathname： 包含了文件名的路径名
 */
void display (int flag, char *pathname) {

	int i, j, flag_param = flag;
	struct stat buf;
	char name[NAME_MAX + 1];

	//从路径解析文件名
	for (i = 0, j = 0; i < strlen(pathname); i++) {
	
		if (pathname[i] == '/') {
		
			j = 0;
			continue;
		
		}

		name[j++] = pathname[i];
	
	}
	name[j] = '\0';

	//用lstat解析链接文件
	if (lstat (pathname, &buf) == -1) {
	
		my_err ("stat", errno);
	
	}

	switch (flag) {
	
		case PARAM_NONE: 	//无 -l, -a;
			if (name[0] != '.') {
			
				display_single (flag_param, name);
			
			}
			break;
		case PARAM_A:  		//-a;
			display_single (flag_param, name);
			break;
		case PARAM_M: 		//-m;
			if (name[0] != '.') {

				display_single (flag_param, name);
				printf (" , ");

			}
			break;
		case PARAM_L: 		//-l;
			if (name[0] != '.') {
			
				display_attribute (buf, name);
				printf (" %-s\n", name);
			
			}
			break;
		case PARAM_A + PARAM_L: //-a,-l
			display_attribute (buf, name);
			printf (" %-s\n", name);
			break;
	
	}

}

//将命令行参数指定的目录下的文件显示出来
void display_dir (int flag_param, char *path) {

	DIR *dir;
	struct dirent *ptr;
	int count = 0;
	char filename[256][PATH_MAX + 1], temp[PATH_MAX + 1];
	int i, j, len = strlen (path);

	//获取该目录下文件总数和最长文件名
	dir = opendir (path);
	if (dir == NULL) {
	
		my_err ("opendir", errno);
	
	}

	while ((ptr = readdir(dir)) != NULL) {
	
		if (g_maxlen < strlen(ptr -> d_name)) {
		
			g_maxlen = strlen(ptr -> d_name);
		
		}

		count++;
	
	}

	closedir (dir);

	if (count > 256) {
	
		my_err ("too many files under this dir", errno);
	
	}

	//获取该目录下所有文件名
	dir = opendir (path);
	for (i = 0; i < count; i++) {
	
		ptr = readdir (dir);
		if (ptr == NULL) {
		
			my_err ("readdir", errno);
		
		}

		strncpy (filename[i], path, len);
		filename[i][len] = '\0';
		strcat (filename[i], ptr -> d_name);
		filename[i][len + strlen(ptr -> d_name)] = '\0';
	
	}

	//用冒泡对文件名进行排序，按字母顺序存储于filename
	for (i = 0; i < count - 1; i++)
	      for (j = 0; j < count - 1 - i; j++) {
	      
		      if (strcmp (filename[j], filename[j + 1]) > 0) {
		      
			      strcpy (temp, filename[j]);
			      temp[strlen(filename[j])] = '\0';
			      strcpy (filename[j], filename[j + 1]);
			      filename[j][strlen(filename[j + 1])] = '\0';
			      strcpy (filename[j + 1], temp);
			      filename[j + 1][strlen(temp)] = '\0';
		      
		      }
	      
	      }
	for (i = 0; i < count; i++) {
	
		display (flag_param, filename[i]);
	
	}

	closedir (dir);

	//若命令行没有 -l 选项，打印换行符
	if ((flag_param & PARAM_L) == 0) {
	
		printf ("\n");
	
	}

}
