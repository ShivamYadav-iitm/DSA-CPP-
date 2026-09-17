#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, int> prefixMap;
        
       
        prefixMap[0] = -1; 
        
        int currentSum = 0;
        int minLenSoFar = 1e9; 
        int result = 1e9;
        
        vector<int> best(n, 1e9); 
        
        for (int i = 0; i < n; i++) {
            currentSum += arr[i];
            
            prefixMap[currentSum] = i; 
            
            if (prefixMap.count(currentSum - target)) {
                int startIdx = prefixMap[currentSum - target];
                int currentLen = i - startIdx;
                
                if (startIdx >= 0 && best[startIdx] != 1e9) {
                    result = min(result, currentLen + best[startIdx]);
                }
                
                minLenSoFar = min(minLenSoFar, currentLen);
            }
            
            best[i] = minLenSoFar;
        }
        
        return result == 1e9 ? -1 : result;
    }
};