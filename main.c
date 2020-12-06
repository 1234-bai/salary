#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ID.h"
#include "struct.h"
#include "add.h"
#include "search.h"
#include "back_recover.h"
#include "date.h"
#include "record.h"
#include "change_delete.h"

Date begin_date= {2020,4,NULL};
char nowdatefile[20]= {0};

void begin();
void end_display();
void qingping();
void qingping2();
int main()
{
    printf("\t  ********************************************\n");
    printf("\t  *                                          *\n");
    printf("\t  *             ���ʹ���ϵͳ                 *\n");
    printf("\t  *                                          *\n");
    printf("\t  ********************************************\n");
    //char m=0,n=7;
    //printf("��ֱ������������������ñ�����������ɫ��ǰ�߱�����������,Ĭ�Ϻڵװ��֣�:\n0=��ɫ 1=��ɫ 2=��ɫ 3=����ɫ 4=��ɫ 5=��ɫ 6=��ɫ 7=��ɫ 8=��ɫ 9=����ɫ\n");
    // scanf("%c%c",&a,&b);
    system("color a0");
    Date *nowdate=get_nowdate();
    date_to_string(nowdatefile,nowdate);
    begin();
    return 0;
}

/********************************************/
void sign_in(); ///��¼
void sign_up(); ///ע��
void begin()
{
    while(1)
    {
        printf("\n\t\t\t1����¼\n");
        printf("\t\t\t2��ע��\n");
        printf("\t\t\t0���˳�\n");
        printf("������������ţ�");
        char t=input_char();
        if(t=='1')
            sign_in();
        else if(t=='2')
            sign_up();
        else if(t=='0')
            break;
        else
        {
            qingping();
            printf("\n����һλ��ĸ��������������ʾһλ���֨R�n�Q\n");
        }
    }
}

/********************************************/
void sign_up() ///ע��
{

    id * p=create_id();
    qingping();
    while(1)
    {
        printf("\n\t\t\t1������Աע��\n");
        printf("\t\t\t2����ͨԱ��ע��\n");
        printf("\t\t\t0���˳�\n");
        printf("������������ţ�");
        char t=input_char();
        if(t=='1')
        {
            add_id_to_filename("id0faddmin.txt",p);
            break;
        }
        else if(t=='2')
        {
            add_id_to_filename("id0fstaff.txt",p);
            break;
        }
        else if(t=='0')
            break;
        else
        {
            qingping();
            printf("\n����һλ��ĸ��������������ʾһλ���֨R�n�Q\n");

        }
    }
    qingping();
}

