class Solution {
    // [-1,0,1,2,-1,-4]
    // -4, -1, -1, 0, 1, 2 
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        int n = nums.length;
        for(int i=0; i<n; ){
            int j=i+1, k=n-1;
            while(j<k){
                int cSum = nums[i] + nums[j] + nums[k];
                if(cSum<0){
                    int j1 = j;
                    while(j1<k && j1<n && nums[j1]==nums[j]) j1++;
                    j = j1;
                }
                else if(cSum>0){
                    int k1 = k;
                    while(k1>j && k1>=0 && nums[k1]==nums[k]) k1--;
                    k = k1;
                }
                else{
                    List<Integer> lst = new ArrayList<>(Arrays.asList(nums[i], nums[j], nums[k]));
                    result.add(lst);
                    int j1 = j;
                    while(j1<k && j1<n && nums[j1]==nums[j]) j1++;
                    j = j1;
                    int k1 = k;
                    while(k1>j && k1>=0 && nums[k1]==nums[k]) k1--;
                    k = k1;
                }
            }
            int i1 = i;
            while(i1<n && nums[i1]==nums[i])    i1++;
            i = i1;
        }
        return result;
    }
}