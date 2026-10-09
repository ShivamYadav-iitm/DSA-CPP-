#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;   
        int neededRight = 0;  
        
        for (char c : s) {
            if (c == '(') {
                
                if (neededRight % 2 != 0) {
                    insertions++;
                    neededRight--;
                }
               
                neededRight += 2;
            } else {
                neededRight--;
                if (neededRight < 0) {
                    insertions++;      
                    neededRight += 2;  
                                      
                }
            }
        }
        return insertions + neededRight;
    }
};