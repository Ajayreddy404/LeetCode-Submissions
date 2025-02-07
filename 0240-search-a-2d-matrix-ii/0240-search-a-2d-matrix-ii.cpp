class Solution {
public:

    int findTarget(int st, int en, vector<int>& arr, int target){
        int l = st, r = en;
        while(l<r){
            int mid = (l+r)/2;
            if(arr[mid]>=target){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return r;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st = 0, en = matrix[0].size()-1;
        for(int i=0; i<matrix.size(); i++){
            // for(int j=0; j<matrix[i].size(); j++){

                // cout<<st<<" "<<en<<endl;
                int idx = findTarget(st, en, matrix[i], target);
                if(matrix[i][idx]==target)  return true;
                // cout<<idx<<endl;
                en = idx;
            // }
        }
        return false;
    }
};