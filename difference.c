# include "stdio.h"
# define N 100

int main() {

	char s[N],f;
	int i, t, a = 0, b = 0, c = 0, d = 0, e = 0;
	printf("请输入字符串：");
	gets(s);
	for(i = 0; i < N; i++) {

		f = s[i];
		if(f != '\0') {

			if(f <= 'z' && f >= 'a')
			a++;
        		else if(f <= 'Z' && f >= 'A')
        		b++;
       			else if(f <= '9' && f >= '0')
        		c++;
         		else if(f == ' ')
           		d++;
          		else
            		e++;
    		}
   		else
     			break;
	}
  	printf("字符串中小写字母为%d个，大写字母为%d个，数字为%d个，空格为%d个，其它字符为%d个。\n", a, b, c, d, e);

	return 0;

}
