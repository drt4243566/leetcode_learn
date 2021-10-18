#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 8 [1 2 4 8]
int ability(int num){
    int res = 0;
    for(int factor=1;factor<=num;factor++){
        if((num%factor)==0) res++;
    }
    return res;
}

int cmp(int a,int b){
    return a>b;
}

int main(){
    int n=0;
    cin >> n;
    int t=0;
    // 现在要让齐王赢
    // a是齐王的🐎，b是邹忌的🐎,i是齐王的快马索引，j是邹忌的快马索引,f则为齐王的慢马索引,k为邹忌的慢马索引
    // 齐王快马i,慢马f   邹忌快马j，慢马k
    int i(0),j(0),sum(0),k(0),f(0);
    vector<int> a(n,0),b(n,0);
    for(int i=0;i<n;i++){
        cin >> t;
        a[i] = ability(t);
    }
    for(int i=0;i<n;i++){
        cin >> t;
        b[i] = ability(t);
    }
    sort(a.begin(),a.end(),greater<int>());  //默认升序，现在是降序
    sort(b.begin(),b.end(),cmp);
    // 慢马倒序
    k=n-1;
    f=n-1;
    for(int times=0;times<n;times++){
        // 齐王的快马>邹忌快马
        if(a[i]>b[j]){
            sum++;
            i++;
            j++;
        }
        else if(a[i]<b[j]){
            f--;
            j++;
        }
        else{
            if(a[f]>b[k]){
                sum++;
                f--;
                k--;
            }
            else{
                f--;
                j++;
            }
        }
    }
    cout << sum << endl;
    return 0;
}