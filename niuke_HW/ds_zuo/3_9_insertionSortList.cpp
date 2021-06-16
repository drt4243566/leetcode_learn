#include <iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
 };

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* insertionSortList(ListNode* head) {
        // write code here
        if(head==NULL or head->next==NULL)
            return head;
        ListNode* newhead = new ListNode;
        newhead->next = NULL;
        newhead->val = -1;

        ListNode *p, *q;
        ListNode *cur ;
        p = newhead;
        q = newhead;
        cur = head;
        while(cur){
            //q指向下一个无序的数
            q = cur->next;
            while(p->next !=NULL && p->next->val <cur->val){
                p = p->next;
                //cout<<"2"<<endl;
            }
            cur->next = p->next;
            p->next = cur;
            p = newhead;
            cur = q;
        }
        return newhead->next;
    }
};

void print(ListNode * head){
    ListNode* p;
    p = head;
    while(p){
        std::cout<<p->val<<'\t';
        p = p->next;
    }
    std::cout<<std::endl;
}
ListNode* createLinklist(){
    ListNode* head;
    head = NULL;
    return head;
}
ListNode* InsertLinklist(ListNode* head, int num){

    if(head==NULL){
        head = new ListNode;
        head->next = NULL;
        head->val = num;
    }
    else{
        ListNode *p = head;
        ListNode *q = head;
        while(q){
            p = q;
            q = q->next;
        }
        p->next = new ListNode;
        p->next->val = num;
        p->next->next = NULL;
    }

    return head;
}
int main(){

    ListNode *head;
    head = NULL;
    head = InsertLinklist(head,4);
    head = InsertLinklist(head,3);
    head = InsertLinklist(head,2);
    head = InsertLinklist(head,1);
    head = InsertLinklist(head,5); 
    head = InsertLinklist(head,0); 
    print(head);
    Solution s;
    head = s.insertionSortList(head);
    print(head);

    return 0;
}

