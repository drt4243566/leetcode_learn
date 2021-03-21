#include <iostream>
#include <vector>
#include <string>

using namespace std;
// 替换空格
class Solution1
{
public:
    string replaceSpace(string s)
    {
        size_t pos = s.find_first_of(" ");
        while(pos != -1){
            s.replace(pos,1,"%20");
            pos = s.find_first_of(" ");
        }
        return s;
    }
};
//  官方推荐解法,动态解法
class Solution2{
public:
    string replaceSpace(string s){
        string res;
        for(auto &c : s){
            if( c == ' '){
                res.push_back('%');
                res.push_back('2');
                res.push_back('0');
            }
            else{
                res.push_back(c);
            }
        }
        return res;
    }
};
//  静态字符数组解法
class Solution3
{
public:
    string replaceSpace(string s)
    {
        char* cArray=new char[s.size()*3]();
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                cArray[j++]='%';
                cArray[j++] = '2';
                cArray[j++] = '0';
            }
            else{
                cArray[j++]=s[i];
            }
        }
        string res(cArray, j);   // 只取前j个字符，因为多余部分为乱码.
        return res;
    }
};

//  更加简便的库函数实现方式： return s.replace(" ","%20");   ———针对python

int main(){
    Solution1 sol;
    Solution2 sol2;
    Solution3 sol3;
    string s = "We are happy.";
    string res1 = sol.replaceSpace(s);
    string res2 = sol2.replaceSpace(s);
    string res3 = sol3.replaceSpace(s);
    cout << s << endl;
    cout << res1 << " " << res2 <<" "<< res3 << endl;
    return 0;
}