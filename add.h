#ifndef ADD_H_INCLUDED
#define ADD_H_INCLUDED

#include "struct.h"
///����Ҫ¼��Ľṹ�壬���������Ϊ-1�Ļ����ͷ���null����ʾ¼����������򷵻ش���ɹ��Ľṹ��
STU * create_STU();

///�����������Ϊnull
STU * create_list(STU *st);     ///��������ͷ���������һ���ṹ���ָ�룬������һ���¿��ٵĽṹ�壨��ƣ�

///��������¿��ٵĽṹ�壨��ƣ����������null�Ļ�˵��¼����Ա����ظ�������һ������·�������ͷָ��
STU * insert_list(STU * head,STU *st);    ///������Ա��¼����Ա��

///���������null������null��¼������null������ͷָ��
STU * add_people(STU * head,int year,int month);
STU * after_add_people(STU * head,int year,int month,STU * st);

/**����Ϊ�����������йصĺ���**/
/***************************************************************************/

///β�巨�����
STU * tail_insert(STU * tail,STU * st);

void delete_list(STU *head);     ///ɾ������

/**����Ϊ������ļ�����ϵ**/
/***************************************************************************/

///�ж��ļ��Ƿ�Ϊ�գ��շ���0�����򷵻�1
int file_is_null(const char * filename);

///���ļ�ת��Ϊ��������ͷָ��
STU * file_to_list(const char * filename);

///�����������ļ���
void list_to_file(const char * filename,STU * head);

#endif // ADD_H_INCLUDED
