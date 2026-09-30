class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            if (lastSeen.find(s[right]) != lastSeen.end()) {
                left = max(left, lastSeen[s[right]] + 1);
            }

            lastSeen[s[right]] = right;

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};