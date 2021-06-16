#include <iostream>
using namespace std;
typedef struct Node * treeNode;
typedef struct Info * InfoNode;
struct Node {
    int value;
    struct Node *left;
    struct Node *right;
    Node(int x) :
            value(x), left(nullptr), right(nullptr) {
    }
};
struct Info {
    int maxDistance;
    int height;
    Info(int dis, int h) {
        maxDistance = dis;
        height = h;
    }
};
InfoNode process(treeNode x) {
    if(x == nullptr ) {
        return new Info(0,0);
    }
    InfoNode leftInfo = process(x->left);
    InfoNode rightInfo = process(x->right);
    int height = 1 + max(leftInfo->height,rightInfo->height);
    int maxDistance = 1 + leftInfo->height + rightInfo->height;
    maxDistance = max(maxDistance,leftInfo->maxDistance);
    maxDistance = max(maxDistance,rightInfo->maxDistance);

    return new Info(maxDistance,height);
}
int maxDistanceInTree(treeNode head) {
    return process(head)->maxDistance;
}
int main(){
    treeNode head = new Node(3);
    head -> left = new Node(4);
    head ->right = new Node(5);
    head ->left ->left = new Node(5);
    head ->left ->right = new Node(8);
    head->right->left = new Node(7);
    head->right->right = new Node(10);
    cout<<maxDistanceInTree(head)<<endl;
    return 0;
}
