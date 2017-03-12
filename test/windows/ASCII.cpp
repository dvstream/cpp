// ASCII.cpp : Defines the entry point for the console application.
// 打印出255个ASCII吗

#include "stdafx.h"

#include"stdio.h"
#include"windows.h"  //这个头文件必须添加

int main(void)
{
    SetConsoleOutputCP(437);
    // 指定CMD显示的方式为英文，即可以正常显示ASCII码128-255中的字符；
    // 想要显示中文：SetConsoleOutputCP(936);
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
