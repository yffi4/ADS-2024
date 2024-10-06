#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};


TreeNode* insert(TreeNode* root, int value, int level, vector<int>& level_sum) {
    if (root == nullptr) {
        
        if (level >= level_sum.size()) {
            level_sum.push_back(0);
        }
        level_sum[level] += value;
        return new TreeNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value, level + 1, level_sum);
    } else {
        root->right = insert(root->right, value, level + 1, level_sum);
    }

    return root;
}

int main() {
    int n;  
    cin >> n;

    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        cin >> permutation[i];
    }

    
    vector<int> level_sum;

    TreeNode* root = nullptr;

    
    for (int i = 0; i < n; i++) {
        root = insert(root, permutation[i], 0, level_sum);
    }

    
    cout << level_sum.size() << endl;

    
    for (int i = 0; i < level_sum.size(); i++) {
        cout << level_sum[i] << " ";
    }

    return 0;
}
