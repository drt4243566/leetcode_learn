#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    struct node{
        int key;
        int val;
        node* next;
        node* pre;
        node(int k,int v):key(k),val(v){}
    };
    
    struct doubleLink{
    public:
        node* head;
        node* tail;
        doubleLink(){
            this->head = nullptr;
            this->tail = nullptr;
        }
        // 新增元素 add方法，加到tail之后，注意是双向链表
        void addNode(node* newNode){
            if(newNode==nullptr) return;
            if(head==nullptr){
                head = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                newNode->pre = tail;
                tail = newNode;
            }
        }
        
        // 将当前元素移动到tail，先取下当前节点，再进行移动
        void moveToTail(node* curNode){
            if(curNode==tail) return;
            if(head==curNode){
                head = head->next;
                head->pre = nullptr;
            }else{
                curNode->pre->next = curNode->next;
                curNode->next->pre = curNode->pre;
            }
            curNode->pre = tail;
            curNode->next = nullptr;
            tail->next = curNode;
            tail = curNode;
        }
        // 去掉最不经常使用的结点
        node* removeHead(){
            if(head==nullptr) return nullptr;
            // 只有一个元素结点
            node* res = head;
            if(head==tail){
                head = nullptr;
                tail = nullptr;
            }else{
                head = head->next;
                res->next = nullptr;
                head->pre = nullptr;
            }
            return res;
        }
    };
    
    struct mycache{
        doubleLink* lists;
        unordered_map<int, node*> dic;
        int cap;
        
        mycache(int c){
            if(c<1){
                throw("wrong cap");
            }
            cap = c;
            lists = new doubleLink();
        }
        
        int get(int key){
            if(dic.find(key)!=dic.end()){
                node* res = dic[key];
                lists->moveToTail(res);
                return res->val;
            }else{
                return -1;
            }
        }

        void set(int key,int val){
            if(dic.find(key)!=dic.end()){
                node* t = dic[key];
                t->val = val;
                lists->moveToTail(t);
            }else{
                node* newNode = new node(key,val);
                lists->addNode(newNode);
                dic[key] = newNode;
                if(dic.size()==cap+1){
                    node* del = lists->removeHead();
                    dic.erase(del->key);
                }
            }
        }
    };
    
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        // write code here
        mycache* cache = new mycache(k);
        vector<int> res;
        for(int i=0;i<operators.size();i++){
            if(operators[i][0]==1){
                cache->set(operators[i][1],operators[i][2]);
            }else if(operators[i][0]==2){
                int status = cache->get(operators[i][1]);
                res.push_back(status);
            }
        }
        return res;
    }
    
    
};