#include <bits/stdc++.h>
using namespace std;

void t1(int n) {
    //
    char a[n][n + 1];
    cout << (sizeof(a) >> 1) << endl; // 5050
}

class Tmp {
public:
    Tmp() {
        ++N;
        sum += N;
    }
    static void Reset() {
        N = 0;
        sum = 0;
    }
    static unsigned int GetSum() { return sum; }

private:
    static unsigned int N, sum;
};

unsigned int Tmp::N = 0, Tmp::sum = 0;

void t2(int n) {
    // 本质是动态数组调用N次构造函数, 构造函数内完成加法
    Tmp::Reset();
    auto a = new Tmp[n];
    delete[] a;
    a = NULL;
    cout << Tmp::GetSum() << endl; // 5050
}

class A;
A* arr[2];
class A {
public:
    virtual unsigned int sum(unsigned int n) { return 0; }
};

class B : public A {
public:
    virtual unsigned int sum(unsigned int n) {
        return arr[!!n]->sum(n - 1) + n; // 计算的关键, 映射0->1, 非零->0
    }
};


void t3(int n) {
    // 虚函数方法
    A a;
    B b;
    arr[0] = &a;
    arr[1] = &b;
    cout << arr[1]->sum(n) << endl; // 5050
}


typedef unsigned int (*fun)(unsigned int);
// 调用出口
unsigned int Fun1(unsigned int n) { return 0; }
unsigned int Fun2(unsigned int n) {
    static fun f[2] = {Fun1, Fun2}; // 函数指针数组
    return n + f[!!n](n - 1);
}

void t4(int n) {
    // 函数指针
    cout << Fun2(n) << endl; // 5050
}

template <unsigned int n>
struct Tmp1 {
    enum Value { N = Tmp1<n - 1>::N + n };
};

template <>
struct Tmp1<1> {
    enum Value { N = 1 };
};

void t5(int n) {
    // 模板递归, 缺点: 只能指定编译期常量
    cout << Tmp1<100>::N << endl; // 5050
}

int main() {
    //
    int n = 100;
    // t1(n);
    // t2(n);
    // t3(n);
    // t4(n);
    t5(n);
}