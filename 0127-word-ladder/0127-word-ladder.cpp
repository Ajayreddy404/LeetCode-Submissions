class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> words;
        unordered_set<string> taken;
        taken.insert(beginWord);
        for(auto w: wordList)   words.insert(w);
        if(words.find(endWord)==words.end())    return 0;
        int minCnt = INT_MAX;

        int cnt = 1;
        queue<string> qu;
        qu.push(beginWord);

        while(!qu.empty()){
            int sz = qu.size();
            
            while(sz--){
                string w = qu.front();
                qu.pop();
                taken.insert(w);
                if(w==endWord){
                    return cnt;
                }
                // cout<<w<<" "<<cnt<<endl;
                for(int i=0; i<w.length(); i++){
                    string s = w;
                    for(char c='a'; c<='z'; c++){
                        if(c==w[i]) continue;   // same word -> self loop
                        s[i] = c;
                        // cout<<s<<endl;
                        
                        if(taken.find(s)==taken.end() && words.find(s)!=words.end()){
                            // taken.insert(s);
                            qu.push(s);
                        }
                    }
                }
            }
            cnt++;
        }
        return 0;
    }
};