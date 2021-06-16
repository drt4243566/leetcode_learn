#include <iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
 };
void print(ListNode * head);
class PalindromeList {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    bool chkPalindrome(ListNode* head){
        if(head == NULL or head->next == NULL)
            return true;
        
        ListNode *fast, *slow;
        fast = slow = head;
        while(fast->next){
            fast = fast->next;
            if(fast->next){
                fast = fast->next;
            }
            slow = slow->next;
        }
        fast = reverseLinklist(slow);
        slow->next = NULL;
        ListNode *fastCopy = fast;
        ListNode *headCopy = head;
        int flag = 1;
        while(fastCopy){
            if(fastCopy->val != headCopy->val)
            {
                flag = 0;
                break;
            }
                
            else{
                fastCopy = fastCopy->next;
                headCopy = headCopy->next;
            }
        }
        reverseLinklist(fast);
        return flag;
    }
    ListNode* reverseLinklist(ListNode* head){
        if(head == NULL or head->next == NULL){
            return head;
        }
        ListNode *p, *q, *temp;
        p = head;
        q = head->next;
        p->next = NULL;
        while(q){
            temp = q->next;
            q->next = p;
            p = q;
            q = temp;
        }
        return p;

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
    head = InsertLinklist(head,2); 
    head = InsertLinklist(head,3); 
    head = InsertLinklist(head,4); 
    PalindromeList s;
    print(head);
    cout<< s.chkPalindrome(head)<<endl;
    print(head);

    return 0;
}

