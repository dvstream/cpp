// chapter_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::string;
#ifndef DEBUG_LF
#define DEBUG_LF
#endif

#ifdef DEBUG_LF
#define DEBUG_INFO(fmt,...) {\
        printf(":%4d-%s:"##fmt, __LINE__, __FUNCTION__, ##__VA_ARGS__);\
    }
#endif

#ifdef DEBUG_FLF
#define DEBUG_INFO(fmt,...) {\
        printf("%s:%4d-%s: "##fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__);\
    }
#endif

#ifdef DEBUG_RELEASE
#define DEBUG_INFO(fmt,...) {\
        1;\
    }
#endif


typedef void(*fcb_func)();
map<string, fcb_func> map_func;
#define REG_FUNC(func_name, func)\
    if(map_func.find(func_name) == map_func.end())\
    {\
        map_func[func_name] = func;\
    }

void help();
void string_init();
void string_read_write();
void string_read_write1();
void string_read_write2();
void string_read_write3();
void string_size_type();
void string_compare();
void string_add();
void string_for();
void string_for1();
void string_for2();
void string_visit();
void string_visit1();
void string_visit2();
void string_exp_3_9();
void string_exp_3_11();


int main()
{
    REG_FUNC("help", help);
    REG_FUNC("string_init", string_init);
    REG_FUNC("string_read_write", string_read_write);
    REG_FUNC("string_read_write1", string_read_write1);
    REG_FUNC("string_read_write2", string_read_write2);
    REG_FUNC("string_read_write3", string_read_write3);
    REG_FUNC("string_size_type", string_size_type);
    REG_FUNC("string_compare", string_compare);
    REG_FUNC("string_add", string_add);
    REG_FUNC("string_for", string_for);
    REG_FUNC("string_for1", string_for1);
    REG_FUNC("string_for2", string_for2);
    REG_FUNC("string_visit", string_visit);
    REG_FUNC("string_visit1", string_visit1);
    REG_FUNC("string_visit2", string_visit2);
    REG_FUNC("string_exp_3_9", string_exp_3_9);
    REG_FUNC("string_exp_3_11", string_exp_3_11);
    DEBUG_INFO("\n");
    string cmd;
    cout << "please input the function name to execute:";
    while (cin >> cmd)
    {
        if (map_func.find(cmd) != map_func.end())
        {
            map_func[cmd]();
            cout << "******done******" << endl;
        }
        else
        {
            cout << "not have the function :" << cmd << endl;
        }
        cout << "please input the function name to execute:";
    }
    return 0;
}
void help()
{
    cout << "the functions name list:" << endl;
    cout << "------------------------------------------" << endl;
    decltype(map_func.size()) index = 0;
    for (auto itr : map_func)
    {
        cout << itr.first << "------"<< index << endl;
        ++index;
    }
    cout << "------------------------------------------" << endl;
    return;
}
void string_init()
{
    DEBUG_INFO("\n");
    string s1;
    string s2(s1);
    string s2_1 = s1;
    string s3("value");
    string s3_1 = "value";
    string s4(10, 'c');
    cout << "s1:" << s1 << endl;
    cout << "s2:" << s2 << endl;
    cout << "s2_1:" << s2_1 << endl;
    cout << "s3:" << s3 << endl;
    cout << "s3_1:" << s3_1 << endl;
    cout << "s4:" << s4 << endl;
    return;
}
void string_read_write()
{
    DEBUG_INFO("\n");
    string s1, s2;
    cin >> s1 >> s2;
    cout << s1 << s2 << endl;
    return;
}

void string_read_write1()
{
    string word;
    while (cin >> word)
        cout << word << endl;

    string line;
    while (getline(cin, line))
        cout << line.length() << ":" << line << endl;
    return;
}

void string_read_write2()
{
    string line;
    while (getline(cin, line))
        if (!line.empty())
            cout << line << endl;
    return;
}

void string_read_write3()
{
    string line;
    while (getline(cin, line))
        if (line.size() > 10)
            cout << line << endl;
    return;
}

void string_size_type()
{
    DEBUG_INFO("\n");
    string line;
    getchar();
    getline(cin, line);
    auto len = line.size();
    cout << line << ":" << typeid(line).name() << endl;
    cout << "len=" << len << " type:" << typeid(len).name() << endl;
    if (len > -1)
        cout << "true" << endl;
    return;
}

void string_compare()
{
    string s1, s2;
    getchar();
    while (getline(cin, s1) && getline(cin, s2))
    {
        if (s1 == s2)
            cout << "s1 == s2" << endl;
        else
            cout << (s1 > s2) << endl;
    }
    return;
}

void string_add()
{
    DEBUG_INFO("\n");
    string s1(5, 'a');
    string s2(5, 'b');
    string s3 = s1 + s2;
    cout << "s1:" << s1 << endl;
    cout << "s3:" << s3 << endl;
    s1 += s2;
    cout << "s1:" << s1 << endl;
    cout << "s2:" << s2 << endl;
    string s5 = s2 + "hello" + "," + "world";
    //string s5 += "hello"; // error not support this manipulator
    //string s1 += "hello"; // error not support this manipulator
    cout << "s5:" << s5 << endl;
    string s6 = "hello" + s2;
    cout << "s6:" << s6 << endl;
    // string s7 = "hello" + "," + s2; .// error
    return;
}
void string_for()
{
    DEBUG_INFO("\n");
    string line;
    getchar();
    while (getline(cin, line))
        for (auto &c : line)
            cout << c << endl;
    return;
}

void string_for1()
{
    DEBUG_INFO("\n");
    string line;
    getchar();
    decltype(line.length()) punct_num = 0;
    while (getline(cin, line))
    {
        for (auto c : line)
            if (ispunct(c))
                ++punct_num;
        cout << punct_num << endl;
        punct_num = 0;
    }
    return;
}

void string_for2()
{
    DEBUG_INFO("\n");
    string line;
    getchar();
    while (getline(cin, line))
    {
        for (auto &c : line)
            c = toupper(c);
        cout << line << endl;
    }
    return;
}
void string_visit()
{
    string s = "01234";
    cout << s[0] << endl;
    cout << s[s.size() - 1] << endl;
    cout << s[s.size()] << endl;
    cout << s.size() << endl;
    string s2(2, 'c');
    //cout << s2[3] << endl; // error
    return;
}

void string_visit1()
{
    DEBUG_INFO("\n");
    string line;
    getchar();
    while (getline(cin, line))
    {
        for (decltype(line.size()) index = 0;
            index != line.size() && !isspace(line[index]); ++index)
            line[index] = toupper(line[index]);
        cout << line << endl;
    }
    return;
}

void string_visit2()
{
    DEBUG_INFO("\n");
    const string hexdigits = "0123456789ABCDEF";
    cout << "Enter a series of numbers between 0 and 15"
         << "separated by spaces. Hit ENTER when finished:"
         << endl;
    string result;
    string::size_type n;
    while (cin >> n)
    {
        if (n < hexdigits.size())
        {
            result += hexdigits[n];
            cout << "Your hex number is: " << result << endl;
        }
    }
    cout << "Your hex number is: " << result << endl;
    return;
}

void string_exp_3_9()
{
    DEBUG_INFO("\n");
    string s;
    cout << s[0] << endl;
    cout << s.size() <<":" <<s.length()<<endl;
    return;
}

void string_exp_3_11()
{
    DEBUG_INFO("\n");
    const string s = "Keep out!";
    for (auto &c : s)
    {
        cout << c << endl;
        // c = toupper(c); //error const
    }
    return;
}