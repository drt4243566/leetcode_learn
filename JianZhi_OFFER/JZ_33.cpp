#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 递归解法，先寻找左右子树的边界（根节点必然在区间的右边界），然后验证右子树是否全部小于根节点
class Solution1 {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return recur(postorder,0,postorder.size()-1);
    }
    bool recur(vector<int> &postorder,int i,int j){
        if(i>=j) return true;
        int p=i;
        // 左子树小于根节点
        while(postorder[p]<postorder[j]){
            p++;
        }
        int m = p;                      // 右子树第一个节点
        // 右子树保证大于根节点
        while(postorder[p]>postorder[j]){
            p++;
        }
        return p==j && recur(postorder,i,m-1) && recur(postorder,m,j-1);
    }
};

// 单调栈解法： 递增入辅助栈，出现递减节点时要将栈内元素弹出；
// 思路来源于先序遍历的根-左-右，
// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/solution/dan-diao-di-zeng-zhan-by-shi-huo-de-xia-tian/
class Solution2{
public:
    bool verifyPostorder(vector<int> &postorder){
        stack<int> stack;
        int root = INT_MAX;
        for(int i=postorder.size()-1;i>=0;i--){
            // 左子树大于根节点
            if(postorder[i]>root) return false;
            while(!stack.empty()&&stack.top()>postorder[i]){
                root = stack.top();
                stack.pop();
            }
            stack.push(postorder[i]);
        }
        return true;
    }
};