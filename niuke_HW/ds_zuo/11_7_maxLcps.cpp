#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string manacherString(string str) {
    string temp;
    for (int i = 0; i < str.size(); i++) {
        temp.push_back('#');
        temp.push_back(str[i]);
    }
    temp.push_back('#');
    return temp;
}
int maxLcpsLength(string s) {
    if (s.size() < 1) return 0;
    string str = manacherString(s);
    vector<int> pArr(str.size());
    int C = -1;
    int R = -1;
    int maxV = 0;
    for (int i = 0; i != str.size(); i++) {
        pArr[i] = R > i ? min(pArr[2 * C - i], R - i) : 1;
        while (i + pArr[i]<str.size() and i - pArr[i]>-1) {
            if (str[i + pArr[i]] == str[i - pArr[i]])
                pArr[i]++;
            else
                break;
        }
        if (i + pArr[i] > R) {
            R = i + pArr[i];
            C = i;
        }
        maxV = max(maxV, pArr[i]);
    }
    return maxV - 1;
}
int main() {
    string str;
    cin >> str;
    int maxL = 0;
    for (int i = 0; i < str.size(); i++) {
        string temp = str.substr(i, str.size() - i) + str.substr(0, i);
        int n = maxLcpsLength(temp);
        maxL = max(maxL, n);
    }
    cout << maxL << endl;
    return 0;
}