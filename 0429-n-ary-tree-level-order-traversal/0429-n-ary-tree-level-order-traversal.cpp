/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void levelOrderTravarsal(Node*root,vector<vector<int>>&ans){
        if(root==NULL)return;
        queue<Node*>q;
        vector<int>level;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* front= q.front();
            q.pop();
            if(front==NULL){
                ans.push_back(level);
                level.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
               level.push_back(front->val);
               for(int i=0;i<front->children.size();i++){
                     q.push(front->children[i]);
               }
            }

        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        levelOrderTravarsal(root,ans);
        return ans;
    }
};