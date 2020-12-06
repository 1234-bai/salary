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
    printf("\t  *             工资管理系统                 *\n");
    printf("\t  *                                          *\n");
    printf("\t  ********************************************\n");
    //char m=0,n=7;
    //printf("请分别输入两个数字以设置背景及文字颜色（前者背景后者文字,默认黑底白字）:\n0=黑色 1=蓝色 2=绿色 3=湖蓝色 4=红色 5=紫色 6=黄色 7=白色 8=灰色 9=淡蓝色\n");
    // scanf("%c%c",&a,&b);
    system("color a0");
    Date *nowdate=get_nowdate();
    date_to_string(nowdatefile,nowdate);
    begin();
    return 0;
}

/********************************************/
void sign_in(); ///登录
void sign_up(); ///注册
void begin()
{
    while(1)
    {
        printf("\n\t\t\t1：登录\n");
        printf("\t\t\t2：注册\n");
        printf("\t\t\t0：退出\n");
        printf("请输入操作代号：");
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
            printf("\n输入一位字母，请重新输入上示一位数字≧﹏≦\n");
        }
    }
}

/********************************************/
void sign_up() ///注册
{

    id * p=create_id();
    qingping();
    while(1)
    {
        printf("\n\t\t\t1：管理员注册\n");
        printf("\t\t\t2：普通员工注册\n");
        printf("\t\t\t0：退出\n");
        printf("请输出操作代号：");
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
            printf("\n输入一位字母，请重新输入上示一位数字≧﹏≦\n");

        }
    }
    qingping();
}

