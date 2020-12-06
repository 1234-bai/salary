#ifndef BACK_RECOVER_H_INCLUDED
#define BACK_RECOVER_H_INCLUDED

#include <stdio.h>
#include<stdlib.h>

void transform_file(const char * fromfile,const char * tofile,const char * string) ///文件的复制
{
    FILE *infp, *outfp;//infp:工资文件指针 outfp：备份文件指针
    char  ch;
    infp = fopen(fromfile, "rb+");
    outfp = fopen(tofile, "wb+");
    if(infp==NULL)
    {
        printf("\n无本月数据，请进行录入操作\n");
        return;
    }
   /* if (outfp==NULL)
    {
        printf("Cannot open %s.\n",tofile);
        exit(0);
    }//判断能否正确开启工资文件与备份文件*/
    while (feof(infp) == 0)
    {
        if ((ch = fgetc(infp)) != EOF)
        {
            // printf("%c", ch);
            fputc(ch, outfp);//将工资文件内所有信息存到备份文件内
        }
    }
    printf("%s成功\n",string);
    fclose(infp);
    fclose(outfp);
    // system("cls");
}

#endif // BACK_RECOVER_H_INCLUDED
