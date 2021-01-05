#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<memory.h>
#include <cstring>

using namespace std;

// 最直接的朴素解法 
class Solution1
{
public:
    vector<int> printNumbers(int n)
    {
        vector<int> res;
        int goal = pow(10, n);
        for (int i = 1; i < goal; i++)
        {
            res.push_back(i);
        }
        return res;
    }
};

// 题解：由于题目所给的函数返回值为int类型，相当于默认不越界
// 实际应当考虑大数越界问题
// 1. 默认数字类型明显会有越界风险，如Int,long一类的，因此使用string进行表示；
// 2. 如果使用进位方式过于复杂，可以转化为每位0~9的全排列，递归遍历；

class Solution2
{
public:
    void printNumbers(int n)
    {
        string res;
        string num(n,'0');
        process(res,num,0,n);
        cout<<res<<endl;
    }
    void process(string& res,string& num,int cur,int n){
        if(cur==n){
            res += num+" ";
            return;
        }
        for (int i = 0; i < 10; i++)
        {
            // string类型直接初始化不能使用char，但是Push_back可以，或者(size_t,char);
            // string temp(1, i);
            num[cur] = i+'0';
            // 这里的问题在于 循环当中如果定义 char i=0; 则实际给char类型的赋值是ASCII码等于0的空格符"/000"
            process(res,num,cur+1,n);
        }
    }
};


// 除了递归方法以外，还有一种直观方法，就是直接使用字符串形式来模拟数字的递增加法，然后是对于字符串的输出函数
// 存在一个问题，只会打印从1开始的数字，因此有必要先单独打印一个‘0’
class Solution3{
public:
    void printMax(int n){
        if(n<=0) return;
        char *num = new char[n+1]; //注意这里长度+1，存放最后的/0
        num[n] = '\0';
        memset(num,'0',n);
        printf("%c ",'0');
        while(!Increment(num)){  //这里第一次判断时已经为数字1
            printNum(num);
        }
        delete []num;
    }
    bool Increment(char* num){
        int len = strlen(num);
        int nTakeover = 0;
        bool nOverflow = false;
        for(int i=len-1;i>=0;i--){   //从最低位开始
            int nSum=num[i]-'0'+nTakeover;
            if(i==len-1){
                nSum++;
            }
            if(nSum>=10){     // 进位继续循环
                if(i==0){
                    return true;
                }
                nSum -= 10;
                nTakeover = 1;
                num[i] = nSum + '0';
            }
            else
            {
                num[i] = nSum + '0';
                break;
            }            
        }
        return nOverflow;
    }
    void printNum(char* num){
        bool begin0 = true;
        int len = strlen(num); // 使用strlen来获得给定char*类型字符数组的长度，此长度并不包括'\0'
        for(int i=0;i<len;i++){
            if(begin0&&num[i]!=0){
                begin0 = false;
            }
            if(!begin0){
                printf("%c ",num[i]);
            }
        }
        //printf("\t");  // 转义字符，表示一个TAB键的长度
    }
};

class Solution4{
public:
    void printMAX(int n){
        if(n<=0) return;
        string res;
        string num(n,'0');
        for(int i=0;i<10;i++){
            num[0] = i+'0';
            process(res,num,n,0);
        }
        cout<<res<<endl;
    }
    void process(string& res,string& num,int n,int cur){
        if(cur==n-1){
            res += num+" ";
            return;
        }
        for(char i='0';i<='9';i++){
            num[cur+1] = i;
            process(res,num,n,cur+1);
        }
    }
};

int main(){
    int n=1;
    Solution2 sol2;
    sol2.printNumbers(n);
    Solution3 sol3;
    sol3.printMax(n);
    printf("\n");
    Solution4 sol4;
    sol4.printMAX(n);
    //vector<int> res = sol.printNumbers(n);
    /*for(int i=0;i<res.size();i++){
        printf("%d ",res[i]);
    }
    printf("\n");*/
    return 0;
}