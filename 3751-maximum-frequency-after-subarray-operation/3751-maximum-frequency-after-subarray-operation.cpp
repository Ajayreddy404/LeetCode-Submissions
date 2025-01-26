class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int kf = 0, max_x=0;
        for(auto x: nums){
            if(x==k)    kf++;
            max_x = max(max_x, x);
        }
        // cout<<kf<<endl;
        int ans = 0, ckmm = 0;
        for(int x=1; x<=max_x; x++){
            // cout<<"x: "<<x<<endl;
            if(x==k)    continue;
            int fq = 0, max_fq = 0, ck = 0, ckm = 0;
            for(int i=0; i<nums.size(); i++){
                
                if(nums[i]==k){
                    fq--;
                }
                else if(nums[i]==x){
                    fq++;
                }
                if(fq<=0){
                    fq = 0;
                    ck = 0;
                }
                if(max_fq<fq){
                    max_fq = fq;
                    ckm = ck;
                }
                // if(x==9)    cout<<i<<" "<<ck<<endl;
            }
            if(ans<max_fq){
                ans = max_fq;
                ckmm = ckm;
            }
            // cout<<max_fq<<" "<<ckm<<endl;
        }
        return ans+kf;
    }
};