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
    printf("\n-------------------ɾ����Ա--------------------------------------\n");
    printf("\n������ɾ����Ա��������");
    char del_name[30]= {0};
    gets(del_name);
    STU *ptr = L->next;
    STU * pre = L;
    while (ptr != NULL)///ѭ������
    {
        if (strcmp(ptr->name,del_name) == 0)
        {
            temp=1;
            printf("\n...ɾ����ϵ����Ŀ...\n");
            printf("\n     ���    ����           �绰    ���    �·�     ��н  ��Ч����  �ܹ���  ˰����\n");
            display(ptr);
            printf("\nȷ��ɾ����\n");
            printf("\n1����  0����\n");
            char input=input_char();
            while (input != '1' && input != '0')
            {
                printf("\n��Ч���������������룺");
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
        ptr = ptr->next;//������
        pre = pre->next;
    }
    pre=L;
    if(strcmp(pre->name, del_name) == 0)///����ͷɾ��
    {
        temp=1;
        printf("\n...ɾ����ϵ����Ŀ...\n");
        printf("\n     ���    ����           �绰    ���    �·�     ��н  ��Ч����  �ܹ���  ˰����\n");
        display(ptr);
        printf("\nȷ��ɾ����\n");
        printf("\n1����  0����\n");
        char input=input_char();
        while (input != '1' && input != '0')
        {
            printf("\n��Ч���������������룺");
            input=input_char();
        }
        if (input == 'y')
        {
            L=L->next;	///����ͷ��ǰ�ƶ�
            free(pre);
        }
    }
    if(!temp) printf("\n�������޴��˻���ɾ��\n");
    printf("\n------------------------------------------------------------------\n");
    return L;
}

void modify(STU * l) //�޸�
{
    STU *p;
    if(!l)
        printf("/n------û����Ϣ���޸�-------/n");
    printf("������Ҫ�޸ĵ���Ա��ţ�");
    int id=string_to_number();
    p=search_id(l,id);
    if(p) change_the_node(p,0);
    else
        {qingping();printf("\n�������޴��˻���ɾ��\n");}
}

#endif // CHANGE_DELETE_H_INCLUDED
