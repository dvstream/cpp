// ASCII.cpp : Defines the entry point for the console application.
// ��ӡ��255��ASCII��

#include "stdafx.h"

#include"stdio.h"
#include"windows.h"  //���ͷ�ļ��������

int main(void)
{
    SetConsoleOutputCP(437);
    // ָ��CMD��ʾ�ķ�ʽΪӢ�ģ�������������ʾASCII��128-255�е��ַ���
    // ��Ҫ��ʾ���ģ�SetConsoleOutputCP(936);
    for (unsigned int a = 0; a < 256; ++a)
    {
        printf("[%d-%c] ", a, a);
        if (a % 10 == 9)
        {
            printf("\n");
        }
    }

    return 0;
}
