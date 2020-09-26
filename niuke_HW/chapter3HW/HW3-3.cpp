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
    ListNode* insertionSortList(ListNode* head) {           //此种方法报错，堆栈调用过多，暂未解决
        // write code here
        if (head == nullptr || head->next == nullptr)      //空链表或者只有一个结点，直接返回
            return head;
        ListNode* p_current = head->next, * p_last = head;
        while (p_current != nullptr) {
            if (p_current->val >= p_last->val) {                  //当未排序的下一个数大于等于上一个数时，无需启动插入排序
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
                    p_last->next = p_current->next;                         // 曾经忽略这一句，必须要先将p_curren的下一个结点传递给p_last
                    ListNode* p_front = head;
                    while (p_front != p_last) {                                    //将当前数字插入到有序部分
                        if (p_front->next->val > p_current->val) {      //暗含相等时，后来的数字放在右侧
                            p_current->next = p_front->next;
                            p_front->next = p_current;
                            break;
                        }
                        else
                            p_front = p_front->next;                                    //曾经出过错，不满足插入条件时，继续递进
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
         if (head == NULL or head->next == NULL)                    //空链表或者只有一个结点，直接返回
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
             p_front = newhead;                                         //不要忽略每次循环结束将指针重置
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

    //输出单链表上的每个结点
    ListNode* Cur = myList;
    while (Cur !=nullptr){
        cout << Cur->val << " ";
        Cur = Cur->next;
    }
    cout << endl;
    return 0;
}

ListNode* add(ListNode* head, int element) {
    ListNode* Ele = new ListNode;           //申请新结点
    Ele->val = element;
    Ele->next = NULL;
    if (head == nullptr) {
        head = Ele;
    }
    else {
        ListNode* p = head;
        while(p->next!=nullptr){
            p = p->next;                                //这里如果不跳转到下一个结点，会进入死循环
        }
        p->next = Ele;
    }
    return head;
}