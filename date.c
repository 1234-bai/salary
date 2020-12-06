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
    p->month=ptr.tm_mon+1;///******************�ǵøĳ���ȷ������·ݣ�ptr.tm_mon+1��*******************/
    p->year=ptr.tm_year+1900;
    p->next=NULL;
    return p;
}

///��������ӵ��ļ���
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

Date * create_datelist(Date *st)     ///��������ͷ
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

///�ж�filename���Ƿ���Ҫ��Ľṹ��
int date_in_filename(Date * t,const char * filename)    ///����ֵΪ1��ʾ�鵽�ˣ�0��ʾû�в鵽
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

///β�巨
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

Date* drawdate_part(Date *head,int year1,int month1,int year2,int month2)/*,Date **a)*/   ///���ݲ�ͬ�Ĺ��򣬽��в�ͬ����ȡ,����NULL����ȡʧ��
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

/*int length_datelist(Date * head)     ///�󳤶�
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

/** \brief �ҵ�˼·��׼��һ���ļ������洢��Ķ������ڣ�Ҳ���Ǳ�ʾ��ͬ���ļ�
 *��ѯʱ��������ݵ��ò�ͬ���ļ������ܻ����õ���ȡ�����һ���֣���������ת�����ַ���
 * \param �õ��ĺ����У������ļ������ļ�������������������ʱ���ṹ������װ�����ַ����������ļ�����
 * \param
 * \return
 *
 */
