#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

struct TrieNode{
    int passValue;
    int endValue;
    TrieNode* nexts[26];
    TrieNode(){
        passValue = 0;
        endValue = 0;
        for(int i=0;i<26;i++){
            nexts[i] = NULL;
        }
    }
};
class TrieTree{
    TrieNode *root;
public:
    TrieTree(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode *node = root;
        if(word.size()==0){
            return;
        }
        node->passValue++;
        int path;
        for(int i=0;i<word.size();i++){
            path = word[i] - 'a';
            if(node->nexts[path]==NULL){
                node->nexts[path]=new TrieNode();
            }
            node = node->nexts[path];
            node->passValue++;
        }
        node->endValue++;
    }
    void deleteStr(string word){
        if(!this->search(word)){
            return;
        }
        TrieNode *node = root;
        node->passValue--;
        int path;
        TrieNode *a = NULL;
        int deleteIndex = -1;
        unordered_set<TrieNode*> deleteSet;
        for(int i=0;i<word.size();i++){
            path = word[i] - 'a';
            node->nexts[path]->passValue--;
            if(node->nexts[path]->passValue == 0){
                a = a==NULL?node:a;
                deleteIndex = deleteIndex==-1?path:deleteIndex;
                deleteSet.insert(node->nexts[path]);
            }
            node = node->nexts[path];
        }
        node->endValue--;
        a->nexts[deleteIndex]=NULL;
        //~
        for(auto p=deleteSet.begin();p!=deleteSet.end();p++){
            TrieNode *temp;
            temp = *p;
            delete temp;
        }
    }
    int search(string word){
        if(word.size()==0){
            return 0;
        }
        TrieNode *node = root;
        int path;
        for(int i=0;i<word.size();i++){
            path = word[i] - 'a';
            if(node->nexts[path]==NULL){
                return 0;
            }
            node = node->nexts[path];
        }
        return node->endValue;
    }
    int prefixNumber(string pre){
        if(pre.size()==0){
            return 0;
        }
        TrieNode *node = root;
        int path;
        for(int i=0;i<pre.size();i++){
            path = pre[i] - 'a';
            if(node->nexts[path]==NULL){
                return 0;
            }
            node = node->nexts[path];
        }
        return node->passValue;
    }
};
int main(){
    string str = "abc";
    TrieTree tree;
    tree.insert(str);
    cout<<tree.search(str)<<endl;
    cout<<tree.prefixNumber("ab")<<endl;
    tree.deleteStr(str);
    cout<<tree.search(str)<<endl;
    cout<<tree.prefixNumber("a")<<endl;
    return 0;
}