#include <iostream>

using namespace std;

int main(){
    int n=1, m=2;
    int *p=&n, *q=&m;

    // p = &n;
    // *q = &m;

    // p = &*&n;
    // n = (*&)m;

    // n = (int)p;
    // n = *&*&m;

    p = &q;
    n = (*p)+++*q;

    return 0;
}