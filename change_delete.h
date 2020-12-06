#ifndef CHANGE_DELETE_H_INCLUDED
#define CHANGE_DELETE_H_INCLUDED

#include "struct.h"
#include "input.h"
#include <string.h>
#include <stdio.h>

STU * search_id(STU *head,int id);
void change_the_node(STU *,int);
void display(STU * p);
void qingping();
void qingping2();

STU * delete_struct(STU * L)
{
    int temp=0;
    printf("\n-------------------删除人员--------------------------------------\n");
    printf("\n请输入删除人员的姓名：");
    char del_name[30]= {0};
    gets(del_name);
    STU *ptr = L->next;
    STU * pre = L;
    while (ptr != NULL)///循环查找
    {
        if (strcmp(ptr->name,del_name) == 0)
        {
            temp=1;
            printf("\n...删除联系人条目...\n");
            printf("\n     编号    姓名           电话    年份    月份     底薪  绩效工资  总工资  税后工资\n");
            display(ptr);
            printf("\n确认删除吗？\n");
            printf("\n1：是  0：否\n");
            char input=input_char();
            while (input != '1' && input != '0')
            {
                printf("\n无效操作，请重新输入：");
                input=input_char();
            }
            if (input == '0')
            {
                ptr = ptr->next;
                pre = pre->next;
                continue;
            }
            else if (input == '1')
            {
                pre->next = ptr->next;
                free(ptr);
                ptr = pre->next;
                continue;
            }
        }
        ptr = ptr->next;//往后推
        pre = pre->next;
    }
    pre=L;
    if(strcmp(pre->name, del_name) == 0)///链表头删除
    {
        temp=1;
        printf("\n...删除联系人条目...\n");
        printf("\n     编号    姓名           电话    年份    月份     底薪  绩效工资  总工资  税后工资\n");
        display(ptr);
        printf("\n确认删除吗？\n");
        printf("\n1：是  0：否\n");
        char input=input_char();
        while (input != '1' && input != '0')
        {
            printf("\n无效操作，请重新输入：");
            input=input_char();
        }
        if (input == 'y')
        {
            L=L->next;	///链表头向前移动
            free(pre);
        }
    }
    if(!temp) printf("\n数据中无此人或已删除\n");
    printf("\n------------------------------------------------------------------\n");
    return L;
}

void modify(STU * l) //修改
{
    STU *p;
    if(!l)
        printf("/n------没有信息可修改-------/n");
    printf("请输入要修改的人员编号：");
    int id=string_to_number();
    p=search_id(l,id);
    if(p) change_the_node(p,0);
    else
        {qingping();printf("\n数据中无此人或已删除\n");}
}

#endif // CHANGE_DELETE_H_INCLUDED
