class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode vHead(0), *p=&vHead;
       int flag=0;
       while(l1||l2||flag){
           int temp=0;
           if(l1!=nullptr) temp+=l1->val;
           if(l2!=nullptr) temp+=l2->val;
           temp+=flag;

           flag=temp/10;
           temp=temp%10;

           ListNode *next=new ListNode(temp);    //新建结点

           p->next=next;                         //链表的经典操作
           p=p->next;

           l1=l1?l1->next:nullptr;     //这里很有趣的一种遍历方式
           l2=l2?l2->next:nullptr;

       }
        return vHead.next;
    }
};