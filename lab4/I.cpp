#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    int count;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), count(1), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    } else {
        root->count++;
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int val) {
    if (root == nullptr) return nullptr;
    if (val < root->val) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->val) {
        root->right = deleteNode(root->right, val);
    } else {
        if (root->count > 1) {
            root->count--;
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                TreeNode* temp = root->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                root->val = temp->val;
                root->count = temp->count;
                temp->count = 1;
                root->right = deleteNode(root->right, temp->val);
            }
        }
    }
    return root;
}

int countNode(TreeNode* root, int val) {
    if (root == nullptr) return 0;
    if (val < root->val) {
        return countNode(root->left, val);
    } else if (val > root->val) {
        return countNode(root->right, val);
    } else {
        return root->count;
    }
}

int main() {
    int Q;
    cin >> Q;
    TreeNode* root = nullptr;
    while (Q--) {
        string query;
        int val;
        cin >> query >> val;
        if (query == "insert") {
            root = insert(root, val);
        } else if (query == "delete") {
            root = deleteNode(root, val);
        } else if (query == "cnt") {
            cout << countNode(root, val) << endl;
        }
    }
    return 0;
}