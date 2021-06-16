#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main(){
    int n=0;
    cin >> n;
    vector<int> tick(n,0);
    int sum=0;
    int a_max=0;
    for(int i=0;i<n;i++){
        cin >> tick[i];
        sum += tick[i];
        a_max = max(a_max,tick[i]);
    }
    int k = ceil((2*sum*1.0)/n);
    k = max(k,a_max);
    cout << k <<endl;
    return 0;
}