/******************************************************/
void menu1();
void search_by_id(int id);
void sign_in()  ///��¼
{

    id * ip=create_id();
    qingping();
    int m=id_in_filename(ip,"id0faddmin.txt");
    if(m==1)
        menu1();   ///����Ա�˺ţ��������Ա����ѡ��
    else if(m==-1)      ///�ǹ���Ա�˺ţ������벻��ȷ
    {
        qingping();
        printf("\n�������벻��ȷ��������ѡ������R�n�Q\n");

    }
    else    ///���ǹ���Ա�˺�,�ж��Ƿ���Ա���˺�
    {
        m=id_in_filename(ip,"id0fstaff.txt");
        if(m==1)    ///Ա���˺�
        {
            printf("��ӭ����Ա��ϵͳ��������Ϊ������Ϣ��");
            for(long int i=0; i<500000000; i++);
            search_by_id(ip->acc); ///���������Ϣ
        }
        else if(m==-1)      ///��Ա���˺ţ������벻��ȷ
        {
            qingping();
            printf("\n�������벻��ȷ��������ѡ������R�n�Q\n");
        }
        else    ///����Ա���˺�
        {
            qingping();
            printf("\n�޴��˺ţ������²����R�n�Q\n");
        }
    }
}
/********************************************/
void search_by_id(int id)   ///���Ҵ��˺ŵ������Ϣ
{
    qingping();
    printf("\n******************************************************************************************************\n");
    long long salary=0;
    Date *dp=datefile_to_list("date.txt");
    int k1=0,k2=0;
    while(dp!=NULL)
    {
        k1++;
        char t[20]= {0};
        date_to_string(t,dp);
        STU * head=file_to_list(t);
        STU *sp=search_id(head,id);
        if(sp==NULL)      ///�������ļ���û�������
        {
            k2++;
        }
        else    ///������˵���Ϣ�����
        {
            salary+=sp->final_salary;
            printf("\n     ���    ����           �绰     ���   �·�     ��н  ��Ч����   �ܹ���  ˰����\n");
            display(sp);
        }
        delete_list(head);
        dp=dp->next;
    }
    if(k1==k2)  ///�ѱ�ȫ���ļ���û���������Ϣ��û������˵��ļ��������ļ�����ȣ�
        printf("\n�޴�����Ϣ�R�n�Q\n");
    else
    {
        printf("\n*******************************************�ܻ��Ϊ��%lld************************************************\n\n",salary);
        Date *dp2=datefile_to_list("date.txt");
        printf("�������ʼ���");
        int year1=string_to_number();
        printf("�������ʼ�·�");
        int month1=string_to_number();
        printf("������������");
        int year2=string_to_number();
        printf("����������·�");
        int month2=string_to_number();
        Date *dp3=drawdate_part(dp2,year1,month1,year2,month2);
        int k11=0,k22=0;
        long long salary1=0;
        while(dp3!=NULL)
        {
            k11++;
            char t[20]= {0};
            date_to_string(t,dp3);
            STU * head1=file_to_list(t);
            STU *sp1=search_id(head1,id);
            if(sp1==NULL)      ///�������ļ���û�������
            {
                k22++;
            }
            else    ///������˵���Ϣ�����
            {
                salary1+=sp1->final_salary;
                printf("\n     ���    ����           �绰     ���   �·�     ��н  ��Ч����   �ܹ���  ˰����\n");
                display(sp1);
            }
            delete_list(head1);
            dp3=dp3->next;
        }
        if(k11==k22)  ///�ѱ�ȫ���ļ���û���������Ϣ��û������˵��ļ��������ļ�����ȣ�
            printf("\n�����ݨR�n�Q\n");
        else
        {
            printf("\n*******************************************�ܻ��Ϊ��%lld************************************************\n",salary1);
        }
    }
    end_display();
}
/********************************************/
void adds();    ///�����Ա����
void change();  ///�޸���Ա
void deletes(); ///ɾ����Ա
void countpeople();     ///ͳ�ƺ���
void menu1()
{
    int temp=1;
    while(temp)   ///�������Ա����ѡ��
    {
        printf("\n\t\t��ӭ�������Ա����ϵͳ��\n");
        printf("\n\t\t����й���ѡ��\n");
        printf("\t\t\t1 ����ѯ\n");
        printf("\t\t\t2 ��¼��\n");
        printf("\t\t\t3 ���޸�\n");
        printf("\t\t\t4 ��ɾ��\n");
        printf("\t\t\t5 ��ͳ��\n");
        printf("\t\t\t6 ������\n");
        printf("\t\t\t7 ���ָ�\n");
        printf("\t\t\t0 ���˳�\n");
        printf("������������ţ�");
        char t=input_char();
        switch(t)
        {
        case '1':
        {
            printf("\n������������Ա��ID��");
            int id=string_to_number();
            search_by_id(id);
        }
        break;
        case '2':
            adds();
            break;
        case '6':
        {
            ///ֻ�ܱ�������µ���Ϣ����Ϊ�޷��ϸ��µ������ļ��޷����ã�ÿ���µ�������Ҫ�ֶ����ݣ�
            char t[20]= {0};
            sprintf(t,"back%s",nowdatefile);
            transform_file(nowdatefile,t,"����");
            end_display();
        }
        break;
        case '7':
        {
            char t[20]= {0};
            sprintf(t,"back%s",nowdatefile);
            transform_file(t,nowdatefile,"�ָ�");
            end_display();
        }
        break;
        case '5':
            countpeople();
            break;
        case '0':
            temp=0;
            break;
        case '3':
            change();
            break;
        case '4':
            deletes();
            break;
        default:
            qingping();
            printf("\n��Ч������������ѡ��R�n�Q\n");
            break;
        }
    }
    qingping();

}
/********************************************/

