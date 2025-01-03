class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // displacing the nums1 to the end
        for(int i=m+n-1; i>=n; i--){
            nums1[i] = nums1[i-n];
        }

        int i=n, j=0, k=0;
        while(i<m+n || j<n){
            if(i<m+n && j<n){
                if(nums1[i]<=nums2[j]){
                    nums1[k] = nums1[i];
                    i++;
                }else{
                    nums1[k] = nums2[j];
                    j++;
                }
            }else if(i<m+n){
                nums1[k] = nums1[i];
                i++;
            }else if(j<n){
                nums1[k] = nums2[j];
                j++;
            }
            k++;
        }

        return;
    }
};