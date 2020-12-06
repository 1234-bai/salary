#ifndef ADD_H_INCLUDED
#define ADD_H_INCLUDED

#include "struct.h"
///创造要录入的结构体，如果输入编号为-1的话，就返回null，表示录入结束，否则返回创造成功的结构体
STU * create_STU();

///传入参数不会为null
STU * create_list(STU *st);     ///创造链表头，传入的是一个结构体的指针，返回另一个新开辟的结构体（深复制）

///插入的是新开辟的结构体（深复制）。如果返回null的话说明录入人员编号重复，出错。一般情况下返回链表头指针
STU * insert_list(STU * head,STU *st);    ///增加人员（录入人员）

///输入结束的null，返回null；录入出错的null，返回头指针
STU * add_people(STU * head,int year,int month);
STU * after_add_people(STU * head,int year,int month,STU * st);

/**以下为和链表生成有关的函数**/
/***************************************************************************/

///尾插法：深复制
STU * tail_insert(STU * tail,STU * st);

void delete_list(STU *head);     ///删除链表

/**以下为链表和文件的联系**/
/***************************************************************************/

///判断文件是否为空，空返回0，否则返回1
int file_is_null(const char * filename);

///将文件转化为链表，返回头指针
STU * file_to_list(const char * filename);

///将链表储存在文件中
void list_to_file(const char * filename,STU * head);

#endif // ADD_H_INCLUDED
