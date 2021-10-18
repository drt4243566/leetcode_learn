#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;


// 这个题目的关键点在于分解每一小步 — — — —> 从当前的status出发，对应的next_status的所有可能情况；
// BFS的思想，利用一个队列记录status和对应的step，同时有两个hashset，一个为死锁，另一个为已访问的结点
class Solution{
public:
    char num_prev(char x){
        return x=='0'?'9':x-1;
    }

    char num_succ(char x){
        return x=='9'?'0':x+1;
    }

    vector<string> get(string &status){
        vector<string> ret;
        for(int i=0;i<4;i++){
            char num = status[i];
            status[i] = num_prev(num);
            ret.push_back(status);
            status[i] = num_succ(num);
            ret.push_back(status);
            status[i] = num;
        }
        return ret;
    }

    int openlock(vector<string> &deadlock,string target){
        unordered_set<string> dead;
        for(string sd:deadlock){
            dead.insert(sd);
        }
        queue<pair<string,int>> q;
        q.emplace("0000",0);
        unordered_set<string> seen = {"0000"};
        while(!q.empty()){
            auto [status,step] = q.front();
            q.pop();
            for(auto&& next_status:get(status)){
                if(!seen.count(next_status)&&!dead.count(next_status)){
                    if(target==next_status){
                        return step+1;
                    }
                    q.emplace(next_status,step+1);
                    seen.insert(move(next_status));
                }
            }
        }
        return -1;
    }
};

int main(){
    return 0;
}