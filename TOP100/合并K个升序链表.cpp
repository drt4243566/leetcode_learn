#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) { val = x; }
};

class Solution{
public:
    bool cmp(ListNode* l1,ListNode* l2){
        return l1->val>=l2->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,function<bool(ListNode*,ListNode*)>> pq(cmp);
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                pq.push(lists[i]);
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy;
        while(!pq.empty()){
            ListNode* cur = pq.top();
            pq.pop();
            pre->next = cur;
            pre = pre->next;
            if(pre->next) pq.push(p);
        }
    }
};


int main(){
    return 0;
}