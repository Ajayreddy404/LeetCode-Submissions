class Solution {
public:

    // Comparator to sort words by length
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        // Sort words by length
        sort(words.begin(), words.end(), compare);

        // DP map to store the longest chain length ending with each word
        unordered_map<string, int> dp;
        int res = 0; // Result to store the maximum chain length

        // Iterate through each word
        for (string w : words) {
            // Initialize the chain length for the current word
            dp[w] = 1;

            // Generate all possible predecessors by removing one character
            for (int i = 0; i < w.length(); i++) {
                string pre = w.substr(0, i) + w.substr(i + 1);

                // If the predecessor exists in the DP map, update the current word's chain length
                if (dp.find(pre) != dp.end()) {
                    dp[w] = max(dp[w], dp[pre] + 1);
                }
            }

            // Update the result with the maximum chain length found so far
            res = max(res, dp[w]);
        }

        return res;
    }
};