#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};
        queue<TreeNode *> q;
        vector<vector<int>> res;
        q.push(root);
        int order=0;                // order为0从左到右，为1则反向
        while (!q.empty())
        {
            vector<int> temp;
            for (int i = q.size(); i > 0; i--)
            {
                TreeNode *cur = q.front();
                q.pop();
                temp.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            if(order) reverse(temp.begin(),temp.end());
            order = 1-order;
            res.push_back(temp);
        }
        return res;
    }
};
// temp使用双端队列
class Solution1
{
public:
    vector<vector<int>> levelOrder(TreeNode *root){
        if(root==NULL) return{};
        queue<TreeNode *> q;
        vector<vector<int>> res;
        q.push(root);
        while (!q.empty())
        {
            deque<int> temp;
            for (int i = q.size(); i > 0; i--)
            {
                TreeNode *cur = q.front();
                q.pop();
                if(res.size()%2==1){
                    temp.push_front(cur->val);      //奇数从头部添加，倒序
                }
                else{
                    temp.push_back(cur->val);       //偶数从尾部添加，正序
                }
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            res.push_back(vector<int>(temp.begin(),temp.end()));
        }
        return res;
    }
};

// q使用双端队列的解法
class Solution2{
public:
    vector<vector<int>> levelOrder(TreeNode *root){
        if(root==NULL) return{};
        deque<TreeNode *> q;
        vector<vector<int>> res;
        q.push_back(root);
        while (!q.empty())
        {
            vector<int> temp;
            for (int i = q.size(); i > 0; i--)
            {
                // 奇数层
                TreeNode *cur = q.front();
                q.pop_front();
                temp.push_back(cur->val);
                // 作用于下一层的节点顺序
                if (cur->left) q.push_back(cur->left);
                if (cur->right) q.push_back(cur->right);
            }
            res.push_back(temp);
            // 中间必须要进行结束判断
            if(q.empty()) break;
            temp.clear();
            // 偶数层
            for (int i = q.size(); i > 0; i--){
                TreeNode *cur = q.back();
                q.pop_back();
                temp.push_back(cur->val);
                if (cur->right) q.push_front(cur->right);
                if (cur->left) q.push_front(cur->left);
            }
            res.push_back(temp);
        }
        return res;
    }
};

// 双端队列deque比较神奇，正常阅读顺序可以理解为从上到下，当push_back()时，数据正序，从高到底依次为123，但是push_front()则为倒序；
// 当和pop()指令对应时，如果front对front，理解为栈结构，反之为队列；

int main(){
    
}