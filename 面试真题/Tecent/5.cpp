#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int nums,weight;
        vector<int> fms;
        int sum = 0;
        cin >> nums >> weight;
        for(int i=0;i<nums;i++){
            int tmp;
            cin >> tmp;
            fms.push_back(tmp);
        }
        sort(fms.begin(),fms.end());
        for(auto i:fms){
            sum += i;
        }
        if(sum<=weight){
            if(sum==weight){
                cout <<nums << endl;
                continue;
            }
            else{
                cout << -1 << endl;
                continue;
            }
        }
        int k = sum/weight + 1;
        int mixnum = 9999;
        int num_tmp = 0;
        for(int i=1;i<=k;i++){
            int wei_tmp = i*weight;
            for(int j=fms.size()-1;j>=0;j--){
                if(wei_tmp<fms[j]) continue;
                if(wei_tmp==fms[j]){
                    num_tmp++;
                    if(mixnum>num_tmp){
                        mixnum = num_tmp;
                    }
                    break;
                }
                if(wei_tmp!=fms[j]){
                    for(int q=j;q>=0;q--){
                        if(wei_tmp<fms[q]) continue;
                        if(wei_tmp==fms[q]){
                            num_tmp++;
                            if(mixnum>num_tmp) mixnum = num_tmp;
                            num_tmp = 0;
                            wei_tmp = i*weight;
                            break;
                        }
                        wei_tmp -= fms[q];
                        num_tmp++;
                    }
                }
            }
        }
        cout << mixnum << endl;
    }
    return 0;
}