#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
    ListNode(int v):val(v),next(nullptr){}
};


class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // write code here
        ListNode* fast = new ListNode(0);
        ListNode* slow = fast;
        ListNode* temp = fast;
        fast->next = head;
        slow->next = head;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow==temp){
            return head->next;
        }
        if(slow!=head){
            slow->next = slow->next->next;
            return head;
        }
        else{
            return head->next;
        }
    }
};