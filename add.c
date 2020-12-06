#include "add.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double tax_rate=0.03;
void qingping();
void qingping2();

///����Ҫ¼��Ľṹ�壬���������Ϊ-1�Ļ����ͷ���null����ʾ¼�����
STU * create_STU(int year,int month)
{
    int number[3];
    char name[NAME_LENGTH]= {0};
    char phone[PHONE_LENGTH]= {0};
    char *s[2]= {name,phone};
    char *p1[2]= {"���������֣�","������绰���룺"};
    char *p2[3]= {"\n�������ţ�","�������н��","�����뼨Ч���ʣ�"};
    for(int i=0; i<3; i++)
    {
        printf("%s",p2[i]);
        number[i]=(i==0) ? input_id() : string_to_number();
        if(number[i]==-1)///�ж�¼�����
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
    printf("¼����");
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

/*void stucopy(STU *p,STU *st)   //�ṹ�帴�ƺ���
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

///�����������Ϊnull
STU * create_list(STU *st)     ///��������ͷ
{
    STU * head=(STU *)malloc(sizeof(STU));
    //stucopy(head,st);
    *head=*st;
    head->next=NULL;
    return head;
}

///�˴��������null�Ļ�˵��¼����Ա����ظ�������
STU * insert_list(STU * head,STU *st)    ///������Ա��¼����Ա��
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
        return NULL;    ///����null�ͳ�����
    }
    else
    {
        STU * p1=head;
        while(p1->next!=NULL && (p1->next->id)<(p->id))
        {
            p1=p1->next;
        }
        if(p1->next != NULL && (p1->next->id)==(p->id))
            return NULL;    //����null�ͳ�����
        p->next=p1->next;
        p1->next=p;
    }
    return head;
}

///����¼��
///��Ҫ�ٴηֳ������������null������¼������null��ǰ�߷���null�����߷���ͷָ�����¼��
///head�������ɵ�����
STU * add_people(STU * head,int year,int month)
{
    STU * p=create_STU(year,month);   ///p���Ϊnull�Ļ�����Ϊ¼�����
    if(p==NULL)
        return NULL;    ///������¼������������ų�����ˣ�˵Ŀ���
    if(head==NULL)
        head=create_list(p);     ///�����headΪnull��˵��û������
    else
    {
        STU * p1=insert_list(head,p);
        if(p1==NULL)
            printf("¼��ʧ�ܣ�����Ա����¼����Ա����ظ���������¼��R�n�Q\n");
        else
            head=p1;
    }
    return head;    ///head����Ϊnull
}

void change_the_node(STU * st,int rule)
{
    while(1)
    {
        printf("\n     ���    ����           �绰     ��н  ��Ч����  �ܹ���  ˰����\n");
        printf("%9d%8s%15s",st->id,st->name,st->phone);
        printf("%9d%9d%9d%9d\n",st->basic_salary,st->salary_per,st->total_salary,st->final_salary);
        printf("\n\t\t\t1���޸�����\n");
        printf("\t\t\t2���޸ĵ绰\n");
        printf("\t\t\t3���޸ĵ�н\n");
        printf("\t\t\t4���޸ļ�Ч\n");
        if(rule==1)
        {
            printf("\t\t\t5��ɾ��������Ϣ\n");
            printf("\t\t\t0�����ٸı�\n");
        }
        else printf("\t\t\t0���˳�\n");
        printf("��ѡ�������");
        char t=input_char();
        if(t=='0')
            break;
        else if(t=='1')
        {
            printf("\n�������޸ĺ��������");
            char name[NAME_LENGTH]= {0};
            gets(name);
            strcpy(st->name,name);
            qingping();
            printf("�޸ĳɹ����R�بQ\n");
        }
        else if(t=='2')
        {
            printf("\n�������޸ĺ�ĵ绰��");
            char phone[PHONE_LENGTH]= {0};
            input_stringnumber(phone);
            strcpy(st->phone,phone);
            qingping();
            printf("�޸ĳɹ����R�بQ\n");
        }
        else if(t=='3')
        {
            printf("\n�������޸ĺ�ĵ�н��");
            int salary=string_to_number();
            st->basic_salary=salary;
            qingping();
            printf("�޸ĳɹ����R�بQ\n");
        }
        else if(t=='4')
        {
            printf("\n�������޸ĺ�ļ�Ч��");
            int salary=string_to_number();
            st->salary_per=salary;
            qingping();
            printf("�޸ĳɹ����R�بQ\n");
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
            printf("\n��Ч����������������R�n�Q\n");
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

///���ڳ���¼���Ժ��¼��
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
            head=create_list(p);     ///�����headΪnull��˵��û������
        else
        {
            STU * p1=insert_list(head,p);
            if(p1==NULL)
                printf("¼��ʧ�ܣ�����Ա����¼����Ա����ظ���������¼��R�n�Q\n");
            else
                head=p1;
        }
    }
    return head;    ///head����Ϊnull
}

/**����Ϊ�����������йصĺ���**/
/***************************************************************************/

///β�巨
STU * tail_insert(STU * tail,STU * st)
{
    STU * p=(STU *)malloc(sizeof(STU));
    *p=*st;
    p->next=NULL;
    tail->next=p;
    return p;
}

void delete_list(STU *head)     ///ɾ������
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

/**����Ϊ������ļ�����ϵ**/
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
