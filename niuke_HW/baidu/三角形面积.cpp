#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class Point{
public:
    int x,y,z;
    Point(int _x=0,int _y=0,int _z=0):x(_x),y(_y),z(_z){}
    void get(){
        scanf("%d%d%d",&x,&y,&z);
    }
    // 叉乘公式
    Point cross_product(const Point &b) const{
        return Point(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);
    }
    // 向量模长
    double get_len(){
        return sqrt((long long)x*x+(long long)y*y+(long long)z*z);
    }
    // 向量
    Point operator-(const Point& b) const{
        return Point(x-b.x,y-b.y,z-b.z);
    }
};

double ans = 0.0;
typedef vector<Point> vp;
typedef Point Vec;

// 遍历容器内的每一个向量
void loop(vp &a,vp &b,vp &c){
    for(vp::iterator i=a.begin();i!=a.end();++i){
        for(vp::iterator j=b.begin();j!=b.end();++j){
            for(vp::iterator k=c.begin();k!=c.end();++k){
                Vec sa=*j-*i;
                Vec sb=*k-*i;
                ans=max(ans,sa.cross_product(sb).get_len()*0.5);
            }
        }
    }
}

vp r,g,b;

int main(){
    int n;
    char tmp[3];
    cin >> n;
    for(int i=0;i<n;i++){
        // 输入颜色
        cin >> tmp;
        // 输入点的3D坐标
        Point p;p.get();
        if(tmp[0]=='R') r.push_back(p);
        if(tmp[0]=='G') g.push_back(p);
        if(tmp[0]=='B') b.push_back(p);
    }
    loop(r,r,r);
    loop(g,g,g);
    loop(b,b,b);
    loop(r,g,b);
    printf(".5f\n",ans);
    return 0;
}