/******************************************************/
void menu1();
void search_by_id(int id);
void sign_in()  ///登录
{

    id * ip=create_id();
    qingping();
    int m=id_in_filename(ip,"id0faddmin.txt");
    if(m==1)
        menu1();   ///管理员账号，进入管理员功能选择
    else if(m==-1)      ///是管理员账号，但密码不正确
    {
        qingping();
        printf("\n输入密码不正确，请重新选择操作≧﹏≦\n");

    }
    else    ///不是管理员账号,判断是否是员工账号
    {
        m=id_in_filename(ip,"id0fstaff.txt");
        if(m==1)    ///员工账号
        {
            printf("欢迎进入员工系统！（以下为您的信息）");
            for(long int i=0; i<500000000; i++);
            search_by_id(ip->acc); ///查找相关信息
        }
        else if(m==-1)      ///是员工账号，但密码不正确
        {
            qingping();
            printf("\n输入密码不正确，请重新选择操作≧﹏≦\n");
        }
        else    ///不是员工账号
        {
            qingping();
            printf("\n无此账号，请重新操作≧﹏≦\n");
        }
    }
}
/********************************************/
void search_by_id(int id)   ///查找此账号的相关信息
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
        if(sp==NULL)      ///此日期文件中没有这个人
        {
            k2++;
        }
        else    ///把这个人的信息打出来
        {
            salary+=sp->final_salary;
            printf("\n     编号    姓名           电话     年份   月份     底薪  绩效工资   总工资  税后工资\n");
            display(sp);
        }
        delete_list(head);
        dp=dp->next;
    }
    if(k1==k2)  ///搜遍全部文件都没有这个人信息（没有这个人的文件数和总文件数相等）
        printf("\n无此人信息≧﹏≦\n");
    else
    {
        printf("\n*******************************************总获得为：%lld************************************************\n\n",salary);
        Date *dp2=datefile_to_list("date.txt");
        printf("请输入初始年份");
        int year1=string_to_number();
        printf("请输入初始月份");
        int month1=string_to_number();
        printf("请输入结束年份");
        int year2=string_to_number();
        printf("请输入结束月份");
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
            if(sp1==NULL)      ///此日期文件中没有这个人
            {
                k22++;
            }
            else    ///把这个人的信息打出来
            {
                salary1+=sp1->final_salary;
                printf("\n     编号    姓名           电话     年份   月份     底薪  绩效工资   总工资  税后工资\n");
                display(sp1);
            }
            delete_list(head1);
            dp3=dp3->next;
        }
        if(k11==k22)  ///搜遍全部文件都没有这个人信息（没有这个人的文件数和总文件数相等）
            printf("\n无数据≧﹏≦\n");
        else
        {
            printf("\n*******************************************总获得为：%lld************************************************\n",salary1);
        }
    }
    end_display();
}
/********************************************/
void adds();    ///添加人员函数
void change();  ///修改人员
void deletes(); ///删除人员
void countpeople();     ///统计函数
void menu1()
{
    int temp=1;
    while(temp)   ///进入管理员功能选择
    {
        printf("\n\t\t欢迎进入管理员操作系统！\n");
        printf("\n\t\t请进行功能选择：\n");
        printf("\t\t\t1 ：查询\n");
        printf("\t\t\t2 ：录入\n");
        printf("\t\t\t3 ：修改\n");
        printf("\t\t\t4 ：删除\n");
        printf("\t\t\t5 ：统计\n");
        printf("\t\t\t6 ：备份\n");
        printf("\t\t\t7 ：恢复\n");
        printf("\t\t\t0 ：退出\n");
        printf("请输入操作代号：");
        char t=input_char();
        switch(t)
        {
        case '1':
        {
            printf("\n请输入所查人员的ID：");
            int id=string_to_number();
            search_by_id(id);
        }
        break;
        case '2':
            adds();
            break;
        case '6':
        {
            ///只能备份这个月的信息，因为无法上个月的数据文件无法调用（每个月的数据需要手动备份）
            char t[20]= {0};
            sprintf(t,"back%s",nowdatefile);
            transform_file(nowdatefile,t,"备份");
            end_display();
        }
        break;
        case '7':
        {
            char t[20]= {0};
            sprintf(t,"back%s",nowdatefile);
            transform_file(t,nowdatefile,"恢复");
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
            printf("\n无效操作，请重新选择≧﹏≦\n");
            break;
        }
    }
    qingping();

}
/********************************************/

void change_recordfile(STU * head);
void adds() ///添加人员
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
        printf("\n本月数据已存在，是否要继续\n");
        while(1)
        {
            printf("\n1：是  0：否\n");
            printf("请输入操作代号：");
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

                printf("\n无效操作，请重新输入≧﹏≦\n");
            }
        }
    }
    fclose(fp);
    if(active==2)
    {
        printf("\n上月数据拷贝完成，请选择更新操作≧ω≦\n");
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
        // printf("\n是否要增加人员\n");
        while(1)
        {
            printf("\n是否要增加人员\n");
            printf("\n1：是  0：否\n");
            printf("请输入操作代号：");
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
                printf("\n无效操作，请重新输入≧﹏≦\n");
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
        printf("\n输入 -1 表示录入结束\n");
        while((p=add_people(head,nowdate->year,nowdate->month))!=NULL)
        {
            printf("\n输入 -1 表示录入结束\n");
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
    Record *he=recordfile_to_list("record.txt");    ///打开储存每月结算的文件，然后形成链表
    long long salary=totaloflist(head);
    he=change_salary(he,nowdate->year,nowdate->month,salary);
    list_to_recordfile("record.txt",he);     ///更新后的结算链表储存到原来的文件中（覆盖原来数据）；
    delete_recordlist(he);      ///删除结算链表，释放空间
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

        printf("\n\t\t\t查询标准：\n");
        printf("\t\t\t1 ：ID\n");
        printf("\t\t\t2 ：底薪\n");
        printf("\t\t\t3 ：绩效工资\n");
        printf("\t\t\t4 ：总工资\n");
        printf("\t\t\t5 ：税后工资\n");
        // printf("6 ：姓名\n");
        //printf("4 ：电话\n");
        printf("\t\t\t0 ：退出\n");
        printf("请输入操作代号：");
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
            printf("\n标准号错误，请重新选择≧﹏≦\n");
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
        // printf("\n请选择所要查询的年份：\n");
        for(int i=begin_date.year; i<= nowdate->year; i++)
        {
            printf("\t\t\t%d\n",i);
        }
        printf("\n请选择所要查询的年份：");
        int m=getchoice(begin_date.year,nowdate->year);  ///确定了所选的年份,接下来确定所选的月份
        Record *he=recordfile_to_list("record.txt");
        Record *he1=draw_recordpart(he,m);
        display_recordlist(he1);
        delete_recordlist(he);
        delete_recordlist(he1);
        //  printf("\n请选择所要详细查询的月份：\n");
        // printf("\n输入 0 退出\n");
        for(int i=1; i<13; i++)
        {
            printf("\t\t\t%d\n",i);
        }
        printf("\n请选择所要详细查询的月份（输入 0 退出）：");
        // printf("\n输入 0 退出\n");
        memset(ti,0,sizeof(ti));
        int n=getchoice(0,12); ///确定了所选的月
        sprintf(ti,"%04d%02d.txt",m,n); ///确定了所要打开的文件；
        FILE * fp=fopen(ti,"rb");
        if(fp==NULL)
        {
            qingping();
            if(n!=0)
                printf("\n%04d年%d月无数据，请重新选择≧﹏≦\n",m,n);
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
            printf("\n无效操作，请重新选择≧﹏≦\n");
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
            printf("\n\t\t\t查询标准：\n");
            printf("\t\t\t0：退出\n");
            printf("\t\t\t1：0~6000\n");
            printf("\t\t\t2：6000~10000\n");
            printf("\t\t\t3：10000及以上\n");
            printf("\t\t\t4：全部\n");
            printf("请输入查询标准：");
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
                    printf("\n无此部分，请重新查询≧﹏≦\n");
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
                printf("\n标准号错误，请重新输入≧﹏≦\n");
                break;
            }
        }
    }
}

void search_by_totalsalary(STU * head,int m)
{
    {
        qingping();
        sort_list(head,4);   /// 4 代表按总工资排
        int temp=1;
        while(temp)
        {
            printf("\n\t\t\t查询标准：\n");
            printf("\t\t\t0：退出\n");
            printf("\t\t\t1：0~6000\n");
            printf("\t\t\t2：6000~10000\n");
            printf("\t\t\t3：10000及以上\n");
            printf("\t\t\t4：全部\n");
            printf("请输入查询标准：");
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
                    printf("\n无此部分，请重新查询≧﹏≦\n");
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
                printf("\n标准号错误，请重新输入≧﹏≦：");
                break;
            }
        }
    }
}
/********************************************/

void end_display()
{
    //printf("\n输入 0 以返回:");
    while(1)
    {
        printf("\n输入 0 以返回:");
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
            printf("\n输入字符无效，请重新输入≧﹏≦\n");
        }
    }
    qingping();
}
void qingping()
{
    system("cls");
    printf("\t  ********************************************\n");
    printf("\t  *                                          *\n");
    printf("\t  *             工资管理系统                 *\n");
    printf("\t  *                                          *\n");
    printf("\t  ********************************************\n");
}
void qingping2()
{
    system("cls");
    printf("\t  ********************************************\n");
    printf("\t  *                                          *\n");
    printf("\t  *             工资管理系统                 *\n");
    printf("\t  *                                          *\n");
    printf("\t  ********************************************\n");
}
