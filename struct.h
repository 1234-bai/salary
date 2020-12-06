#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

#define NAME_LENGTH 20
#define PHONE_LENGTH 20

struct student;
typedef struct student STU;


struct student
{
    int id;
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    //int work_age;       /// (rule 2)
    int year;
    int month;
    int basic_salary;
    int salary_per;     ///绩效工资，根据等级 (rule 1)
    int total_salary;   ///(rule 4)
    int final_salary;   ///(rule 4)
    struct student *next;
};

#endif // STRUCT_H_INCLUDED
