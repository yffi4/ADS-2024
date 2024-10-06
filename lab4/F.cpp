#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x) : val(x), right(nullptr), left(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val){
    if(!root){
        return new TreeNode(val);
    }
    if (val < root->val)
    {
        root->left = insert(root->left, val);
    }else{ 
        root->right = insert(root->right, val);
    }
    return root;
}
int countTriangles(TreeNode* root){
    if (root == nullptr)
    {
        return 0;
    }
    int count = countTriangles(root->left) + countTriangles(root->right);
   
    if (root->right != nullptr && root->left != nullptr)
    {
        count++;
    }
    return count;
}
int main(){
    int n; cin >> n;
    TreeNode* root = nullptr;
    for (int i = 0; i < n; i++)
    {
        int value; cin >> value;
        root = insert(root, value);
    }
    cout << countTriangles(root) << endl;
    return 0;
}