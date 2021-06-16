#include <iostream>
using namespace std;
typedef struct Node * treeNode;
struct Node {
    int value;
    struct Node *left;
    struct Node *right;
    Node(int x) :
            value(x), left(nullptr), right(nullptr) {
    }
};
void morris(treeNode head){
    if(head == nullptr) return;
    treeNode cur = head;
    treeNode mostRight = nullptr;
    while(cur != nullptr) {
        cout<<cur->value<<" ";
        mostRight = cur->left;
        if(mostRight != nullptr) {
            while(mostRight->right != nullptr && mostRight->right != cur){
                mostRight = mostRight -> right;
            }
            if(mostRight->right == nullptr) { /*第一次来到最右节点*/
                mostRight ->right = cur;
                cur = cur -> left;
                continue;
            } else {/*第二次来到最右节点*/
                mostRight ->right = nullptr;
            }
        }
        cur = cur -> right;
    }
}
void morrisPre(treeNode head){
    if(head == nullptr) return;
    treeNode cur = head;
    treeNode mostRight = nullptr;
    while(cur != nullptr) {
        mostRight = cur->left;
        if(mostRight != nullptr) {
            while(mostRight->right != nullptr && mostRight->right != cur){
                mostRight = mostRight -> right;
            }
            if(mostRight->right == nullptr) { /*第一次来到最右节点*/
                cout << cur->value << " ";
                mostRight ->right = cur;
                cur = cur -> left;
                continue;
            } else {/*第二次来到最右节点*/
                mostRight ->right = nullptr;
            }
        } else {
            cout<<cur->value<<" ";
        }
        cur = cur -> right;
    }
}
void morrisIn(treeNode head){
    if(head == nullptr) return;
    treeNode cur = head;
    treeNode mostRight = nullptr;
    while(cur != nullptr) {
        mostRight = cur->left;
        if(mostRight != nullptr) {
            while(mostRight->right != nullptr && mostRight->right != cur){
                mostRight = mostRight -> right;
            }
            if(mostRight->right == nullptr) { /*第一次来到最右节点*/
                mostRight ->right = cur;
                cur = cur -> left;
                continue;
            } else {/*第二次来到最右节点*/
                mostRight ->right = nullptr;
                cout<< cur->value << " ";
            }
        } else {
            cout << cur->value << " ";
        }
        cur = cur -> right;
    }
}
treeNode reverseEdge(treeNode from){
   treeNode pre = nullptr;
   treeNode next = nullptr;
   while(from != nullptr) {
       next = from->right;
       from -> right  = pre;
       pre = from;
       from = next;
   }
    return pre;
}
void printSubRightEdge(treeNode head){
    treeNode tail = reverseEdge(head);
    treeNode cur = tail;
    while(cur != nullptr) {
        cout<<cur->value<<" ";
        cur = cur -> right;
    }
    reverseEdge(tail);
}
void morrisPos(treeNode head){/*后序遍历*/
    if(head == nullptr) return;
    treeNode cur = head;
    treeNode mostRight = nullptr;
    while(cur != nullptr) {
        mostRight = cur->left;
        if(mostRight != nullptr) {
            while(mostRight->right != nullptr && mostRight->right != cur){
                mostRight = mostRight -> right;
            }
            if(mostRight->right == nullptr) { /*第一次来到最右节点*/
                mostRight ->right = cur;
                cur = cur -> left;
                continue;
            } else {/*第二次来到最右节点*/
                mostRight ->right = nullptr;
                printSubRightEdge(cur->left);/*打印当前节点左子树的右边界*/
            }
        }
        cur = cur -> right;
    }
    printSubRightEdge(head);/*打印头节点右边界*/
}
int main(){
    treeNode head = new Node(3);
    head -> left = new Node(4);
    head ->right = new Node(5);
    head ->left ->left = new Node(5);
    head ->left ->right = new Node(8);
    head->right->left = new Node(7);
    head->right->right = new Node(10);
    morrisPos(head);
    return 0;
}
