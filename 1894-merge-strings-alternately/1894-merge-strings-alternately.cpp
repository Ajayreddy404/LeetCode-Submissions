class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedWord = "";
        for(int i=0; i<word1.length() || i<word2.length(); i++){
            if(i<word1.length())    mergedWord += word1[i];
            if(i<word2.length())    mergedWord += word2[i];
        }
        return mergedWord;
    }
};