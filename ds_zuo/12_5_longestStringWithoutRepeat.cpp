#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int ans = 0, left = 0, right = 0;
    unordered_set<int> s;
    while (left < n && right < n) {
        if (!s.count(arr[right]) && right < n) {
            s.insert(arr[right]);
            right++;
            ans = max(ans, right - left);
        }
        else {
            s.erase(arr[left]);
            left++;
        }
    }
    cout << ans << endl;
    cin.get();
    return 0;
}