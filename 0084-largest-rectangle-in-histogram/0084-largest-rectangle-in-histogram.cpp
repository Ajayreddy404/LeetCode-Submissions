class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        int area = 0;
        // for(int i=0; i<heights.size(); i++){
        //     int minH = INT_MAX;
        //     int carea = 0;
        //     for(int j=i; j<heights.size(); j++){
        //         minH = min(minH, heights[j]);
        //         carea = minH * (j-i+1);
        //         area = max(carea, area);
        //         // cout<<i<<" "<<j<<" "<<carea<<endl;
        //     }
        // }

        // finding the left and right rectangle areas considering 
        // the current element is the minH of all the heights in this rectangle
        int n = H.size();
        vector<int> lmax(n), rmax(n);
        stack<int> st;  // store indices of elements, so that elemets are in strictly incr ord
        // st.push();
        for(int i=0; i<n; i++){
            while(st.size()>0 && H[st.top()]>=H[i])  st.pop();
            lmax[i] = (st.size()>0)? H[i]*(i-st.top()) : H[i]*(i+1);
            //if(st.size()>0 && H[st.top()]!=H[i]) 
            st.push(i);
        }
        while(st.size()>0) st.pop();
        for(int i=n-1; i>=0; i--){
            while(st.size()>0 && H[st.top()]>=H[i])  st.pop();
            rmax[i] = (st.size()>0)? H[i]*(st.top()-i) : H[i]*(n-i);
            //if(st.size()>0 && H[st.top()]!=H[i])
                st.push(i);
        }

        for(int i=0; i<n; i++){
            area = max(area, lmax[i]+rmax[i]-H[i]);
            // cout<<lmax[i]<<" ";
        }cout<<endl;

        // for(int i=0; i<n; i++){
            // area = max(area, lmax[i]+rmax[i]-H[i]);
        //     cout<<rmax[i]<<" ";
        // }cout<<endl;

        return area;
    }
};