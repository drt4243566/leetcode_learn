#include <iostream>
#include <vector>

using namespace std;

struct s1
{
    char a[8];
};

struct s2
{
    double d;
};

struct s3
{
    s1 s;
    char a;
};

struct s4
{
    s2 s;
    char a;
};

int main(){
    cout << sizeof(s1) << endl;
    cout << sizeof(s2) << endl;
    cout << sizeof(s3) << endl;
    cout << sizeof(s4) << endl;
    return 0;
}