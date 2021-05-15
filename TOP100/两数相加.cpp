#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode *head=nullptr,*tail=nullptr;
        // 设置进位
        int carry=0;
        while(l1||l2){
            int n1 = l1?l1->val:0;
            int n2 = l2?l2->val:0;
            int sum = n1+n2+carry;
            if(!head){
                head = tail = new ListNode(sum%10);
            }
            else{
                tail->next = new ListNode(sum%10);
                tail = tail->next;
            }
            carry = sum/10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        // 循环结束后，可能仍然存在进位
        if(carry>0) tail->next = new ListNode(carry);
        return head;
    }
};

// 我的版本
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 虚头节点
        ListNode* res=new ListNode(0);
        ListNode* cur = res;
        int sum=0;  //进位
        while(l1||l2){
            int num = l1->val+l2->val+sum;
            sum = num /10;
            cur->next = new ListNode(num%10);
            l1 = l1->next;
            l2 = l2->next;
            cur = cur->next;
        }
        while(l1!=nullptr){
            int num = l1->val+sum;
            sum = num /10;
            cur->next = new ListNode(num%10);
            l1 = l1->next;
            cur = cur->next;
        }
        while(l2!=nullptr){
            int num = l2->val+sum;
            sum = num /10;
            cur->next = new ListNode(num%10);
            l2 = l2->next;
            cur = cur->next;
        }
        if(sum!=0) cur->next = new ListNode(sum);
        return res->next;
    }
};

class reviewSol{
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        bool carry=false;
        int sum=0;
        while(l1||l2){
            sum=0;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            if(carry){
                sum++;
            }
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            carry = sum>=10?true:false;
        }
        if(carry){
            cur->next = new ListNode(1);
        }
        return head->next;
    }
};