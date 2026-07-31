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
    void levelOrderTraversal(TreeNode*root,vector<double>&ans){
        if(root==NULL)return;

        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        double totalNum=0;
        double sum=0;
        while(!q.empty()){
            TreeNode*front=q.front();
            q.pop();
            if(front==NULL){
                ans.push_back(sum/totalNum);
                sum=0;
                totalNum=0;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                sum+=front->val;
                totalNum++;
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        levelOrderTraversal(root,ans);
        return ans;
    }
};