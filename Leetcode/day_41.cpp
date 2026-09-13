#include<iostream>
using namespace std;

class Solution {
public:
    int count(TreeNode* root){
        int count_n = 0;
        if(root==NULL){
            return 0;
        }
        int left_count = count(root->left);
        int right_count = count(root->right);
        count_n = left_count + right_count+1;
        return count_n;

    }
    int sum1(TreeNode *root){
        int sum = 0;
        if(root==NULL){
            return 0;
        }
        int left_s = sum1(root->left);
        int right_s = sum1(root->right);
        sum = left_s + right_s+ root->val;
        return sum;
    }

    int averageOfSubtree(TreeNode* root) {
        int count_l = 0;
        if(root== NULL){
            
            return 0;
        }

            int c = count(root);
            int s = sum1(root);
            int avg = s/c;

            if(avg==root->val){
                count_l++;
            }

            count_l += averageOfSubtree(root->left);
            count_l += averageOfSubtree(root->right);

        
        return count_l;
    }
};