#include <iostream>
#include <vector>
using namespace std;
typedef struct Node * treeNode;
typedef struct Info * InfoNode;
struct Node {
    int value;
    vector<treeNode> nexts;
    Node(int x) 
     : value(x) {
         nexts.clear();
    }
};
struct Info {
    int happyNo;
    int happyYes;
    Info(int no, int yes) {
        happyNo = no;
        happyYes = yes;
    }
};
InfoNode process(treeNode x) {
    if(x->nexts.empty()) {/*x是基层员工*/
        return new Info(0,x->value);
    }
    int yes = x->value;
    int no = 0;
    for(treeNode next : x->nexts) {
        InfoNode nextInfo = process(next);
        yes += nextInfo ->happyNo;
        no += max(nextInfo->happyNo,nextInfo->happyYes);
    }
    return new Info(no,yes);

}
int maxHappy(treeNode head) {
    InfoNode headInfo = process(head);
    return max(headInfo->happyNo,headInfo->happyYes);
}
int main(){
    treeNode head = new Node(5);
    head->nexts.push_back(new Node(4));
    head->nexts.push_back(new Node(5));
    head->nexts[0]->nexts.push_back(new Node(5));
    head->nexts[0]->nexts.push_back(new Node(8));
    cout<<maxHappy(head)<<endl;
    return 0;
}
