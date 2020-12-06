#include "add.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double tax_rate=0.03;
void qingping();
void qingping2();

///创造要录入的结构体，如果输入编号为-1的话，就返回null，表示录入结束
STU * create_STU(int year,int month)
{
    int number[3];
    char name[NAME_LENGTH]= {0};
    char phone[PHONE_LENGTH]= {0};
    char *s[2]= {name,phone};
    char *p1[2]= {"请输入名字：","请输入电话号码："};
    char *p2[3]= {"\n请输入编号：","请输入底薪：","请输入绩效工资："};
    for(int i=0; i<3; i++)
    {
        printf("%s",p2[i]);
        number[i]=(i==0) ? input_id() : string_to_number();
        if(number[i]==-1)///判断录入结束
        {
            qingping();
            return NULL;
        }
        if(i==0)
        {
            for(int j=0; j<2; j++)
            {
                printf("%s",p1[j]);
                if(j==0)
                    gets(name);
                else
                    input_stringnumber(phone);
            }
        }
    }
    printf("录入中");
    qingping2();
    STU *p=(STU *)malloc(sizeof(STU));
    p-> month=month;
    p-> year=year;
    p->id=number[0];
    strcpy(p->name,s[0]);
    strcpy(p->phone,s[1]);
    p->basic_salary=number[1];
    p->salary_per=number[2];
    p->total_salary=p->basic_salary+p->salary_per;
    if(p->total_salary>5000)p->final_salary=p->total_salary - (p->total_salary-5000)*tax_rate;
    else p->final_salary=p->total_salary;
    p->next=NULL;
    return p;
}

/*void stucopy(STU *p,STU *st)   //结构体复制函数
{
    p->id=st->id;
    strcpy(p->name,st->name);
    strcpy(p->level,st->level);
    strcpy(p->phone,st->phone);
    strcpy(p->address,st->address);
    p->work_age=st->work_age;
    p->salary_age=st->salary_age;
    p->salary_house=st->salary_house;
    p->basic_salary=st->basic_salary;
    p->total_salary=st->total_salary;
    p->final_salary=st->final_salary;
    p->next=NULL;
}*/

///传入参数不会为null
STU * create_list(STU *st)     ///创造链表头
{
    STU * head=(STU *)malloc(sizeof(STU));
    //stucopy(head,st);
    *head=*st;
    head->next=NULL;
    return head;
}

///此处如果返回null的话说明录入人员编号重复，出错
STU * insert_list(STU * head,STU *st)    ///增加人员（录入人员）
{
    STU * p=(STU *)malloc(sizeof(STU));
    //stucopy(p,st);
    *p=*st;
    p->next=NULL;
    if(p->id < head->id)
    {
        p->next=head;
        head=p;
    }
    else if(p->id == head-> id)
    {
        return NULL;    ///返回null就出错啦
    }
    else
    {
        STU * p1=head;
        while(p1->next!=NULL && (p1->next->id)<(p->id))
        {
            p1=p1->next;
        }
        if(p1->next != NULL && (p1->next->id)==(p->id))
            return NULL;    //返回null就出错了
        p->next=p1->next;
        p1->next=p;
    }
    return head;
}

///初次录入
///需要再次分出是输入结束的null，还是录入出错的null，前者返回null，后者返回头指针继续录入
///head是新生成的链表
STU * add_people(STU * head,int year,int month)
{
    STU * p=create_STU(year,month);   ///p如果为null的话，则为录入结束
    if(p==NULL)
        return NULL;    ///上来就录入结束，不能排除这种耍人的可能
    if(head==NULL)
        head=create_list(p);     ///传入的head为null，说明没有链表
    else
    {
        STU * p1=insert_list(head,p);
        if(p1==NULL)
            printf("录入失败，此人员与已录入人员编号重复，请重新录入≧﹏≦\n");
        else
            head=p1;
    }
    return head;    ///head不会为null
}

