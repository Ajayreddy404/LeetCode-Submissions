/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)  return NULL;
        queue<Node*> qu;
        qu.push(root);
        while(!qu.empty()){
            int sz = qu.size();
            while(sz--){
                Node* node = qu.front();
                qu.pop();
                if(sz==0){
                    node->next = NULL;
                }else{
                    node->next = qu.front();
                }
                if(node->left)  qu.push(node->left);
                if(node->right) qu.push(node->right);
            }
        }
        return root;
    }
};