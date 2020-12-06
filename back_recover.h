#ifndef BACK_RECOVER_H_INCLUDED
#define BACK_RECOVER_H_INCLUDED

#include <stdio.h>
#include<stdlib.h>

void transform_file(const char * fromfile,const char * tofile,const char * string) ///�ļ��ĸ���
{
    FILE *infp, *outfp;//infp:�����ļ�ָ�� outfp�������ļ�ָ��
    char  ch;
    infp = fopen(fromfile, "rb+");
    outfp = fopen(tofile, "wb+");
    if(infp==NULL)
    {
        printf("\n�ޱ������ݣ������¼�����\n");
        return;
    }
   /* if (outfp==NULL)
    {
        printf("Cannot open %s.\n",tofile);
        exit(0);
    }//�ж��ܷ���ȷ���������ļ��뱸���ļ�*/
    while (feof(infp) == 0)
    {
        if ((ch = fgetc(infp)) != EOF)
        {
            // printf("%c", ch);
            fputc(ch, outfp);//�������ļ���������Ϣ�浽�����ļ���
        }
    }
    printf("%s�ɹ�\n",string);
    fclose(infp);
    fclose(outfp);
    // system("cls");
}

#endif // BACK_RECOVER_H_INCLUDED