void change_recordfile(STU * head);
void adds() ///�����Ա
{
    qingping();
    int active=2;
    int have_now_data=0;
    Date *nowdate=get_nowdate();
    if(nowdate->year==begin_date.year && nowdate->month==begin_date.month)
        active=1;
    FILE * fp=fopen(nowdatefile,"rb");
    if(fp!=NULL&&date_in_filename(nowdate,"date.txt"))
    {
        /* if(!date_in_filename(nowdate,nowdatefile)) */have_now_data=1;
        printf("\n���������Ѵ��ڣ��Ƿ�Ҫ����\n");
        while(1)
        {
            printf("\n1����  0����\n");
            printf("������������ţ�");
            char t=input_char();
            if(t=='0')
            {
                active=0;
                qingping();
                break;
            }
            else if(t=='1')
            {
                active=1;
                break;
            }
            else
            {

                printf("\n��Ч����������������R�n�Q\n");
            }
        }
    }
    fclose(fp);
    if(active==2)
    {
        printf("\n�������ݿ�����ɣ���ѡ����²����R�بQ\n");
        Date lastmonth;
        if(nowdate->month==1)
        {
            lastmonth.month=12;
            lastmonth.year=nowdate->year-1;
        }
        else
        {
            lastmonth.month=nowdate->month-1;
            lastmonth.year=nowdate->year;
        }
        char lastmonth_string[20]= {0};
        date_to_string(lastmonth_string,&lastmonth);
        STU *lastmonth_head=file_to_list(lastmonth_string);
        STU * p=lastmonth_head;
        STU * nowhead=NULL;
        while(lastmonth_head!=NULL)
        {
            nowhead=after_add_people(nowhead,nowdate->year,nowdate->month,lastmonth_head);
            lastmonth_head=lastmonth_head->next;
        }
        delete_list(p);
        // printf("\n�Ƿ�Ҫ������Ա\n");
        while(1)
        {
            printf("\n�Ƿ�Ҫ������Ա\n");
            printf("\n1����  0����\n");
            printf("������������ţ�");
            char t=input_char();
            if(t=='0')
                break;
            else if(t=='1')
            {
                active=1;
                break;
            }
            else
            {
                qingping();
                printf("\n��Ч����������������R�n�Q\n");
            }
        }
        qingping();
        list_to_file(nowdatefile,nowhead);
        change_recordfile(nowhead);
        delete_list(nowhead);
    }
    if(active==1)
    {
        qingping();
        STU * p=file_to_list(nowdatefile);
        STU * head=p;
        printf("\n���� -1 ��ʾ¼�����\n");
        while((p=add_people(head,nowdate->year,nowdate->month))!=NULL)
        {
            printf("\n���� -1 ��ʾ¼�����\n");
            head=p;
        }
        list_to_file(nowdatefile,head);
        change_recordfile(head);
        delete_list(head);
    }
    if(!have_now_data)
        add_date_to_filename("date.txt",nowdate);
}

void change_recordfile(STU * head)
{
    if(head==NULL)
        return;
    Date * nowdate=get_nowdate();
    Record *he=recordfile_to_list("record.txt");    ///�򿪴���ÿ�½�����ļ���Ȼ���γ�����
    long long salary=totaloflist(head);
    he=change_salary(he,nowdate->year,nowdate->month,salary);
    list_to_recordfile("record.txt",he);     ///���º�Ľ��������浽ԭ�����ļ��У�����ԭ�����ݣ���
    delete_recordlist(he);      ///ɾ�����������ͷſռ�
}

/***********************************************/
void change()
{
    qingping();
    STU * head=file_to_list(nowdatefile);
    if(head==NULL)
        return;
    modify(head);
    list_to_file(nowdatefile,head);
    change_recordfile(head);
    delete_list(head);
}

void deletes()
{
    qingping();
    STU * head=file_to_list(nowdatefile);
    if(head==NULL)
        return;
    head=delete_struct(head);
    list_to_file(nowdatefile,head);
    change_recordfile(head);
    delete_list(head);
    qingping2();
}
/********************************************/
void getfilename(char *t);
void search_by_bpsalary();
void search_by_totalsalary();
void countpeople()
{
    qingping();
    char filename[20]= {0};
    getfilename(filename);
    int temp=1;
    STU * head=file_to_list(filename);
    if(head==NULL)
        return;
    while(temp)
    {

        printf("\n\t\t\t��ѯ��׼��\n");
        printf("\t\t\t1 ��ID\n");
        printf("\t\t\t2 ����н\n");
        printf("\t\t\t3 ����Ч����\n");
        printf("\t\t\t4 ���ܹ���\n");
        printf("\t\t\t5 ��˰����\n");
        // printf("6 ������\n");
        //printf("4 ���绰\n");
        printf("\t\t\t0 ���˳�\n");
        printf("������������ţ�");
        char t=input_char();
        switch(t)
        {
        case '1':
            display_list(head);
            end_display();
            break;
        case '2':
        case '3':
            search_by_bpsalary(head,t-'0');
            break;
        case '4':
        case '5':
            search_by_totalsalary(head,t-'0');
            break;
        case '0':
            temp=0;
            break;
        default:
            printf("\n��׼�Ŵ���������ѡ��R�n�Q\n");
            break;
        }

    }
    qingping();
    delete_list(head);
}

