#include <iostream>
#include <climits>
using namespace std;

void maxsubarraysum(int *arr, int n) {
    int maxSum = INT_MIN;
    int currSum = 0;
    
    for(int i = 0; i < n; i++) {
        currSum += arr[i];
        
        // Update maxSum BEFORE resetting currSum to 0
        maxSum = max(maxSum, currSum);
        
        if(currSum < 0) {
            currSum = 0;
        }
    }
    
    cout << "maximum subarray sum is: " << maxSum << endl;
}

int main() {
    int arr[6] = {2, -3, 6, -5, 4, 2};
    int len = sizeof(arr) / sizeof(int);
    
    maxsubarraysum(arr, len);
    
    return 0;
}
