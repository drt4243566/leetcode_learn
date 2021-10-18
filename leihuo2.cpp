#include <iostream>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

struct Node
{
    int x;
    int y;
    Node(int x1,int y1):x(x1),y(y1){};

    bool operator<(Node &item){
        if(x==item.x) return y>item.y;
        return x>item.x;
    }
};

int main(){
    int R=0;
    cin >> R;
    
    return 0;
}