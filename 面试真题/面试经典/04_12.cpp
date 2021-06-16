#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*class Solution {
public:
    unordered_map<int,int>

    int pathSum(TreeNode* root, int sum) {

    }
};*/