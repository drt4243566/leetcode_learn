#include<iostream>
#include<vector>

using namespace std;

 struct ListNode {
	int val;
	struct ListNode *next;
  };

 ListNode* add(ListNode* head, int element);

/*class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {           //���ַ���������ջ���ù��࣬��δ���
        // write code here
        if (head == nullptr || head->next == nullptr)      //���������ֻ��һ����㣬ֱ�ӷ���
            return head;
        ListNode* p_current = head->next, * p_last = head;
        while (p_current != nullptr) {
            if (p_current->val >= p_last->val) {                  //��δ�������һ�������ڵ�����һ����ʱ������������������
                p_last = p_current;
                p_current = p_current->next;
            }
            else {
                if (p_current->val < head->val) {
                    head->next = p_current->next;
                    p_current->next = head;
                    head = p_current;
                    p_current = head->next;
                }
                else {
                    p_last->next = p_current->next;                         // ����������һ�䣬����Ҫ�Ƚ�p_curren����һ����㴫�ݸ�p_last
                    ListNode* p_front = head;
                    while (p_front != p_last) {                                    //����ǰ���ֲ��뵽���򲿷�
                        if (p_front->next->val > p_current->val) {      //�������ʱ�����������ַ����Ҳ�
                            p_current->next = p_front->next;
                            p_front->next = p_current;
                            break;
                        }
                        else
                            p_front = p_front->next;                                    //�����������������������ʱ�������ݽ�
                    }
                    p_current = p_last->next;
                }
            }
        }
        return head;
    }
};*/

 class Solution {
 public:
     ListNode* insertionSortList(ListNode* head) {
         if (head == NULL or head->next == NULL)                    //���������ֻ��һ����㣬ֱ�ӷ���
             return head;
         ListNode* newhead = new ListNode;
         newhead->next = nullptr;
         newhead->val = -1;
         ListNode* p_front = newhead, *q = head,*p_current=head;
         while (p_current != nullptr) {
             q = p_current->next;
             while (p_front->next != nullptr && p_front->next->val < p_current->val) {
                 p_front=p_front->next;
             }
             p_current->next = p_front->next;
             p_front->next = p_current;
             p_front = newhead;                                         //��Ҫ����ÿ��ѭ��������ָ������
             p_current = q;
         }
         return newhead->next;
     }
 };

int main() {
    ListNode* myList = nullptr;
    int element=1;
    while (cin >> element) {
        if (element == -1)
            break;
        else {
            myList = add(myList,element);
        }
    }     

    Solution sol;
    myList = sol.insertionSortList(myList);

    //����������ϵ�ÿ�����
    ListNode* Cur = myList;
    while (Cur !=nullptr){
        cout << Cur->val << " ";
        Cur = Cur->next;
    }
    cout << endl;
    return 0;
}

ListNode* add(ListNode* head, int element) {
    ListNode* Ele = new ListNode;           //�����½��
    Ele->val = element;
    Ele->next = NULL;
    if (head == nullptr) {
        head = Ele;
    }
    else {
        ListNode* p = head;
        while(p->next!=nullptr){
            p = p->next;                                //�����������ת����һ����㣬�������ѭ��
        }
        p->next = Ele;
    }
    return head;
}