#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

#include "struct.h"

STU * tail_insert(STU * tail,STU * st);
STU * create_list(STU *st);
/**����Ϊ����������Ĳ��������õ���ͬ˳�������**/
/***************************************************************************/

void swap_struct(STU * p1,STU *p3);  ///�����������ṹ��Ľ���

int judge_struct(STU * p3,STU *p2,int rule)  ;   ///����ʱ��ͬ���ŷ�
/**  ��һ��׼λ��ͬ�Ĺ��򣬵ڶ���׼Ϊ��Ŵ�С������
 * rule 1��-1�������ȼ�С->�󣨴�->С����������
 * rule 2��-2����������С->�󣨴�->С����������
 * rule 3��-3���������乤��С->�󣨴�->С����������
 * rule 4��-4�������ܹ���С->�󣨴�->С��
 * ���෵�� -1
 */

void sort_list(STU *head,int rule) ; ///�������ɲ�ͬ������

STU * reverse_list(STU * head) ;     ///��������ţ�������ŴӴ�С�š�����ͷָ��

/**����Ϊ��ȡ�����һ����**/
/***************************************************************************/

STU * search_id(STU * head,int id);  ///���ձ�Ų���ĳ����㡣���ص��������㣨ǳ���ƣ���Ϊ�˺�ɾ����

long long totaloflist(STU * head);

int draw_rule(STU * p,int rule) ;    ///��ȡʱ��ѭ�Ĺ���Ҫ��

STU* draw_part(STU* head,int rule)/*,STU **a)*/ ;  ///���ݲ�ͬ�Ĺ��򣬽��в�ͬ����ȡ,����NULL����ȡʧ�ܣ����෵������ͷ

/**����Ϊ��ӡ����**/
/***************************************************************************/

void display(STU *p);    ///���������Ļ�ϴ�ӡ����

void display_list(STU * head);

#endif // SEARCH_H_INCLUDED
