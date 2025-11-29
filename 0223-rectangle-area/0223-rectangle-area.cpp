class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2) {

        // Area of both rectangles
        int areaA = (ax2 - ax1) * (ay2 - ay1);
        int areaB = (bx2 - bx1) * (by2 - by1);

        // Overlap width
        int overlapW = min(ax2, bx2) - max(ax1, bx1);
        // Overlap height
        int overlapH = min(ay2, by2) - max(ay1, by1);

        int overlap = 0;
        if (overlapW > 0 && overlapH > 0)
            overlap = overlapW * overlapH;

        return areaA + areaB - overlap;
    }
};
