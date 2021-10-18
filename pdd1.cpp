#include <iostream>
#include <vector>
using namespace std;

bool judgePoint(vector<vector<char>> &picture,int visit,int i,int j){
    if(picture[i][j]=='.') return false;
    vector<int> dirX = {0,0,-1,1};
    vector<int> dirY = {1,-1,0,0};
    int step = 1;
    int stepMax = (visit-1)/4;
    while(step<=stepMax){
        for(int c=0;c<4;c++){
            int x = j+step*dirX[c];
            int y = i+step*dirY[c];
            if(x<0||x>=picture[0].size()||y<0||y>=picture.size()) break;
            if(picture[y][x]!='*') return false;
        }
        step++;
    }
    return true;
}

int main(){
    int T=0;
    int h=0,w=0;
    cin >> T;
    while(T--){
        cin >> h >> w;
        vector<vector<char>> picture(h,vector<char>(w,'.'));
        int visit=0;
        for(int i=0;i<h;i++){
            string str;
            cin >> str;
            for(int j=0;j<w;j++){
                picture[i][j] = str[j];
                if(picture[i][j]=='*') visit++;
            }
        }
        bool res=false;
        if((visit-1)%4!=0){
            cout << "NO" << endl;
            continue;
        } 
        for(int i=1;i<h-1;i++){
            for(int j=1;j<w-1;j++){
                res = res || judgePoint(picture,visit,i,j);
                if(res) break;
            }
        }
        if(res){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

/*
4
7 7
.......
...*...
..****.
...*...
...*...
.......
.*.....
5 6
..**..
..**..
******
..**..
..**..
3 7
.*...*.
***.***
.*...*.
5 10
..........
..*.......
.*.******.
..*.......
..........
*/