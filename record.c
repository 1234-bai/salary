#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"

int recordfile_is_null(const char * recordfilename)
{
    FILE * fp=fopen(recordfilename,"rb");
    char ch=fgetc(fp);
    if(ch==EOF)
    {
        fclose(fp);
        return 1;
    }
    return 0;
}

Record * create_recordlist(Record *st)     ///创造链表头
{
    Record * head=(Record *)malloc(sizeof(Record));
    *head=*st;
    head->next=NULL;
    return head;
}

int judge_record(Record * p3,Record *p2,int rule)     ///排序时不同的排法
{
    if(rule==1)
    {
        if(p3->year!=p2->year)
            return p3->year < p2->year;      ///按月份
        else
        {
            if(p3->month!=p2->month)
                return p3->month < p2->month;
        }
    }                        ///rule是正数为从小到大排，是负数为从大到小排
    else if(rule==-1)
    {
        if(p3->year!=p2->year)
            return p3->year > p2->year;      ///按月份
        else
        {
            if(p3->month!=p2->month)
                return p3->month < p2->month;
        }
    }
    return -1;
}

Record * insert_recordlist(Record * head,Record *st)    ///增加人员（录入人员）
{
    Record * p=(Record *)malloc(sizeof(Record));
    *p=*st;
    p->next=NULL;
    if(judge_record(p,head,1))
    {
        p->next=head;
        head=p;
    }
    else
    {
        Record * p1=head;
        while(p1->next!=NULL && judge_record(p1->next,p,1))
        {
            p1=p1->next;
        }
        p->next=p1->next;
        p1->next=p;
    }
    return head;
}

Record * recordtail_insert(Record * tail,Record * st)
{
    Record * p=(Record *)malloc(sizeof(Record));
    *p=*st;
    p->next=NULL;
    tail->next=p;
    return p;
}

Record * add_record(Record * head,int year,int month,long long salary)
{
    Record re= {year,month,salary,NULL};
    Record * p=&re;
    if(head==NULL)
        head=create_recordlist(p);     ///传入的head为null，说明没有链表
    else
        head=insert_recordlist(head,p);
    return head;    ///head不会为null
}

Record * change_salary(Record * head,int year,int month,long long salary)
{
    Record * p=head;
    while(p!=NULL)
    {
        if(p->month==month && p->year==year)
        {
            p->salary=salary;
            break;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        head=add_record(head,year,month,salary);
    }
    return head;
}

Record * recordfile_to_list(const char * recordfilename)
{
    if(recordfile_is_null(recordfilename))
        return NULL;
    FILE * fp=fopen(recordfilename,"rb");
    Record * head=NULL;
    Record *tail=head;
    Record * p=(Record *)malloc(sizeof(Record));
    while(fread(p,sizeof(Record),1,fp)== 1 )
    {
        if(head==NULL)
        {
            head=create_recordlist(p);
            tail=head;
        }
        else
        {
            tail=recordtail_insert(tail,p);
        }
    }
    free(p);
    fclose(fp);
    return head;
}

void list_to_recordfile(const char * recordfilename,Record * head)
{
    FILE * fp=fopen(recordfilename,"wb");
    Record * p = head;
    while(p!=NULL)
    {
        fwrite(p,sizeof(Record),1,fp);
        p=p->next;
    }
    fclose(fp);
}

void displayrecord(Record *p)    ///将结点在屏幕上打印出来
{
    printf("\n%6d%5d%10lld\n",p->year,p->month,p->salary);
}

void display_recordlist(Record * head)
{
    long long salary=0;
    printf("\n***********************************************************************************\n");
    printf("\n    年   月    月支出\n");
    Record * p=head;
    while(p!=NULL)
    {
        salary+=p->salary;
        displayrecord(p);
        p=p->next;
    }
    printf("\n***************************本年总支出为：%lld(单位：元)****************************\n",salary);
    printf("\n***********************************************************************************\n");
}

/**以下为提取链表的一部分**/
/***************************************************************************/

Record* draw_recordpart(Record* head,int year)/*,Record **a)*/
{
    //int k=0;
    Record * p=head;
    while(p!=NULL)
    {
        if(p->year==year)
            break;
        p=p->next;
    }
    if(p!=NULL)
    {
        Record * head2=create_recordlist(p);
        //a[k++]=p;
        Record * tail=head2;
        p=p->next;
        while(p!=NULL)
        {
            if(p->year==year)
            {
                tail=recordtail_insert(tail,p);
                //a[k++]=p;
            }
            p=p->next;
        }
        return head2;
    }
    else
        return NULL;
}

void delete_recordlist(Record *head)     ///删除链表
{
    Record* p=head->next;
    while(p!=NULL)
    {
        free(head);
        head=p;
        p=p->next;
    }
    free(head);
    head=NULL;
}

