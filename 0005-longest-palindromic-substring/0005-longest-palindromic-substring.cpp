class Solution {
public:
    string longestPalindrome(string s) {
        // Manacher's algorith - bounding probelm
        string T = "@#";
        for(auto c: s){
            T += c;
            T += '#';
        }  
        T += '&';
        cout<<T<<endl;
        int n2 = T.length();
        vector<int> P(n2, 1);

        int C = 0, R = 0;
        for(int i=0; i<n2-1; i++){
            int iMirror = 2*C - i;
            if(i<R){    // already a bit of calc done
                P[i] = min(R-i, P[iMirror]);
            }
            
            int lf = i-P[i], rt = i+P[i];
            while(lf>=0 && rt<n2 && T[lf]==T[rt]){
                P[i]++;
                lf--;
                rt++;
            }

            if(P[i]+i > R){
                R = P[i] + i;
                C = i;
            }
        }

        int maxlen = 0, cen=0;
        for(int i=0; i<n2; i++){
            cout<<i<<": "<<P[i]<<endl;
            if(P[i]>maxlen){
                maxlen = P[i];
                cen = i;
            }
        }

        int st = cen - (maxlen-1) + 1;
        int en = cen + maxlen - 1;
        cout<<cen<<" "<<maxlen<<endl;
        string ans = "";
        while(st<=en){
            ans += T[st];
            st+=2;
        }
        return ans;
    }
};