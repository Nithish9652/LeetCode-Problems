class Solution {
public:
    int magicalString(int n) {
        if (n == 1) return 1;

        vector<int> s(n + 2);
        s[0] = 1; 
        s[1] = 2; 
        s[2] = 2;

        int i = 2;   // pointer reading how many times to append
        int j = 3;   // pointer writing into string
        int curr = 1;
        int ones = 1; // s[0] == 1

        while (j < n) {
            int times = s[i];   // how many copies of curr to place

            while (times--) {
                s[j] = curr;
                if (curr == 1 && j < n) ones++;
                j++;
            }

            curr = 3 - curr; // flip 1 <-> 2
            i++;
        }

        return ones;
    }
};
