#include "search.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*STU * tail_insert(STU * tail,STU * st);
STU * create_list(STU *st);*/

/**����Ϊ����������Ĳ��������õ���ͬ˳�������**/
/***************************************************************************/

void swap_struct(STU * p1,STU *p3)  ///�����������ṹ��Ľ���
{
    STU *temp=(STU *)malloc(sizeof(STU));
    *temp=*p1;
    *p1=*p3;
    *p3=*temp;
    STU *te=p1->next;
    p1->next=p3->next;
    p3->next=te;
    free(temp);
}

int judge_struct(STU * p3,STU *p2,int rule)     ///����ʱ��ͬ���ŷ�
{
    if(rule==2)
    {
        if(p3->basic_salary != p2->basic_salary)
            return (p3->basic_salary < p2->basic_salary);      ///����н
        else
            return p3->id < p2->id;
    }
    else if(rule==3)
    {
        if(p3->salary_per!=p2->salary_per)
            return p3->salary_per < p2->salary_per;      ///����Ч
        else
            return p3->id < p2->id;
    }
    else if(rule==4)
    {
        if(p3->total_salary!=p2->total_salary)
            return p3->total_salary < p2->total_salary;      ///���ܹ��ʣ�˰���ʣ�
        else
            return p3->id < p2->id;
    }                           ///rule������Ϊ��С�����ţ��Ǹ���Ϊ�Ӵ�С��
    else if(rule==-2)
    {
        if(p3->basic_salary != p2->basic_salary)
            return (p3->basic_salary > p2->basic_salary);      ///����н
        else
            return p3->id < p2->id;
    }
    else if(rule==-3)
    {
        if(p3->salary_per!=p2->salary_per)
            return p3->salary_per > p2->salary_per;      ///����Ч
        else
            return p3->id < p2->id;
    }
    else if(rule==-4)
    {
        if(p3->total_salary!=p2->total_salary)
            return p3->total_salary > p2->total_salary;      ///���ܹ��ʣ�˰���ʣ�
        else
            return p3->id < p2->id;
    }
    else
        return -1;
}

void sort_list(STU *head,int rule)  ///�������ɲ�ͬ������
{
    STU * p1=head;
    while(p1!=NULL)
    {
        STU * p3=p1;
        STU * p2=p1->next;
        while(p2!=NULL)
        {
            if(judge_struct(p2,p3,rule))
                p3=p2;
            p2=p2->next;
        }
        if(p3!=p1)
            swap_struct(p1,p3);
        p1=p1->next;
    }
}

STU * reverse_list(STU * head)      ///��������ţ�������ŴӴ�С��
{
    STU *p1=head->next;
    head->next=NULL;
    while(p1!=NULL)
    {
        STU *p2=p1->next;
        p1->next=head;
        head=p1;
        p1=p2;
    }
    return head;
}

/**����Ϊ��ȡ�����һ����**/
/***************************************************************************/

STU * search_id(STU * head,int id)  ///���ձ�Ų���ĳ�����
{
    STU *p=head;
    while(p!=NULL && p->id != id)
    {
        p=p->next;
    }
    return p;     ///�鲻������NULL�����򷵻�ָ���Ǹ��ṹ���ָ��
}

long long totaloflist(STU * head)     ///����Ա�ܹ���
{
    long long k=0;
    STU * p=head;
    while(p!=NULL)
    {
        k+=p->total_salary;
        p=p->next;
    }
    return k;
}

///��ݲ����ݲ���ѡ��rule��-12~-1֮�����˼���·ݣ����·�Ϊ��ͬ�Ĺ��򣩣���-24~-13Ϊ��ͬ�Ĺ���������Ϊ��ţ����Ϊ����
int draw_rule(STU * p,int rule)     ///��ȡʱ��ѭ�Ĺ���Ҫ��
{
    if(rule==-13)
        return (p->basic_salary < 6000);
    else if(rule==-14)
        return (p->basic_salary  >= 6000)&&(p->basic_salary  < 10000);
    else if(rule==-15)
        return (p->basic_salary  >= 10000);
    else if(rule==-16)
        return (p->salary_per < 6000);
    else if(rule==-17)
        return (p->salary_per >= 6000)&&(p->salary_per < 10000);
    else if(rule==-18)
        return (p->salary_per >= 10000);
    else if(rule==-19)
        return (p->total_salary < 6000);
    else if(rule==-20)
        return (p->total_salary >= 6000)&&(p->total_salary < 10000);
    else if(rule==-21)
        return (p->total_salary >= 10000);
    else if(rule==-22)
        return (p->final_salary < 6000);
    else if(rule==-23)
        return (p->final_salary >= 6000)&&(p->final_salary < 10000);
    else if(rule==-24)
        return (p->final_salary >= 10000);
    else
        return -1;
}

///aΪ�����������ָ�룬ruleΪ��ͬ�Ĺ���һ�ж��ǰ��չ��򽫽����ȡ������
///��Ϊ�Ƕ��Ѿ�����һ�������ź�������������ȡ����ȡ��������������һ���֣�����ʹ��β�巨�γ��������Զ�ӵ�еڶ������׼
STU* draw_part(STU* head,int rule)/*,STU **a)*/   ///���ݲ�ͬ�Ĺ��򣬽��в�ͬ����ȡ,����NULL����ȡʧ��
{
    //int k=0;
    STU * p=head;
    while(p!=NULL)
    {
        if(draw_rule(p,rule))
            break;
        p=p->next;
    }
    if(p!=NULL)
    {
        STU * head2=create_list(p);
        //a[k++]=p;
        STU * tail=head2;
        p=p->next;
        while(p!=NULL)
        {
            if(draw_rule(p,rule))
            {
                tail=tail_insert(tail,p);
                //a[k++]=p;
            }
            p=p->next;
        }
        return head2;
    }
    else
        return NULL;
}

/**����Ϊ��ӡ����**/
/***************************************************************************/

void display(STU *p)    ///���������Ļ�ϴ�ӡ����
{
    printf("%9d%8s%15s",p->id,p->name,p->phone);
    printf("%9d%7d%9d%10d%9d%10d\n",p->year,p->month,p->basic_salary,p->salary_per,p->total_salary,p->final_salary);
}

void display_list(STU * head)
{
    printf("\n*****************************************************************************************************\n");
    printf("\n     ���    ����           �绰     ���   �·�     ��н  ��Ч����   �ܹ���  ˰����\n");
    STU * p=head;
    while(p!=NULL)
    {
        display(p);
        p=p->next;
    }
    printf("\n*****************************************************************************************************\n");
}
