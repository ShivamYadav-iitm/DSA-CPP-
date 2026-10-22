#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zeroIdx = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroIdx = i;
                break;
            }
        }

        bool isForward = true;
        for (int i = 0; i < n; i++) {
            if (nums[(zeroIdx + i) % n] != i) {
                isForward = false;
                break;
            }
        }

        if (isForward) {
            int pureRotate = zeroIdx;
            int reverseAlt = 2 + (n - zeroIdx) % n;
            return min(pureRotate, reverseAlt);
        }

        bool isReverse = true;
        for (int i = 0; i < n; i++) {
            if (nums[(zeroIdx - i + n) % n] != i) {
                isReverse = false;
                break;
            }
        }

        if (isReverse) {
            int op1 = 1 + (n - 1 - zeroIdx) % n;
            int op2 = ((zeroIdx + 1) % n) + 1;
            return min(op1, op2);
        }

        return -1;
    }
};