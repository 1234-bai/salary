#ifndef ID_H_INCLUDED
#define ID_H_INCLUDED

///���ļ�����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

typedef struct ID
{
   int acc;
   char code[100];
}id;

///�ж�filename���Ƿ���Ҫ��Ľṹ��
int id_in_filename(id * t,const char * filename)    ///����ֵΪ1��ʾ�鵽�ˣ�-1��ʾ�鵽�ˣ������벻��ȷ��0��ʾû�в鵽
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

///ע�᣺��idд���ļ���
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
