class Solution {
public:

    bool static comp(string s1, string s2){
        return s1+s2 > s2+s1;
    }

    string largestNumber(vector<int>& nums) {
        string ans = "";
        vector<string> vec;
        for(auto x: nums){
            vec.push_back(to_string(x));
        }
        sort(vec.begin(), vec.end(), comp);
        bool flg = true;
        for(auto x: vec){
            if(flg && x=="0")   continue;
            flg = false;
            ans += x;
        }
        if(ans=="") ans = "0";
        return ans;
    }
};