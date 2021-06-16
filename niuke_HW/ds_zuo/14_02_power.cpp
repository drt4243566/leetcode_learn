#include <iostream>
using namespace std;
int is2Power(int n) {
    return (n & (n - 1)) == 0;
}
int is4Power(int n) {
    return (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
}
int main(){
    cout<<is2Power(1024)<<endl;
    cout<<is4Power(1024)<<endl;
    return 0;
}
