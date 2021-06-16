#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    int n,m,c;
    cin >> n >> m >>c;
    vector<int> iv;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        iv.push_back(tmp);
    }
    int sum = 0;
    for(int i=0;i<m;i++){
        sum += iv[i];     
    }
    int minNum = sum;

    for(int i=m;i<iv.size();i++){
        sum = sum-iv[i-m]+iv[i];
        minNum = min(sum,minNum);
    }
    cout << (int)(minNum*1.0/c+0.5) <<endl;
    return 0;
}
