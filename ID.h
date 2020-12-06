#ifndef ID_H_INCLUDED
#define ID_H_INCLUDED

///此文件无误
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

typedef struct ID
{
   int acc;
   char code[100];
}id;

///判断filename里是否有要查的结构体
int id_in_filename(id * t,const char * filename)    ///返回值为1表示查到了，-1表示查到了，但密码不正确，0表示没有查到
{
    FILE * fp=fopen(filename,"r");
    id * p=(id *)malloc(sizeof(id));
    while(fread(p,sizeof(id),1,fp)==1){
        if(t->acc == p->acc){
            if(strcmp(t->code,p->code)==0){
                free(p);
                fclose(fp);
                return 1;
            }
            else {
                free(p);
                fclose(fp);
                return -1;
            }
        }
    }
    free(p);
    fclose(fp);
    return 0;
}

///注册：将id写到文件里
void add_id_to_filename(const char * filename,id * t)
{
    FILE * fp=fopen(filename,"a");
    fwrite(t,sizeof(id),1,fp);
    fclose(fp);
}

id * create_id()
{
    int ac;
    char a[100]={0};
    ac=scan_id(a);
    id * p=(id *)malloc(sizeof(id));
    p->acc=ac;
    strcpy(p->code,a);
    return p;
}

#endif // ID_H_INCLUDED
