class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedWord = "";
        for(int i=0, j=0; ; ){
            if(i<word1.length())    mergedWord += word1[i];
            i++;
            if(j<word2.length())    mergedWord += word2[j];
            j++;
            if(i>=word1.length() && j>=word2.length())  break;
        }
        return mergedWord;
    }
};