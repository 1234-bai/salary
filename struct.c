#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

struct student
{
    int id;
    char name[NAME_LENGTH];
    char level[2];     ///A B C D �ĸ��ȼ� (rule 1)
    char phone[PHONE_LENGTH];
    char address[ADDRESS_LENGTH];
    int work_age;       /// (rule 2)
    int salary_age;     ///ÿ�µĲ��������ݹ��䣩(rule 3)
    int salary_house;   ///���ݵȼ� (rule 1)
    int basic_salary;   ///���ݵȼ� (rule 1)
    int salary_per;     ///��Ч���ʣ����ݵȼ� (rule 1)
    int total_salary;   ///(rule 4)
    int final_salary;   ///(rule 4)
    struct student *next;
};

//ypedef struct student STU;
