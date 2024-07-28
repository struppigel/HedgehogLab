// cdecl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class NumberCombinator
{
public:

    int i = 3;

    NumberCombinator(int arg1) 
    {
        i = arg1;
    }
    
    __declspec(noinline)
    int callme_thiscall(int arg2, int arg3, int arg4, int arg5, int arg6) 
    {
        return i + arg2 + arg3 + arg4 + arg5 + arg6;
    }
};

__declspec(noinline)
int __fastcall callme_fastcall(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) 
{
    return arg1 + arg2 + arg3 / arg4 + arg5 + arg6;
}

__declspec(noinline) 
int __stdcall callme_stdcall(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) 
{
    return arg1 + arg2 + arg3 * arg4 + arg5 + arg6;
}

__declspec(noinline) 
int __cdecl callme_cdecl(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) 
{
    return arg1 + arg2 + arg3 - arg4 + arg5 + arg6;
}

void cdecl_call() 
{
    int a = rand();
    int b = rand();
    int c = rand();
    int d = rand();
    int e = rand();
    int f = rand();

    int res1 = callme_cdecl(a, b, c, d, e, f);
    std::cout << res1 << std::endl;
}

void fastcall_call() 
{
    int a = rand();
    int b = rand();
    int c = rand();
    int d = rand();
    int e = rand();
    int f = rand();

    int res1 = callme_fastcall(a, b, c, d, e, f);
    std::cout << res1 << std::endl;
}

void stdcall_call() 
{
    int a = rand();
    int b = rand();
    int c = rand();
    int d = rand();
    int e = rand();
    int f = rand();

    int res1 = callme_stdcall(a, b, c, d, e, f);
    std::cout << res1 << std::endl;
}

void thiscall_call() 
{
    int a = rand();
    int b = rand();
    int c = rand();
    int d = rand();
    int e = rand();
    int f = rand();

    NumberCombinator* nc = new NumberCombinator(a);
    int res1 = nc->callme_thiscall(b, c, d, e, f);
    std::cout << res1 << std::endl;
}

int main()
{
    //cdecl_call();
    //stdcall_call();
    fastcall_call();
    //thiscall_call();
}