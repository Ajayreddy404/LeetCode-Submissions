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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> mp;
        
        queue<pair<TreeNode*, int>> qu;
        qu.push({root, 0});

        while(!qu.empty()){

            int n = qu.size();
            map<int, vector<int>> mp2; 
            while(n--){
                TreeNode* node = qu.front().first;
                int i = qu.front().second;
                qu.pop();
                if(node->left!=NULL)    qu.push({node->left, i-1});
                if(node->right!=NULL)    qu.push({node->right, i+1});

                if(mp2.find(i)==mp2.end())    mp2[i] = {node->val};
                else    mp2[i].push_back(node->val);
            }

            for(auto p2: mp2){
                vector<int> v = p2.second;
                sort(v.begin(), v.end());
                if(mp.find(p2.first)==mp.end()){
                    mp[p2.first] = v;
                }else{
                    for(auto x: v)  mp[p2.first].push_back(x);
                    // mp[p2.first].insert(mp[p2.first],v.begin(),v.end());
                }
            }


            
            // if(mp.find(i)==mp.end())    mp[i] = {{i,node->val}};
            // else{
            //     for(auto x: temp)   mp[i].push_back(x);
            // }
            
        }


        vector<vector<int>> arr;
        for(auto p: mp){
            // vector<int> t = p.second;
            // sort(t.begin(),t.end());
            // vector<int> t1;
            // for(auto p1: t){
            //     t1.push_back(p1.second);
            // }
            arr.push_back(p.second);
        }
        return arr;
    }
};