/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Thu Apr  7 02:09:03 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 1000
void rmnull();
void adddou();

void adddou(){
        FILE *fp,*sp;
        char buf[200];
        fp = fopen("/root/lr75106/socket/temp.txt", "r");//打开文件
        sp = fopen("/root/lr75106/socket/addou","wb");
        while(fgets(buf, sizeof(buf), fp))//每次读取一行数据，直到读取失败。
        {
            fputs(",",sp);
            fprintf(sp,"%s", buf); //打印该行。
        }
        fclose(fp);//关闭文件
        fclose(sp);
}

void rmnull()
{

    char s[maxn];
    FILE *p;
        p=fopen("/root/lr75106/socket/addou","rb");//in.txt是待处理文件名，包含后缀
        fscanf(p,"%[^#]",s);//#代表待处理文件中不存的字符
        fclose(p);
        int i=0,j=0;
    for(i=0;i<strlen(s);i++){
                if(s[i]==' ' || s[i]=='\n') continue;//删除空格和回车
                s[j++]=s[i];
            
    }
        s[j]=0;//0即 NULL
        p=fopen("/root/lr75106/socket/rmnull","wb");//新建一个in2.txt文件
        fprintf(p,"%s",s);//处理后的文件放在in2.txt中
        fclose(p);
}
