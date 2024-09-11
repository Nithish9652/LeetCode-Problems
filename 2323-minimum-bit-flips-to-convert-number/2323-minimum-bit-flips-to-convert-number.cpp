class Solution {
public:
    int minBitFlips(int start, int goal) {
        int d = start ^ goal;
        int c = 0;
        while (d > 0) {
            c += d & 1;  
            d >>= 1;     
        }
        return c;
    }
};
