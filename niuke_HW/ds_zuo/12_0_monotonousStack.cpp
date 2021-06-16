#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;
class MonotonousStack{
    vector<int> arr;
    vector<vector<int>> res;
public:
    MonotonousStack(vector<int> &v){
        arr = v;
    }
    vector<vector<int>> getNearLessNoRepeat(){
        res = vector<vector<int>>(arr.size());
        stack<int> sta;
        for(int i = 0; i < arr.size(); i++){
            while( !sta.empty() && arr[sta.top()] > arr[i]){
                int popIndex = sta.top();
                sta.pop();
                int leftLessIndex = sta.empty() ? -1 :sta.top();
                res[popIndex].push_back(leftLessIndex);
                res[popIndex].push_back(i);
            }
            sta.push(i);
        }
        while( !sta.empty()){
            int popIndex = sta.top();
            sta.pop();
            int leftLessIndex = sta.empty() ? -1 : sta.top();
            res[popIndex].push_back(leftLessIndex);
            res[popIndex].push_back(-1);
        }
        return res;
    }
    vector<vector<int>> getNearLess(){
        res = vector<vector<int>>(arr.size());
        stack<vector<int>> sta;
        for(int i = 0; i < arr.size(); i++){
            while( !sta.empty() && arr[sta.top()[0]] > arr[i]){
                vector<int> popV = sta.top();
                sta.pop();
                int leftLessIndex = sta.empty() ? -1 :sta.top()[sta.top().size()-1];
                for(int popi : popV){
                    res[popi].push_back(leftLessIndex);
                    res[popi].push_back(i);
                }
            }
            if(!sta.empty() && arr[sta.top()[0]] == arr[i]){
                sta.top().push_back(i);
            } else {
                vector<int> vt;
                vt.push_back(i);
                sta.push(vt);
            }
        }
        while( !sta.empty()){
            vector<int> popV = sta.top();
            sta.pop();
            int leftLessIndex = sta.empty() ? -1 : sta.top()[sta.top().size()-1];
            for(int popi : popV){
                res[popi].push_back(leftLessIndex);
                res[popi].push_back(-1);
            }
        }
        return res;
    }
};
int main(){
    vector<int> v{3,4,1,5,6,2,7};
    MonotonousStack m(v);
    vector<vector<int>> res = m.getNearLessNoRepeat();
    for(int i=0;i<res.size();i++){
        cout<<i<<" "<<res[i][0]<<" "<<res[i][1]<<endl;
    }
    return 0;
}
