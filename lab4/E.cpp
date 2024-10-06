#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x) : val(x), right(nullptr), left(nullptr) {}
};

void insert(TreeNode* root, int parent, int child, int isRight){
    if(root == nullptr) return;
    if (root->val == parent)
    {
        if (isRight == 0)
        {
            root->left = new TreeNode(child);
        }else 
            root->right = new TreeNode(child);
        
    }else{
        insert(root->left, parent, child, isRight);
        insert(root->right, parent, child, isRight);
    }
    
    
}

void countWidth(TreeNode* root, vector<int>& levelCount, int level){
    if(root == nullptr) return;
    if (level == levelCount.size())
    {
        levelCount.push_back(1);
    }else{
        levelCount[level]++;
    }
    countWidth(root->left, levelCount, level + 1);
    countWidth(root->right, levelCount, level + 1);
    
    
}
int maxWidth(TreeNode* root) {
    vector<int> level_count;
    countWidth(root, level_count, 0);  
    return *max_element(level_count.begin(), level_count.end());
}

int main(){
    int n; cin >> n;
    TreeNode* root = new TreeNode(1);
    for (int i = 0; i < n - 1; ++i) {
        int parent, child, isRight;
        cin >> parent >> child >> isRight;
        insert(root, parent, child, isRight);  
    }

    
    cout << maxWidth(root) << endl;

    return 0;
}