class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==0)    return -1;
        if(n==1)    return nums[0];
        if(nums[0]!=nums[1])    return nums[0];
        if(nums[n-1]!=nums[n-2])    return nums[n-1];
        int l = 1, r = n-2, mid;
        while(l<r){
            mid = (l+r)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }else if((nums[mid]==nums[mid-1] && mid%2==1) || (mid%2==0 && nums[mid]==nums[mid+1])){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return nums[l];
    }
};