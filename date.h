#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct DATE;
typedef struct DATE Date;
struct DATE
{
    int year;
    int month;
    struct DATE *next;
};

Date * get_nowdate();

///将日期添加到文件里
void add_date_to_filename(const char * filename,Date * t);

int datefile_is_null(const char * filename);

Date * create_datelist(Date *st) ;    ///创造链表头

Date * date_tail_insert(Date * tail,Date * st);

Date * datefile_to_list(const char * filename);

void date_to_string(char * str,Date * da);

int date_in_filename(Date * t,const char * filename) ;

Date* drawdate_part(Date *p,int year1,int month1,int year2,int month2);

#endif // DATE_H_INCLUDED
