#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cmp(int a,int b){
    return a>b;
}

int main(){
    vector<int> a,b;  //a是齐王的🐎，b是邹忌的🐎,i是齐王的快马索引，j是邹忌的快马索引,f则为齐王的慢马索引,k为邹忌的慢马索引
    int i(0),n(0),j(0),sum(0),k(0),f(0),king(0);
    while(scanf("%d",&n)&&n>0){
        for(int i=0;i<n;i++){
            int data_a=0;
            cin>>data_a;
            a.push_back(data_a);
        }
        for(int i=0;i<n;i++){
            int data_b=0;
           cin >> data_b;
            b.push_back(data_b);
        }
        sort(a.begin(),a.end(),cmp);  //默认升序，现在是降序
        sort(b.begin(),b.end(),cmp);
        // 慢马倒序
        k=n-1;
        f=n-1;
        for(int times=0;times<n;times++){
            // 邹忌的快马>齐王快马
            if(b[j]>a[i]) {
                sum++;
                j++;
                i++;
            }
            // 邹忌快马不如齐王
            else if(b[j]<a[i]){
                sum--;
                i++;
                k--;
            }
            else{
                // 在快马相同的情况下，邹忌慢马更快
                if(b[k]>a[f]){
                    sum++; k--; f--;
                }
                // 邹忌的慢马慢（或者慢马一样），就去和齐王的快马拼
                else if(b[k]<a[f]){
                    sum--; k--; i++;
                }
                else{
                    if(b[k]==a[i]){
                        k--;
                        i++;
                    }
                    else{
                        sum--;
                        k--;
                        i++;
                    }
                }
            }
        }
        printf("result is %d",sum);
    }
    return 0;
}