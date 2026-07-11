#include <iostream>
#include <climits>
using namespace std;

void maxProfit(int *prices,int n){
    int bestBuy[100000];
    bestBuy[0] = INT_MAX;
    for(int i=1;i<n;i++){
        bestBuy[i] = min(bestBuy[i-1],prices[i-1]);
    }
    int maxProfit = 0;
    for(int i=0;i<n;i++){
        int currProfit = prices[i]-bestBuy[i];
        maxProfit = max(maxProfit,currProfit);
    }
    cout<<"maximum profit possible is: "<<maxProfit<<endl;
}

int main() {
    int arr[6] = {7,1,5,3,8,4};
    int len = sizeof(arr) / sizeof(int);
    maxProfit(arr,len);
    
    return 0;
}
