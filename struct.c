#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

struct student
{
    int id;
    char name[NAME_LENGTH];
    char level[2];     ///A B C D 四个等级 (rule 1)
    char phone[PHONE_LENGTH];
    char address[ADDRESS_LENGTH];
    int work_age;       /// (rule 2)
    int salary_age;     ///每月的补助（根据工龄）(rule 3)
    int salary_house;   ///根据等级 (rule 1)
    int basic_salary;   ///根据等级 (rule 1)
    int salary_per;     ///绩效工资，根据等级 (rule 1)
    int total_salary;   ///(rule 4)
    int final_salary;   ///(rule 4)
    struct student *next;
};

//ypedef struct student STU;
