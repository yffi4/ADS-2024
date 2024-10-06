#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

TreeNode* insertData(TreeNode* root, int data){
    if (!root)
    {
        return new TreeNode(data);
    }
    if (data < root->val)
    {
        root->left = insertData(root->left, data);
    }else {
        root->right = insertData(root->right, data);
    }
    return root;
    
    
}
TreeNode* findNode(TreeNode* root, int data){
    if (!root || root->val == data)
    {
        return root;   
    }
    if (data < root->val)
    {
        return findNode(root->left, data);
    }else{
        return findNode(root->right, data);
    }
    
    
}

int counter(TreeNode* node){
    if(!node) return 0;
    return 1 + counter(node->left) + counter(node->right);
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];   
    }
    int k; cin >> k;
    TreeNode* root = NULL;
    for (int val : arr)
    {
        root = insertData(root, val);
    }
    TreeNode* targetNode = findNode(root, k);
    int subTree = counter(targetNode);
    cout << subTree << endl;
    return 0;
    
}