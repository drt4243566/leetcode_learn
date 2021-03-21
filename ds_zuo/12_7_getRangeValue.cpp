#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits.h>
#define INT_MIN     (-2147483647 - 1)
#define INT_MAX       2147483647
typedef long long LL;
using namespace std;
vector<vector<int>> getBigPeakRange(vector<LL> arr) {
    int n = arr.size() - 1;
    stack<LL> st;
    vector<vector<int>> pos(arr.size());
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && arr[i] >= arr[st.top()]) {
            st.pop();
        }
        pos[i].push_back(st.size() == 0 ? 1 : st.top() + 1);
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            st.pop();
        }
        pos[i].push_back(st.size() == 0 ? n : st.top() - 1);
        st.push(i);
    }
    /*
    cout << "bigPeak:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " " << pos[i][0] << " " << pos[i][1] << endl;
    }
    */
    return pos;
}
vector<vector<int>> getSmallPeakRange(vector<LL> arr) {
    int n = arr.size() - 1;
    stack<int> st;
    vector<vector<int>> pos(arr.size());
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && arr[i] <= arr[st.top()]) {
            st.pop();
        }
        pos[i].push_back(st.size() == 0 ? 1 : st.top() + 1);
        st.push(i);
    }
    while (!st.empty())st.pop();
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            st.pop();
        }
        pos[i].push_back(st.size() == 0 ? n : st.top() - 1);
        st.push(i);
    }
    /*
    cout << "smallPeak:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " " << pos[i][0] << " " << pos[i][1] << endl;
    }
    cout << endl;
    */
    return pos;
}
LL getArrValue2(vector<LL> arr) {
    vector<vector<int>> minPeakPos = getSmallPeakRange(arr);
    vector<vector<int>> maxPeakPos = getBigPeakRange(arr);
    LL sum = 0;
    for (int i = 1; i <= arr.size() - 1; i++) {
        int minLeftPos = minPeakPos[i][0];
        int minRightPos = minPeakPos[i][1];
        int maxLeftPos = maxPeakPos[i][0];
        int maxRightPos = maxPeakPos[i][1];
        int index1 = ((minRightPos - i + 1) * (i - minLeftPos + 1) - 1);
        int index2 = ((maxRightPos - i + 1) * (i - maxLeftPos + 1) - 1);
        sum -= index1 * arr[i];
        sum += index2 * arr[i];
        //printf("((%d - %d + 1)*(%d - %d + 1) - 1)= %d; -%d*%d = %d\n", minRightPos, i, i, minLeftPos, index1, index1, arr[i], index1 * arr[i]);
        //printf("((%d - %d + 1)*(%d - %d + 1) - 1)= %d; +%d*%d = %d\n", maxRightPos, i, i, maxLeftPos, index2, index2, arr[i], index2 * arr[i]);
        //cout << endl;
    }
    return sum;
}
int getArrValue(vector<int> arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            int minv = INT_MAX, maxv = INT_MIN;
            for (int k = i; k <= j; k++) {
                minv = min(minv, arr[k]);
                maxv = max(maxv, arr[k]);
            }
            sum += maxv - minv;
        }
    }
    return sum;
}
int main() {

    int M, N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        vector<LL> arr;
        arr.push_back(-1);
        cin >> N;
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        cout << getArrValue2(arr) << endl;
    }
    /*
    vector<int> arr{ 4,2,3};
    MonotonousStack m(arr);
    vector<vector<int>> res = m.getNearLarger();
    for (int i = 0; i < res.size(); i++) {
        cout << i << " " << res[i][0] << " " << res[i][1] << endl;
    }

    vector<int> a{ -1,1,8,4,3,9 };
    for (int i = 1; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < a.size(); i++) {
        cout << i << " ";
    }
    cout << endl;
    cout << getArrValue2(a) << endl;
    cin.get();
    */
    return 0;
}


/*

#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N=1e5+10;
typedef long long ll;
stack <int> st;
ll l[N],r[N],a[N];

int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        int n;
        ll sum=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++){
            while(st.size()&&a[i]<=a[st.top()]) st.pop();
            l[i]=st.size()==0?1:st.top()+1;
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i=n;i>=1;i--){
            while(st.size()&&a[i]<a[st.top()]) st.pop();
            r[i]=st.size()==0?n:st.top()-1;
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i=1;i<=n;i++) sum-=((r[i]-i+1)*(i-l[i]+1)-1)*a[i];
        for(int i=1;i<=n;i++){
            while(st.size()&&a[i]>=a[st.top()]) st.pop();
            l[i]=st.size()==0?1:st.top()+1;
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i=n;i>=1;i--){
            while(st.size()&&a[i]>a[st.top()]) st.pop();
            r[i]=st.size()==0?n:st.top()-1;
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i=1;i<=n;i++) sum+=((r[i]-i+1)*(i-l[i]+1)-1)*a[i];
        printf("%lld\n",sum);
    }

    return 0;
}

https://www.cnblogs.com/ehanla/p/10003420.html

*/

/*
* 改成LL时间复杂度就通过了
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
typedef long long LL;
using namespace std;
int M, N;
LL arr[100003];
LL L[100003], R[100003];
LL getArrValue3() {
    stack<int> st;
    int n = N;
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && arr[i] >= arr[st.top()]) {
            st.pop();
        }
        L[i] = st.size() == 0 ? 1 : st.top() + 1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            st.pop();
        }
        R[i] = st.size() == 0 ? n : st.top() - 1;
        st.push(i);
    }

    for (int i = 1; i <= n; i++) {
        sum += ((R[i] - i + 1) * (i - L[i] + 1) - 1) * arr[i];
    }
    while (!st.empty()) st.pop();
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && arr[i] <= arr[st.top()]) {
            st.pop();
        }
        L[i] = (st.size() == 0 ? 1 : st.top() + 1);
        st.push(i);
    }
    while (!st.empty())st.pop();
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            st.pop();
        }
        R[i] = (st.size() == 0 ? n : st.top() - 1);
        st.push(i);
    }
    for (int i = 1; i <= n; i++) {
        sum -= ((R[i] - i + 1) * (i - L[i] + 1) - 1) * arr[i];
    }
    return sum;
}

int main() {
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> N;
        for (int j = 1; j <= N; j++) {
            scanf("%d",&arr[j]);
        }
        cout << getArrValue3() << endl;
    }
    return 0;
}





*/