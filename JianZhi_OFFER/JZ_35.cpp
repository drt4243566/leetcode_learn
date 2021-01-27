#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// 使用哈希表存储新旧节点间的对应关系
class Solution1 {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        Node* cur = head;
        unordered_map<Node*,Node*> dic;
        // 先复制一波节点(不管对应关系)
        while(cur){
            dic[cur] = new Node(cur->val);
            cur = cur->next;
        }
        // 建立新的连接关系
        cur = head;
        while(cur){
            dic[cur]->next = dic[cur->next];
            dic[cur]->random = dic[cur->random];
            cur = cur->next;
        }
        return dic[head];
    }
};

// 拼接拆分法 —— 形似画辅助线的方法
class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        Node* cur = head;
        // 1. 复制节点，构建拼接链表
        while(cur){
            Node* temp = new Node(cur->val);
            temp->next = cur->next;
            cur->next = temp;
            cur = temp->next;
        }
        // 2.构建random指向
        cur = head;
        while(cur){
            if(cur->random!=NULL){
                // 防止后半部分出现NULL->next;
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        // 3.拆分链表
        cur = head->next;
        Node* pre = head,*res = head->next;
        while(cur->next){
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = nullptr;
        return res;
    }
};