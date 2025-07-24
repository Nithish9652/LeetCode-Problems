class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(); // get length of string
        int count = 0; // total number of palindromic substrings
        
        // there are 2n - 1 centers (odd + even length centers)
        for (int center = 0; center < 2 * n - 1; ++center) {
            int left = center / 2; // starting left pointer
            int right = left + center % 2; // right is same as left for odd, one more for even

            // expand as long as both ends are same and inside string bounds
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++; // found a palindrome
                left--;  // move left outward
                right++; // move right outward
            }
        }
        return count; // return final answer
    }
};
