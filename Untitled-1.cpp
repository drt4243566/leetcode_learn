
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string> s(n);

        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        // 判断
        bool tag=false;
        for(int i=0;i<n;i++){
            if(tag)break;
            for(int j=0;j<m;j++){
                if(s[i][j]=='*'){
                    if(i-1>=0 && s[i-1][j]=='*')continue;
                    if(i+1<n && s[i+1][j]=='*')continue;
                    if(j-1>=0&& s[i][j-1]=='*')continue;
                    if(j+1<m&&s[i][j+1]=='*')continue;
                    tag=true;
                    break;
                }
            }
        }
        if(tag){
            cout<<"NO"<<endl;
            continue;
        }


        int x;
        vector<vector<int> > row;
        for(int i=0;i<n;i++){
            int pre=-1;
            for(int j=0;j<m;j++){
                if(s[i][j]=='*'){
                    if(pre<0){
                        pre=j;
                    }
                }else{
                    if(pre>=0){
                        if(j-pre>1){
                            row.push_back({pre,j});
                            x=i;
                        }
                        pre=-1;
                    }
                }
            }
            if(pre>=0){
                if(m-pre>1){
                    row.push_back({pre,m});
                    x=i;
                }
                pre=-1;
            }
        }
        if(row.size()!=1){
            cout<<"NO"<<endl;
            continue;
        }


        int y;
        vector<vector<int> > col;
        for(int j=0;j<m;j++){
            int pre=-1;
            for(int i=0;i<n;i++){
                if(s[i][j]=='*'){
                    if(pre<0){
                        pre=i;
                    }
                }else{
                    if(pre>=0){
                        if(i-pre>1){
                            col.push_back({pre,i});
                            y=j;
                        }
                        pre=-1;
                    }
                }
            }
            if(pre>=0){
                if(n-pre>1){
                    col.push_back({pre,n});
                    y=j;
                }
                pre=-1;
            }
        }
        if(col.size()!=1){
            cout<<"NO"<<endl;
            continue;
        }

        // 判断是否合理
        //cout<<row[0][1]<<" "<<row[0][0]<<endl;
        if((row[0][1]-row[0][0])%2==0 || (col[0][1]-col[0][0])%2==0){
            cout<<"NO"<<endl;
        }else{
            //cout<<"dddd"<<endl;
            if((row[0][1]-row[0][0])/2+row[0][0]==y&&(col[0][1]-col[0][0])/2+col[0][0]==x){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}
