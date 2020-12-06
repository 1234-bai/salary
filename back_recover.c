#include <stdio.h>
#include<stdlib.h>

void transform_file(const char * fromfile,const char * tofile,const char * string)
{
        FILE *infp, *outfp;//infp:�����ļ�ָ�� outfp�������ļ�ָ��
        char  ch;
        infp = fopen(fromfile, "r+");
        outfp = fopen(tofile, "w+");
        if(infp==NULL)
        {
            printf("Cannot open %s.\n",fromfile);
            exit(0);
        }
        if (outfp==NULL)
        {
            printf("Cannot open %s.\n",tofile);
            exit(0);
        }//�ж��ܷ���ȷ���������ļ��뱸���ļ�

        while (feof(infp) == 0)
        {
            if ((ch = fgetc(infp)) != EOF)
            {
               // printf("%c", ch);
                fputc(ch, outfp);//�������ļ���������Ϣ�浽�����ļ���
            }
        }
        printf("%s\n",string);
        fclose(infp);
        fclose(outfp);
       // system("cls");
}
