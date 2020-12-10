#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

//  自己实现的方法1，算法对数据局限太多
class Solution1
{
public:
    // 反转单链表
    vector<int> reversePrint(ListNode *head)
    {
        vector<int> res;
        if(head==NULL){
            return res;
        }
        else if(head->next == NULL){        // 单个元素的情况，对于p3的初始化非常致命
            res.push_back(head->val);
            return res;
        }
        ListNode* p1=head;
        ListNode* p2=p1->next;
        p1->next=NULL;
        ListNode *p3=p2->next;
        while(p3!=NULL){
            p2->next=p1;
            p1=p2;
            p2=p3;
            p3=p2->next;
        }
        p2->next = p1;
        head=p2;
        ListNode *p4=head;
        while(p4!=NULL){
            res.push_back(p4->val);
            p4 = p4->next;
        }
        return res;
    }
};

// 方法2 摘自Leetcode上其他人的解法
class Solution2{
public:
    vector<int> reversePrint(ListNode *head){
        ListNode *pre = NULL;
        ListNode *cur = head;
        while(cur){     // 同时检测head是否为空的作用
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        vector<int> res;
        while(pre){
            res.push_back(pre->val);
            pre = pre->next;
        }
        return res;
    }
};

// 方法3 偷鸡做法
class Solution3
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        ListNode *cur = head;
        stack<int> stack;
        while (cur)
        { // 同时检测head是否为空的作用
           stack.push(cur->val);
           cur = cur->next;
        }

        vector<int> res;
        while (!stack.empty())
        {
           res.push_back(stack.top());
           stack.pop();
        }
        return res;
    }
};

// 方法4  静态数组解法
//  1. 从头遍历，获取链表长度；
//  2. 建立数组，再次遍历链表，但是从数组的最后端开始倒序存放数据；


void printNode(ListNode *head){
    if(head!=NULL){
        ListNode *cur = head;
        while (cur)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
}

int main(){
    vector<int> inputData = {1,2,4,5};
    ListNode *head = new ListNode(inputData[0]);
    ListNode *cur = head;
    for(int i=1;i<inputData.size();i++){
        ListNode *newNode = new ListNode(inputData[i]);
        cur->next = newNode;
        cur = cur->next;
    }
    cur->next = NULL;
    printNode(head);
    vector<int> res;
    Solution1 sol1;
    Solution2 sol2;
    Solution3 sol3;
    res = sol3.reversePrint(head);
    for(int i=0; i<res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

