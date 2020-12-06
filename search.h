#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

#include "struct.h"

STU * tail_insert(STU * tail,STU * st);
STU * create_list(STU *st);
/**以下为对整个链表的操作，来得到不同顺序的链表**/
/***************************************************************************/

void swap_struct(STU * p1,STU *p3);  ///链表中两个结构体的交换

int judge_struct(STU * p3,STU *p2,int rule)  ;   ///排序时不同的排法
/**  第一标准位不同的规则，第二标准为编号从小到大排
 * rule 1（-1）：按等级小->大（大->小）以下类似
 * rule 2（-2）：按工龄小->大（大->小）以下类似
 * rule 3（-3）：按工龄工资小->大（大->小）以下类似
 * rule 4（-4）：按总工资小->大（大->小）
 * 其余返回 -1
 */

void sort_list(STU *head,int rule) ; ///排序，生成不同的链表

STU * reverse_list(STU * head) ;     ///链表的逆排，即按编号从大到小排。返回头指针

/**以下为提取链表的一部分**/
/***************************************************************************/

STU * search_id(STU * head,int id);  ///按照编号查找某个结点。返回的是这个结点（浅复制），为了好删除。

long long totaloflist(STU * head);

int draw_rule(STU * p,int rule) ;    ///提取时遵循的规则（要求）

STU* draw_part(STU* head,int rule)/*,STU **a)*/ ;  ///根据不同的规则，进行不同的提取,返回NULL则提取失败，其余返回链表头

/**以下为打印链表**/
/***************************************************************************/

void display(STU *p);    ///将结点在屏幕上打印出来

void display_list(STU * head);

#endif // SEARCH_H_INCLUDED
