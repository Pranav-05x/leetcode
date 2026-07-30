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
    void levelOrderTraversal(TreeNode*root,int &highLevel){
        if(root==NULL)return;

        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int level=0;
        int maxi=INT_MIN;
        int sum=0;
        while(!q.empty()){
           TreeNode*front=q.front();
           q.pop();
           if(front==NULL){
             level++;
             if(maxi<sum){
                maxi=sum;
                highLevel=level;
              }
             sum=0;
             if(!q.empty()){
                q.push(NULL);
             }
           }
           else{
              sum+=front->val;
              if(front->left!=NULL){
                q.push(front->left);
              }
              if(front->right!=NULL){
                q.push(front->right);
              }
           }
        }
    }
    int maxLevelSum(TreeNode* root) {
        int highLevel=0;
        levelOrderTraversal(root,highLevel);
        return highLevel;
    }
};