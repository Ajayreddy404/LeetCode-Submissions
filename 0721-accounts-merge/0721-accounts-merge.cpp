class Solution {
public:

    void travelGraph(vector<vector<int>>& grp, int node, vector<bool>& vis, set<string>& emailList, vector<vector<string>>& accounts){
        if(vis[node])   return;
        vis[node] = true;
        // push_bacnk all email
        for(int i=1; i<accounts[node].size(); i++){
            emailList.insert(accounts[node][i]);
        }
        for(auto nd: grp[node]){
            travelGraph(grp, nd, vis, emailList, accounts);
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // make a undirected graph of indices, connect 2 nodes if any common email is found
        // use un_ordered Map of email -> index for the above purpose 
        
        vector<vector<int>> grp(accounts.size(), vector<int>());

        unordered_map<string, int> emailToIndexMap;
        for(int index = 0; index<accounts.size(); index++){
            vector<string> account = accounts[index];
            for(int i=1; i<account.size(); i++){
                if(emailToIndexMap.find(account[i])==emailToIndexMap.end()){
                    emailToIndexMap[account[i]] = index;
                }else{
                    grp[index].push_back(emailToIndexMap[account[i]]);
                    grp[emailToIndexMap[account[i]]].push_back(index);
                }
            }
        }

        vector<vector<string>> ans;
        // traverse each connected comoonent and form result vector
        vector<bool> vis(accounts.size(),false);
        for(int i=0; i<accounts.size(); i++){
            if(vis[i])  continue;

            set<string> emailList;
            travelGraph(grp, i, vis, emailList, accounts);
            // sort(emailList.begin(), emailList.end());

            ans.push_back({accounts[i][0]});  // name
            // ans.back().push_back(emailList.begin(), emailList.end());   // emails
            for(auto email: emailList){
                ans.back().push_back(email);
            }
        }

        return ans;

    }
};