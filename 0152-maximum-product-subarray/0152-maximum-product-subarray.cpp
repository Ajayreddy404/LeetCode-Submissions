class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = INT_MIN;
        int nprod = 1, cprod = 1;
        bool flag = true;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                flag = true;
                nprod = 1;
                cprod = 1;
                maxprod = max(maxprod, 0);
            }else{
                if(flag){  // encountering first -ve value
                    if(nums[i]<0)   flag = false;
                    nprod *= nums[i];
                    cprod *= nums[i];
                    maxprod = max(maxprod, cprod);
                }else{      // not the first negative number
                    cprod *= nums[i];
                    if(cprod<0)    maxprod = max(maxprod, cprod/nprod);
                    else    maxprod = max(maxprod, cprod);
                }
                
            }
            
            // maxprod = max(maxprod, cprod);
        }
        return maxprod;
    }
};