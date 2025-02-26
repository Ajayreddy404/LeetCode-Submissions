class Solution {
public:

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int len = 1, cnt=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]){
                len++;
            }else{
                if(len>=k) cnt++;
                else{
                    cnt = 0;
                }
                len = 1;
            }
            if((cnt==1 && len>=k) || cnt==2 || len>=2*k) return true;
        }
        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int l=1, r=nums.size();
        while(l<r){
            int mid = (l+r)/2;
            if(hasIncreasingSubarrays(nums, mid)){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return l-1;
    }
};