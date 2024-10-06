#include <iostream>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) {
        return new TreeNode(key);
    }
    
    if (key < root->val) {
        root->left = insert(root->left, key); 
    } else if (key > root->val) {
        root->right = insert(root->right, key);  
    }
    
    return root;
}


pair<int, int> diameterAndHeight(TreeNode* root) {
    if (root == nullptr) {
        return {0, 0};  
    }


    auto left = diameterAndHeight(root->left);
    auto right = diameterAndHeight(root->right);

    int leftHeight = left.second;
    int rightHeight = right.second;
    int height = 1 + max(leftHeight, rightHeight);

    int diameter = max(left.first, max(right.first, leftHeight + rightHeight));

    return {diameter, height};  
}

int main() {
    int n;
    cin >> n;  

    TreeNode* root = nullptr;

    
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        root = insert(root, value);
    }

    
    int diameter = diameterAndHeight(root).first;

    
    cout << diameter  + 1 << endl;

    return 0;
}
