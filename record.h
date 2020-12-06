#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct RECORD;
typedef struct RECORD Record;
struct RECORD
{
    int year;
    int month;
    long long salary;
    struct RECORD *next;
};

int recordfile_is_null(const char * recordfilename);

Record * create_recordlist(Record *st);

int judge_record(Record * p3,Record *p2,int rule);

Record * insert_recordlist(Record * head,Record *st);

Record * recordtail_insert(Record * tail,Record * st);

Record * add_record(Record * head,int year,int month,long long salary);

Record * change_salary(Record * head,int year,int month,long long salary);

Record * recordfile_to_list(const char * recordfilename);

void list_to_recordfile(const char * recordfilename,Record * head);

void displayrecord(Record *p);

void display_recordlist(Record * head);

Record* draw_recordpart(Record* head,int year);

void delete_recordlist(Record *head) ;

#endif // RECORD_H_INCLUDED
