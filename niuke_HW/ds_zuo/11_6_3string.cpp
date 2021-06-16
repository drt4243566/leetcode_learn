#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    string res;
    for (int i = 0; i < str.size() - 1; i++) {
        string temp = str.substr(0, i+1);//pos num
        if (str.rfind(temp) == str.size() - i - 1) {
            int index = str.find(temp, 1);
            if (index != -1 and index < str.size() - i - 1) {
                res = temp;
            }
        }
    }
    if (res.size() != 0) {
        cout << res;
    }
    else {
        cout << "Just a legend" << endl;
    }
    return 0;
}