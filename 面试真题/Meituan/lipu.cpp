#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T>0){
        int n=0;
        string res;
        cin >> n;
        string str;
        cin >> str;
        vector<int> wood(n,0);
        for(int i=0;i<n;i++){
            wood[i] = str[i]-'0';
        }
        int L = 0,R = n-1;
        vector<int> flagL,flagR;
        int equal_t=0;
        while(L<R){
            if(wood[L]!=wood[R]){
                equal_t++;
                flagL.push_back(L);
                flagR.push_back(R);
            }
            L++;
            R--;
        }
        if(flagL.size()==0){
            if(n%2==1){
                wood[n/2] == 0;
            }
            for(int i:wood){
                res.push_back(i+'0');
            }
            cout << res;
        }
        else if(flagL.size()==1){
            int L_number =  wood[flagL[0]];
            int R_number = wood[flagR[0]];
            int temp = min(L_number,R_number);
            wood[flagL[0]] = temp;
            wood[flagR[0]] = temp;
            for(int i:wood){
                res.push_back(i+'0');
            }
            cout << res;
        }
        else{
            for(int i=0;i<n;i++){
                if(wood[i]!=0){
                    wood[i] = 0;
                    break;
                }
            }
            for(int i:wood){
                res.push_back(i+'0');
            }
            cout << res;
        }
        T--;
        cout << endl;
    }
    return 0;  
}