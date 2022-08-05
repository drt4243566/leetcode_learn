#include <iostream>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    struct pack{
        int val;
        ListNode* ptr;

        bool operator<(const pack& rhs) const{
            return val > rhs.val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        priority_queue<pack> q;
        int k = lists.size();
        for(int i=0;i<k;i++){
            q.push({lists[i]->val,lists[i]});
        }
        ListNode dummy;
        ListNode* cur = &dummy;
        while(!q.empty()){
            ListNode* next = q.top().ptr;
            q.pop();
            cur->next = next;
            cur = cur->next;
            if(next->next!=nullptr) q.push({next->next->val,next->next});
        }
        return dummy.next;
    }
};

int main(){
    char a = 2;
    char b = 1;
    priority_queue<int> q;
    q.push(1);
    int t = q.top();
    int c = (((int)a)<<8)+b;
    cout << c <<endl;
    return 0;
}

