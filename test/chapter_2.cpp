// chapter_2.cpp : Defines the entry point for the console application.
// auto: conduct type from expression 
// normally auto ignore the top-level-const of init value,
// but for auto reforence retain the top-level-const of init value.

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{  /*
    auto i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;
    cout << "a = " << a <<endl;
    a = 42;
    cout << "a = " << a << endl;

    cout << "b = " << b << endl;
    b = 42;
    cout << "b = " << b << endl;

    cout << "c = " << c << endl;
    c = 42;
    cout << "c = " << c << endl;
    /*
    cout << "d = " << d << endl;
    d = 42; // d is int *
    cout << "d = " << d << endl;

    cout << "e = " << e << endl;
    e = 42; // e is const int *
    cout << "e = " << e << endl;
    
    cout << "g = " << g << endl;
    g = 42; // g is const int
    cout << "g = " << g << endl;
    */ 
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;
    const auto j3 = i, *k3 = &i;
    const int *k4 = &j;
    // *k3 = 43;// error
    // k3 = 43; // error 
    k4 = &j;
    return 0;
}

