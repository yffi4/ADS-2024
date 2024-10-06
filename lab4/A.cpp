#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

TreeNode* insertBst(TreeNode* root, int val){
    if (!root)
    {
        return new TreeNode(val);
    }
    if (val < root->val)
    {
        root->left = insertBst(root->left, val);
    }else root->right = insertBst(root->right, val);
    
    return root;
}

bool checkPath(TreeNode* root, string path){
    TreeNode* current = root;
    for (char direction : path)
    {
        if (!current)
        {
            return false;
        }
        if (direction == 'L')
        {
            current = current->left;
        }else current = current->right;
    
        
    }
    return current != NULL;
    
    
}

int main(){
    int n, m; cin >> n >> m;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    vector<string> pathes(m);
    for (int i = 0; i < m; i++)
    {
        cin >> pathes[i];
    }
    TreeNode* root = NULL;
    for (int val : numbers)
    {
        root = insertBst(root, val);
    }
    for (string path : pathes)
    {
        if (checkPath(root, path))
        {
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
    }
    return 0;
    
}