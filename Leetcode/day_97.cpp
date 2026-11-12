#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int count = 0;
        int j = 0;
        int m = arr2.size();
        for(int x : arr1) {
            while(j < m && arr2[j] < (long long)x - d) {
                j++;
            }

            if(j == m || arr2[j] > (long long)x + d) {
                count++;
            }
        }
        return count;
    }
};