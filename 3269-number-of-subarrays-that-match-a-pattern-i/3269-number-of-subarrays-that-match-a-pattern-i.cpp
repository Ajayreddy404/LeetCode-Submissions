class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (j - i + 1 == m + 1) {
                    int l = i, flag = 0;
                    for (int k = 0; k < m; k++, l++) {
                        if ( (pattern[k] == 1 && nums[l + 1] > nums[l]) ||
                                (pattern[k] == 0 && nums[l + 1] == nums[l]) ||
                                (pattern[k] == -1 && nums[l + 1] < nums[l])     ) {
                            continue;
                        }else {
                            flag = 1;
                            break;
                        }
                    }

                    if (flag == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
