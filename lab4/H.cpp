#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int key) {
    if (!root) {
        return new TreeNode(key);
    }
    if (key < root->val) {
        root->left = insert(root->left, key);
    } else if (key > root->val) {
        root->right = insert(root->right, key);
    }
    return root;
}

void replaceWithGreaterSum(TreeNode* root, int& sum) {
    if (!root) return;
    
    
    replaceWithGreaterSum(root->right, sum);
    
    
    sum += root->val;
    root->val = sum;
    
    
    replaceWithGreaterSum(root->left, sum);
}


void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
}

int main() {
    int n;
    cin >> n;  

    TreeNode* root = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    int sum = 0;

    replaceWithGreaterSum(root, sum);

    vector<int> result;
    inorderTraversal(root, result);
    reverse(result.begin(), result.end());
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
