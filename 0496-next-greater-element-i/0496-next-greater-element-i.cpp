class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> ump;
        vector<int> arr(nums2.size());
        st.push(-1);
        for(int i=nums2.size()-1; i>=0; i--){
            ump[nums2[i]] = i;
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(st.size()==0)    st.push(-1);
            arr[i] = st.top();
            st.push(nums2[i]);
        }

        vector<int> ans(nums1.size());
        for(int i=0; i<nums1.size(); i++){
            int ind = ump[nums1[i]];
            ans[i] = arr[ind];
        }

        return ans;
    }
};