int getchoice(int begin,int end);
void getfilename(char * t)
{
    char ti[20]= {0};
    Date *nowdate=get_nowdate();
    while(1)
    {
        // printf("\n��ѡ����Ҫ��ѯ����ݣ�\n");
        for(int i=begin_date.year; i<= nowdate->year; i++)
        {
            printf("\t\t\t%d\n",i);
        }
        printf("\n��ѡ����Ҫ��ѯ����ݣ�");
        int m=getchoice(begin_date.year,nowdate->year);  ///ȷ������ѡ�����,������ȷ����ѡ���·�
        Record *he=recordfile_to_list("record.txt");
        Record *he1=draw_recordpart(he,m);
        display_recordlist(he1);
        delete_recordlist(he);
        delete_recordlist(he1);
        //  printf("\n��ѡ����Ҫ��ϸ��ѯ���·ݣ�\n");
        // printf("\n���� 0 �˳�\n");
        for(int i=1; i<13; i++)
        {
            printf("\t\t\t%d\n",i);
        }
        printf("\n��ѡ����Ҫ��ϸ��ѯ���·ݣ����� 0 �˳�����");
        // printf("\n���� 0 �˳�\n");
        memset(ti,0,sizeof(ti));
        int n=getchoice(0,12); ///ȷ������ѡ����
        sprintf(ti,"%04d%02d.txt",m,n); ///ȷ������Ҫ�򿪵��ļ���
        FILE * fp=fopen(ti,"rb");
        if(fp==NULL)
        {
            qingping();
            if(n!=0)
                printf("\n%04d��%d�������ݣ�������ѡ��R�n�Q\n",m,n);
        }
        else
        {
            fclose(fp);
            qingping();
            break;
        }
    }
    strcpy(t,ti);
}

int getchoice(int begin,int end)
{
    int m=0;
    while(1)
    {
        m=string_to_number();
        if(m < begin || m > end)
            printf("\n��Ч������������ѡ��R�n�Q\n");
        else
            break;
    }
    return m;
}

void search_by_bpsalary(STU * head,int m)
{
    {
        qingping();
        sort_list(head,m);
        int temp=1;
        while(temp)
        {
            printf("\n\t\t\t��ѯ��׼��\n");
            printf("\t\t\t0���˳�\n");
            printf("\t\t\t1��0~6000\n");
            printf("\t\t\t2��6000~10000\n");
            printf("\t\t\t3��10000������\n");
            printf("\t\t\t4��ȫ��\n");
            printf("�������ѯ��׼��");
            char t=input_char();
            switch(t)
            {
            case '4':
            {
                display_list(head);
                end_display();
            }
            break;
            case '1':
            case '2':
            case '3':
            {
                STU * p=draw_part(head,-(6+m*3+t-'0'));
                if(p==NULL)
                {
                    qingping();
                    printf("\n�޴˲��֣������²�ѯ�R�n�Q\n");
                }
                else
                {
                    //sort_list(p1115,4);
                    display_list(p);
                    end_display();
                }
            }
            break;
            case '0':
                temp=0;
                qingping();
                break;
            default:
                qingping();
                printf("\n��׼�Ŵ�������������R�n�Q\n");
                break;
            }
        }
    }
}

void search_by_totalsalary(STU * head,int m)
{
    {
        qingping();
        sort_list(head,4);   /// 4 �����ܹ�����
        int temp=1;
        while(temp)
        {
            printf("\n\t\t\t��ѯ��׼��\n");
            printf("\t\t\t0���˳�\n");
            printf("\t\t\t1��0~6000\n");
            printf("\t\t\t2��6000~10000\n");
            printf("\t\t\t3��10000������\n");
            printf("\t\t\t4��ȫ��\n");
            printf("�������ѯ��׼��");
            char t;
            scanf("%c",&t);
            getchar();
            switch(t)
            {
            case '4':
            {
                display_list(head);
                end_display();
            }
            break;
            case '1':
            case '2':
            case '3':
            {
                STU * p=draw_part(head,-(6+m*3+t-'0'));
                if(p==NULL)
                {
                    qingping();
                    printf("\n�޴˲��֣������²�ѯ�R�n�Q\n");
                }
                else
                {
                    //sort_list(p1115,4);
                    display_list(p);
                    end_display();
                }
            }
            break;
            case '0':
                temp=0;
                qingping();

                break;
            default:
                qingping();
                printf("\n��׼�Ŵ�������������R�n�Q��");
                break;
            }
        }
    }
}
/********************************************/

void end_display()
{
    //printf("\n���� 0 �Է���:");
    while(1)
    {
        printf("\n���� 0 �Է���:");
        char  t;
        scanf("%c",&t);
        getchar();
        if(t=='0')
        {
            printf("\n");
            break;
        }
        else
        {
            qingping();
            printf("\n�����ַ���Ч������������R�n�Q\n");
        }
    }
    qingping();
}
void qingping()
{
    system("cls");
    printf("\t  ********************************************\n");
    printf("\t  *                                          *\n");
    printf("\t  *             ���ʹ���ϵͳ                 *\n");
    printf("\t  *                                          *\n");
    printf("\t  ********************************************\n");
}
void qingping2()
{
    system("cls");
    printf("\t  ********************************************\n");
    printf("\t  *                                          *\n");
    printf("\t  *             ���ʹ���ϵͳ                 *\n");
    printf("\t  *                                          *\n");
    printf("\t  ********************************************\n");
}
