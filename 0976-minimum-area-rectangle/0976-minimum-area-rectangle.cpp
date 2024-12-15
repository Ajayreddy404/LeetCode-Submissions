class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int,vector<int>> mpx;
        map<int, set<int>> mpy;
        for(int i=0; i<points.size(); i++){
            vector<int> p = points[i];
            if(mpx.find(p[0])==mpx.end()){
                mpx[p[0]] = {p[1]};
            }else{
                mpx[p[0]].push_back(p[1]);
            }

            if(mpy.find(p[1])==mpy.end()){
                mpy[p[1]] = {p[0]};
            }else{
                mpy[p[1]].insert(p[0]);
            }
        }
        int areaVal = INT_MAX;
        for(auto mx: mpx){
            if(mx.second.size()>1){
                vector<int> arry = mx.second;
                for(int i=0; i<arry.size(); i++){
                    if(mpy.find(arry[i])==mpy.end() || mpy[arry[i]].size()<=1)  continue;
                    for(int j=i+1; j<arry.size(); j++){
                        if(mpy.find(arry[j])!= mpy.end() && mpy[arry[j]].size()>1){
                            // cout<<mx.first<<" "<<arry[i]<<" "<<arry[j]<<endl;
                            for(auto it: mpy[arry[i]]){
                                // cout<<it<<endl;
                                int vx = it;
                                if(vx == mx.first)    continue;
                                if(mpy[arry[j]].find(vx)!=mpy[arry[j]].end()){
                                    areaVal = min(areaVal, abs((vx-mx.first)*(arry[i]-arry[j])));
                                }
                            }
                        }
                    }
                }
            }
        }

        if(areaVal==INT_MAX)    return 0;
        return areaVal;
    }
};