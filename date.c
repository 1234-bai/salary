#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "date.h"

Date * get_nowdate()
{
    time_t ti=time(NULL);
    struct tm ptr=*(localtime(&ti));
    Date *p=(Date * )malloc(sizeof(Date));
    p->month=ptr.tm_mon+1;///******************记得改成正确计算的月份：ptr.tm_mon+1；*******************/
    p->year=ptr.tm_year+1900;
    p->next=NULL;
    return p;
}

///将日期添加到文件里
void add_date_to_filename(const char * filename,Date * t)
{
    FILE * fp=fopen(filename,"ab");
    fwrite(t,sizeof(Date),1,fp);
    fclose(fp);
}

int datefile_is_null(const char * filename)
{
    FILE * fp=fopen(filename,"rb");
    char ch=fgetc(fp);
    if(ch==EOF)
    {
        fclose(fp);
        return 1;
    }
    return 0;
}

Date * create_datelist(Date *st)     ///创造链表头
{
    Date * head=(Date *)malloc(sizeof(Date));
    //Datecopy(head,st);
    *head=*st;
    head->next=NULL;
    return head;
}

Date * date_tail_insert(Date * tail,Date * st)
{
    Date * p=(Date *)malloc(sizeof(Date));
    *p=*st;
    p->next=NULL;
    tail->next=p;
    return p;
}

Date * datefile_to_list(const char * filename)
{
    if(datefile_is_null(filename))
        return NULL;
    FILE * fp=fopen(filename,"rb");
    Date * head=NULL;
    Date *tail=head;
    Date * p=(Date *)malloc(sizeof(Date));
    while(fread(p,sizeof(Date),1,fp)== 1 )
    {
        if(head==NULL)
        {
            head=create_datelist(p);
            tail=head;
        }
        else
        {
            tail=date_tail_insert(tail,p);
        }
    }
    free(p);
    fclose(fp);
    return head;
}

void date_to_string(char * str,Date * da)
{
    char str1[20]= {0};
    sprintf(str,"%04d",da->year);
    sprintf(str1,"%02d.txt",da->month);
    strcat(str,str1);
}

///判断filename里是否有要查的结构体
int date_in_filename(Date * t,const char * filename)    ///返回值为1表示查到了，0表示没有查到
{
    FILE * fp=fopen(filename,"rb");
    Date * p=(Date *)malloc(sizeof(Date));
    while(fread(p,sizeof(Date),1,fp)==1)
    {
        if(t->year == p->year && t->month==p->month)
        {
            free(p);
            fclose(fp);
            return 1;

        }
    }
    free(p);
    fclose(fp);
    return 0;
}

///尾插法
Date * tail_dateinsert(Date * tail,Date * st)
{
    Date * p=(Date *)malloc(sizeof(Date));
    *p=*st;
    p->next=NULL;
    tail->next=p;
    return p;
}

int ruleee(Date *p,int year1,int month1,int year2,int month2)
{
    return (p->year >= year1 && p->month >= month1)&&(p->year <= year2 && p->month <= month2);
}

Date* drawdate_part(Date *head,int year1,int month1,int year2,int month2)/*,Date **a)*/   ///根据不同的规则，进行不同的提取,返回NULL则提取失败
{
    //int k=0;
    Date * p=head;
    while(p!=NULL)
    {
        if(ruleee(p,year1,month1,year2,month2));
            break;
        p=p->next;
    }
    if(p!=NULL)
    {
        Date * head2=create_datelist(p);
        //a[k++]=p;
        Date * tail=head2;
        p=p->next;
        while(p!=NULL)
        {
            if(ruleee(p,year1,month1,year2,month2))
            {
                tail=tail_dateinsert(tail,p);
                //a[k++]=p;
            }
            p=p->next;
        }
        return head2;
    }
    else
        return NULL;
}

/*int length_datelist(Date * head)     ///求长度
{
    int k=0;
    Date * p=head;
    while(p!=NULL)
    {
        k++;
        p=p->next;
    }
    return k;
}*/

/** \brief 我的思路是准备一个文件，里面储存的都是日期，也就是表示不同的文件
 *查询时，根据年份调用不同的文件（可能会利用到抽取链表的一部分），将数字转化成字符串
 * \param 用到的函数有，更新文件，从文件中生成链表，遍历链表时将结构体内容装化成字符串（可用文件名）
 * \param
 * \return
 *
 */
