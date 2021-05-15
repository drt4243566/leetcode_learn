#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

struct duiwu{
    char xuhao;
    int score;
    bool operator<(const duiwu& obj){
        if(score<obj.score) return false;
        else if(score>obj.score) return true;
        else{
            return xuhao<obj.xuhao;
        }
    }
};

int main(){
    string s;
    vector<duiwu> scores(26); 
    unordered_set<char> mp;
    for(char i='a';i<='z';i++){
        scores[i-'a'].xuhao = i;
        scores[i-'a'].score = 0;
    }
    while(getline(cin,s)){
        if(s.size()==0) break;
        mp.insert(s[0]);
        if(s[4]>s[6]){
            scores[s[0]-'a'].score += 3;
            scores[s[2]-'a'].score += 0;  
        }
        else if(s[4]==s[6]){
            if(s[4]=='0'){
                scores[s[0]-'a'].score += 0;
                scores[s[2]-'a'].score += 0; 
            }
            else{
                scores[s[0]-'a'].score += 1;
                scores[s[2]-'a'].score += 1; 
            } 
        }
        else{
            scores[s[0]-'a'].score += 0;
            scores[s[2]-'a'].score += 3;  
        }
          
    }
    sort(scores.begin(),scores.end());
    cout << scores[0].xuhao <<" "<<scores[0].score;
    for(int i=1;i<26;i++){
        if(mp.count(scores[i].xuhao)==0) continue;
        cout << "," << scores[i].xuhao << " " << scores[i].score;
    }
    return 0;
}