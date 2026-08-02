/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int getIndex(int element,vector<int>inorder){
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]==element){
            return i;
        }
    }
    return -1;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,int &preOrderIndex,int inOrderStart,int inOrderEnd){
        if(preOrderIndex >=preorder.size()){
            return NULL;
        }
        if(inOrderStart>inOrderEnd){
            return NULL;
        }

        //main Logic
        int element=preorder[preOrderIndex];
        preOrderIndex++;
        
        TreeNode* root=new TreeNode(element);
        int elementIndexInsideInorder=getIndex(element,inorder);

        root->left=buildTree(preorder,inorder,preOrderIndex,inOrderStart,elementIndexInsideInorder-1);
        root->right=buildTree(preorder,inorder,preOrderIndex,elementIndexInsideInorder+1,inOrderEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex=0;
        int inOrderStart=0;
        int inOrderEnd=inorder.size()-1;
        TreeNode*root=buildTree(preorder,inorder,preOrderIndex, inOrderStart, inOrderEnd);
        return root;
    }
};