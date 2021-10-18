#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class node{
public:
    int key;
    int value;
    node* last;
    node* next;
    node(int k,int v):key(k),value(v){}
    node(){}
}

class doubleDirectorList{
public:
    node* head;
    node* tail;
    
    void addNewNode(node* newNode){
        if(newNode==nullptr) return;
        if(head==nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->last = tail;
            tail = newNode;
        }
    }
    void move2tail(node* curNode){
        if(curNode==tail) return;
        if(curNode==head){
            head = head->next;
            head->last = nullptr;
        }
        else{
            curNode->last->next = curNode->next;
            curNode->next->last = curNode->last;
        }
        curNode->last = tail;
        curNode->next = nullptr;
        tail->next = curNode;
        tail = curNode;
    }
    node* removeHead(){
        node* res = head;
        if(head==tail){
            head = nullptr;
            tail = nullptr;
        }
        else{
            head = head->next;
            head->last = nullptr;
            res->next = nullptr;
        }
        return res;
    }
}

class LRU{
    unordered_map<int,node*> mp;
    doubleDirectorList nodeList;
    int capacity;
public:
    void initCap(int cap){
        capacity = cap;
    }
    int get(int key){
        int res = -1;
        if(mp.find(key)==mp.end()) return res;
        else{
            res = mp[key]->value;
            nodeList.move2tail(mp[key]);
        }
        return res;
    }
    void set(int key,int value){
        if(mp.find(key)!=mp.end()){
            mp[key]->value = value;
            nodeList.move2tail(mp[key]);
        }
        else{
            node* newNode = new node(key,value);
            nodeList.addNewNode(newNode);
            if(nodeList.tail-nodeList.head+1>capacity){
                nodeList.removeHead();
                mp.erase(key);
            }
        }
    }
}

int main(){
    
}