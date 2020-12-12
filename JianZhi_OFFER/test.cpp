#include <iostream>
#include <string>

using namespace std;

int main(){
    int a[10] = {1,2,3,4,5};
    char s[10] = " abced";
    //cin >> *a;
    //cout << a;
    cin >> s;
    cout << s;
    // cin >> a;    这一句甚至过不了类型检查
    return 0;
}

/*来波合理解释，a选项不行是因为数组名是一个地址常量，常量不能被写入更改；
b行，因为地址常量照样可以输出；c行，是因为c++里面吧>>重载了，专门设置了
当后面跟的是char*类型字符数组时候，可以正常输入字符串，相当于从头直接覆盖；
d行，因为b行，d也行，但是d应该也被重载了，<<输出的是第一个字符元素；*/