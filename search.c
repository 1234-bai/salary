#include "search.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*STU * tail_insert(STU * tail,STU * st);
STU * create_list(STU *st);*/

/**以下为对整个链表的操作，来得到不同顺序的链表**/
/***************************************************************************/

void swap_struct(STU * p1,STU *p3)  ///链表中两个结构体的交换
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

int judge_struct(STU * p3,STU *p2,int rule)     ///排序时不同的排法
{
    if(rule==2)
    {
        if(p3->basic_salary != p2->basic_salary)
            return (p3->basic_salary < p2->basic_salary);      ///按底薪
        else
            return p3->id < p2->id;
    }
    else if(rule==3)
    {
        if(p3->salary_per!=p2->salary_per)
            return p3->salary_per < p2->salary_per;      ///按绩效
        else
            return p3->id < p2->id;
    }
    else if(rule==4)
    {
        if(p3->total_salary!=p2->total_salary)
            return p3->total_salary < p2->total_salary;      ///按总工资（税后工资）
        else
            return p3->id < p2->id;
    }                           ///rule是正数为从小到大排，是负数为从大到小排
    else if(rule==-2)
    {
        if(p3->basic_salary != p2->basic_salary)
            return (p3->basic_salary > p2->basic_salary);      ///按底薪
        else
            return p3->id < p2->id;
    }
    else if(rule==-3)
    {
        if(p3->salary_per!=p2->salary_per)
            return p3->salary_per > p2->salary_per;      ///按绩效
        else
            return p3->id < p2->id;
    }
    else if(rule==-4)
    {
        if(p3->total_salary!=p2->total_salary)
            return p3->total_salary > p2->total_salary;      ///按总工资（税后工资）
        else
            return p3->id < p2->id;
    }
    else
        return -1;
}

void sort_list(STU *head,int rule)  ///排序，生成不同的链表
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

STU * reverse_list(STU * head)      ///链表的逆排，即按编号从大到小排
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

/**以下为提取链表的一部分**/
/***************************************************************************/

STU * search_id(STU * head,int id)  ///按照编号查找某个结点
{
    STU *p=head;
    while(p!=NULL && p->id != id)
    {
        p=p->next;
    }
    return p;     ///查不到返回NULL，否则返回指向那个结构体的指针
}

long long totaloflist(STU * head)     ///求人员总工资
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

///年份不根据参数选择，rule在-12~-1之间的意思是月份（即月份为不同的规则），在-24~-13为不同的规则，其余则为编号（编号为正）
int draw_rule(STU * p,int rule)     ///提取时遵循的规则（要求）
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

///a为储存各个结点的指针，rule为不同的规则，一切都是按照规则将结果提取出来。
///因为是对已经按照一定规则排好序的链表进行提取，提取的是链表连续的一部分，所以使用尾插法形成新链表，自动拥有第二排序标准
STU* draw_part(STU* head,int rule)/*,STU **a)*/   ///根据不同的规则，进行不同的提取,返回NULL则提取失败
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

/**以下为打印链表**/
/***************************************************************************/

void display(STU *p)    ///将结点在屏幕上打印出来
{
    printf("%9d%8s%15s",p->id,p->name,p->phone);
    printf("%9d%7d%9d%10d%9d%10d\n",p->year,p->month,p->basic_salary,p->salary_per,p->total_salary,p->final_salary);
}

void display_list(STU * head)
{
    printf("\n*****************************************************************************************************\n");
    printf("\n     编号    姓名           电话     年份   月份     底薪  绩效工资   总工资  税后工资\n");
    STU * p=head;
    while(p!=NULL)
    {
        display(p);
        p=p->next;
    }
    printf("\n*****************************************************************************************************\n");
}
