#include<iostream>
using namespace std; 

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int Xmax = max(x1, min(xCenter, x2));
        int ymax = max(y1, min(yCenter, y2));

        int dx = xCenter - Xmax;
        int dy = yCenter - ymax;

        if((dx*dx+dy*dy)<=(radius*radius)){
            return true;
        }
        return false;
    }
};