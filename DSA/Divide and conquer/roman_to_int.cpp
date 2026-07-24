#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        int total = 0;
        int prevValue = 0;
        
        // Iterate from right to left
        for (int i = s.length() - 1; i >= 0; i--) {
            int currentValue = 0;
            
            // Map the Roman numeral character to its integer value
            switch(s[i]) {
                case 'I': currentValue = 1; break;
                case 'V': currentValue = 5; break;
                case 'X': currentValue = 10; break;
                case 'L': currentValue = 50; break;
                case 'C': currentValue = 100; break;
                case 'D': currentValue = 500; break;
                case 'M': currentValue = 1000; break;
            }
            
            // If the current numeral is smaller than the previous one, subtract it
            if (currentValue < prevValue) {
                total -= currentValue;
            } 
            // Otherwise, add it
            else {
                total += currentValue;
            }
            
            // Update previous value for the next iteration
            prevValue = currentValue;
        }
        
        return total;
    }
};