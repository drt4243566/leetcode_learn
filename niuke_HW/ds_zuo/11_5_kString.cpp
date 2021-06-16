#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
string int2str(int num, int radix) {
    string ans;
    do {
        int t = num % radix;
        if (t >= 0 && t <= 9) ans.push_back(t + '0');
        else ans.push_back(t - 10 + 'A');
        num /= radix;
    } while (num != 0);
    //cout<<"ans:"<<ans<<endl;
    return string(ans.rbegin(), ans.rend());
}
string getKstring(int n, int k) {
    string res;
    for (int i = 1; i <= n; i++) {
        string temp = int2str(i, k);
        res += temp;
    }
    return res;
}
int main() {
    int n;
    string t;
    cin >> n;
    cin >> t;
    for (int k = 2; k <= 16; k++) {
        string temp = getKstring(n, k);
        if (temp.find(t)!=string::npos) {
            cout << "yes" << endl;
            return 0;
        }
    }
    cout << "no" << endl;
    return 0;
}