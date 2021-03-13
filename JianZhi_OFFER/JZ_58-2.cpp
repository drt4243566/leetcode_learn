#include <string>
using namespace std;
// 偷懒方法，使用substr函数
class Solution1 {
public:
    string reverseLeftWords(string s, int n) {
        string str=s.substr(0,n);
        return s.substr(n,s.size()-n)+str;
    }
};
// 列表遍历拼接
class Solution2{
public:
    string reverseLeftWords(string s,int n){
        string res;
        for(int i=n;i<s.size();i++){
            res.push_back(s[i]);
        }
        for(int i=0;i<n;i++){
            res.push_back(s[i]);
        }
        return res;
    }
};

// 列表遍历拼接 -- 可以使用取余对其进行优化
class Solution2{
public:
    string reverseLeftWords(string s,int n){
        string res;
        for(int i=n;i<s.size()+n;i++){
            res.push_back(s[i%s.size()]);
        }
        return res;
    }
};