#include <iostream>
#include <vector>
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main(){
    int N;
    cin >> N;
    vector<int> arr;
    for(int i=0; i<N; i++) {
        arr.push_back(read());
    }
    int v;
    vector<int> res;
    for(v = 30; v > 0; v--) {
        res.clear();
        int temp = (1 << v) - 1;
        for(auto p= arr.begin(); p!= arr.end(); p++) {
            /* why & 1 ? */
            if( ( ( (*p)>>v) & 1 )  ) {
                temp = temp & (*p);
                res.push_back(*p);
            }
        }
        if( temp == 0) {
            break;
        }
    }
    cout<<res.size()<<endl;
    cout<<*res.begin();
    for(auto p = res.begin()+1; p!=res.end();p++) {
        cout<<" "<<*p;
    }
    return 0;
}
