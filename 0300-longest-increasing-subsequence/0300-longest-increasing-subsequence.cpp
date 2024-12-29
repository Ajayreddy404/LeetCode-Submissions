class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        vector<int> arr;
        arr.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>arr.back()){
                arr.push_back(nums[i]);
            }else{
                auto it = lower_bound(arr.begin(), arr.end(), nums[i]);
                int indx = it-arr.begin();
                // cout<<indx<<" "<<*it<<" "<<nums[i]<<endl;
                arr[indx] = nums[i];
            }
        }
        return arr.size();
    }
};