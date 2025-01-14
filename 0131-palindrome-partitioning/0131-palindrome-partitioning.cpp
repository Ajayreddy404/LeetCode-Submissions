class Solution {
public:

    bool isPal(int i, int j, string &s){
        while(i<=j){
            if(s[i]!=s[j])  return false;
            i++;
            j--;
        }
        return true;
    }

    void rec(int l, vector<vector<string>> &ans, vector<string> &pals, string &s){
        if(l==s.size()){
            ans.push_back(pals);
            return;
        }
        // if(l>r) return;
        for(int mid=l; mid<s.size(); mid++){
            if(isPal(l,mid,s)){
                pals.push_back(s.substr(l, mid-l+1));
                rec(mid+1, ans, pals, s);
                pals.pop_back();
            }

        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> pals;
        rec(0,ans, pals, s);
        return ans;
    }
};