void change_the_node(STU * st,int rule)
{
    while(1)
    {
        printf("\n     编号    姓名           电话     底薪  绩效工资  总工资  税后工资\n");
        printf("%9d%8s%15s",st->id,st->name,st->phone);
        printf("%9d%9d%9d%9d\n",st->basic_salary,st->salary_per,st->total_salary,st->final_salary);
        printf("\n\t\t\t1：修改姓名\n");
        printf("\t\t\t2：修改电话\n");
        printf("\t\t\t3：修改底薪\n");
        printf("\t\t\t4：修改绩效\n");
        if(rule==1)
        {
            printf("\t\t\t5：删除此人信息\n");
            printf("\t\t\t0：不再改变\n");
        }
        else printf("\t\t\t0：退出\n");
        printf("请选择操作：");
        char t=input_char();
        if(t=='0')
            break;
        else if(t=='1')
        {
            printf("\n请输入修改后的姓名：");
            char name[NAME_LENGTH]= {0};
            gets(name);
            strcpy(st->name,name);
            qingping();
            printf("修改成功！≧ω≦\n");
        }
        else if(t=='2')
        {
            printf("\n请输入修改后的电话：");
            char phone[PHONE_LENGTH]= {0};
            input_stringnumber(phone);
            strcpy(st->phone,phone);
            qingping();
            printf("修改成功！≧ω≦\n");
        }
        else if(t=='3')
        {
            printf("\n请输入修改后的底薪：");
            int salary=string_to_number();
            st->basic_salary=salary;
            qingping();
            printf("修改成功！≧ω≦\n");
        }
        else if(t=='4')
        {
            printf("\n请输入修改后的绩效：");
            int salary=string_to_number();
            st->salary_per=salary;
            qingping();
            printf("修改成功！≧ω≦\n");
        }
        else if(t=='5')
        {
            free(st);
            st=NULL;
            break;
        }
        else
        {
            qingping();
            printf("\n无效操作，请重新输入≧﹏≦\n");
        }
        if(t=='4' || t=='3')
        {
            st->total_salary=st->basic_salary+st->salary_per;
            if(st->total_salary>5000)st->final_salary=st->total_salary - (st->total_salary-5000)*tax_rate;
            else st->final_salary=st->total_salary;
        }
    }
    qingping();
}

///用于初次录入以后的录入
STU * after_add_people(STU * head,int year,int month,STU * st)
{
    if(st==NULL)
        return head;
    STU * p=(STU *)malloc(sizeof(STU));
    *p=*st;
    p-> month=month;
    p-> year=year;
    change_the_node(p,1);
    if(p!=NULL)
    {
        if(head==NULL)
            head=create_list(p);     ///传入的head为null，说明没有链表
        else
        {
            STU * p1=insert_list(head,p);
            if(p1==NULL)
                printf("录入失败，此人员与已录入人员编号重复，请重新录入≧﹏≦\n");
            else
                head=p1;
        }
    }
    return head;    ///head不会为null
}

/**以下为和链表生成有关的函数**/
/***************************************************************************/

///尾插法
STU * tail_insert(STU * tail,STU * st)
{
    STU * p=(STU *)malloc(sizeof(STU));
    *p=*st;
    p->next=NULL;
    tail->next=p;
    return p;
}

void delete_list(STU *head)     ///删除链表
{
    if(head==NULL) return;
    STU* p=head->next;
    while(p!=NULL)
    {
        free(head);
        head=p;
        p=p->next;
    }
    free(head);
    head=NULL;
}

/**以下为链表和文件的联系**/
/***************************************************************************/

int file_is_null(const char * filename)
{
    FILE * fp=fopen(filename,"rb");
    if(fp==NULL)
    {
        return 1;
    }
    char ch=fgetc(fp);
    if(ch==EOF)
    {
        fclose(fp);
        return 1;
    }
    return 0;
}

STU * file_to_list(const char * filename)
{
    if(file_is_null(filename))
    {
        return NULL;
    }
    FILE * fp=fopen(filename,"rb");
    STU * head=NULL;
    STU *tail=head;
    STU * p=(STU *)malloc(sizeof(STU));
    while(fread(p,sizeof(STU),1,fp)== 1 )
    {
        if(head==NULL)
        {
            head=create_list(p);
            tail=head;
        }
        else
        {
            tail=tail_insert(tail,p);
        }
    }
    free(p);
    fclose(fp);
    return head;
}

void list_to_file(const char * filename,STU * head)
{
    FILE * fp=fopen(filename,"wb");
    STU * p = head;
    while(p!=NULL)
    {
        fwrite(p,sizeof(STU),1,fp);
        p=p->next;
    }
    fclose(fp);
}

/*void struct_to_file(const char * filename,STU * st)
{
    FILE * fp=fopen(filename,"ab");
    fwrite(st,sizeof(STU),1,fp);
    fclose(fp);
}*/
