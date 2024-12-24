class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // Frequency map for characters in t
        std::vector<int> map(128, 0);
        for (char c : t) {
            map[c]++;
        }

        int count = t.length(); // Total characters in t that need to be matched
        int start = 0, end = 0, minLen = INT_MAX, startIndex = 0;

        while (end < s.length()) {
            // Process the current character at 'end'
            if (map[s[end]] > 0) {
                count--;
            }
            map[s[end]]--; // Decrement the count in the map
            end++;

            // If all characters from t are matched
            while (count == 0) {
                // Update the minimum window
                if (end - start < minLen) {
                    minLen = end - start;
                    startIndex = start;
                }

                // Shrink the window from the left
                map[s[start]]++;
                if (map[s[start]] > 0) {
                    count++; // A character from t is no longer fully matched
                }
                start++;
            }
        }

        // Return the result
        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};
