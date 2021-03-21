#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <stack>
#include <list>
#include <ctime>
using namespace std;
class MonotonousStack {
    vector<int> arr;
    vector<vector<int>> res;
public:
    MonotonousStack(vector<int>& v) {
        arr = v;
    }
    vector<vector<int>> getNearLessNoRepeat() {
        res = vector<vector<int>>(arr.size());
        stack<int> sta;
        for (int i = 0; i < arr.size(); i++) {
            while (!sta.empty() && arr[sta.top()] > arr[i]) {
                int popIndex = sta.top();
                sta.pop();
                int leftLessIndex = sta.empty() ? -1 : sta.top();
                res[popIndex].push_back(leftLessIndex);
                res[popIndex].push_back(i);
            }
            sta.push(i);
        }
        while (!sta.empty()) {
            int popIndex = sta.top();
            sta.pop();
            int leftLessIndex = sta.empty() ? -1 : sta.top();
            res[popIndex].push_back(leftLessIndex);
            res[popIndex].push_back(-1);
        }
        return res;
    }
    vector<vector<int>> getNearLess() {
        res = vector<vector<int>>(arr.size());
        stack<vector<int>> sta;
        for (int i = 0; i < arr.size(); i++) {
            while (!sta.empty() && arr[sta.top()[0]] > arr[i]) {
                vector<int> popV = sta.top();
                sta.pop();
                int leftLessIndex = sta.empty() ? -1 : sta.top()[sta.top().size() - 1];
                for (int popi : popV) {
                    res[popi].push_back(leftLessIndex);
                    res[popi].push_back(i);
                }
            }
            if (!sta.empty() && arr[sta.top()[0]] == arr[i]) {
                sta.top().push_back(i);
            }
            else {
                vector<int> vt;
                vt.push_back(i);
                sta.push(vt);
            }
        }
        while (!sta.empty()) {
            vector<int> popV = sta.top();
            sta.pop();
            int leftLessIndex = sta.empty() ? -1 : sta.top()[sta.top().size() - 1];
            for (int popi : popV) {
                res[popi].push_back(leftLessIndex);
                res[popi].push_back(-1);
            }
        }
        return res;
    }
};
int max_using2Loops(vector<int> arr) {
    int maxV = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i; j < arr.size(); j++) {
            int minNum = INT_MAX;
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
                minNum = min(minNum, arr[k]);
            }
            maxV = max(maxV, minNum * sum);
        }
    }
    return maxV;
}
int max_usingStack(vector<int> arr) {
    vector<vector<int>> res = MonotonousStack(arr).getNearLess();
    int allMax = INT_MIN;
    for (int i = 0; i < res.size(); i++) {
        int left = res[i][0];
        int right = res[i][1];
        int nowMin = arr[i];
        int leftPos = left == -1 ? 0 : left+1;
        int rightPos = right == -1 ? res.size()-1 : right-1;
        int sum = 0;
        for (int j = leftPos; j <= rightPos; j++) {
            sum += arr[j];
        }
        int nowMax = nowMin * sum;
        allMax = max(allMax, nowMax);
    }
    return allMax;
}
vector<int> generateRandomArray() {
    vector<int> arr;
    int sum = rand() % 10;
    for (int i = 0; i < sum; i++) {
        arr.push_back(rand() % 100);
    }
    return arr;
}
int main() {
    srand((unsigned)time(NULL));
    vector<int> arr = generateRandomArray();
    cout << "isEqual? " << (max_using2Loops(arr) == max_usingStack(arr))<< endl;
    //cout << max_using2Loops(arr)<< endl;
    //cout << max_usingStack(arr) << endl;
    return 0;
}