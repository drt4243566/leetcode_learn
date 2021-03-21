#include <iostream>
using namespace std;
typedef struct Node * treeNode;
typedef struct Info * InfoNode;
struct Node {
    int value;
    struct Node *left;
    struct Node *right;
    Node(int x) 
     : value(x), left(nullptr), right(nullptr) {
    }
};
struct Info {
    int maxBSTSize;
    bool isBST;
    int min;
    int max;
    Info(int maxBST, bool is, int mi, int ma) {
        maxBSTSize = maxBST;
        isBST = is;
        min = mi;
        max = ma;
    }
};
InfoNode process(treeNode x) {
    if(x == nullptr) {
        return new Info(0,true,INT_MAX,INT_MIN);
    }
    InfoNode leftInfo = process(x->left);
    InfoNode rightInfo = process(x->right);
    bool isBST = false;
    int maxBSTSize = max(leftInfo->maxBSTSize,rightInfo->maxBSTSize);
    if(leftInfo->isBST && rightInfo->isBST && 
        leftInfo->max < x->value && rightInfo->min >x->value) {
            maxBSTSize = leftInfo->maxBSTSize + 1 + rightInfo->maxBSTSize;
            isBST = true;
        }
    int mi = min(x->value, min(leftInfo->min, rightInfo->min));
    int ma = max(x->value, max(leftInfo->max, rightInfo->max));
    return new Info(maxBSTSize,isBST,mi,ma);
}
int maxBSTSize(treeNode head) {
    return process(head)->maxBSTSize;
}
int main(){
    treeNode head = new Node(5);
    head -> left = new Node(3);
    head ->right = new Node(7);
    head ->left ->left = new Node(1);
    head ->left ->right = new Node(4);
    head->right->left = new Node(6);
    head->right->right = new Node(8);
    cout<<maxBSTSize(head)<<endl;
    return 0;
}
