class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int j=1; j<strs.size(); j++){
            string word = strs[j];
            int i = 0;
            for( ; i<word.length() && i<ans.length(); i++){
                if(ans[i]!=word[i]) break;
            }
            while(ans.size() > i){
                ans.pop_back();
            }
        }
        return ans;
    }
};