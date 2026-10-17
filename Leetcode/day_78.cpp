#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        
        struct Element {
            int digit_sum;
            int value;
            int original_index;
        };

        std::vector<Element> elements(n);
        for (int i = 0; i < n; ++i) {
            elements[i] = {getDigitSum(nums[i]), nums[i], i};
        }

        std::sort(elements.begin(), elements.end(), [](const Element& a, const Element& b) {
            if (a.digit_sum != b.digit_sum) {
                return a.digit_sum < b.digit_sum;
            }
            return a.value < b.value;
        });

        std::vector<bool> visited(n, false);
        int total_swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || elements[i].original_index == i) {
                continue;
            }

            int cycle_size = 0;
            int curr = i;

            while (!visited[curr]) {
                visited[curr] = true;
                curr = elements[curr].original_index;
                cycle_size++;
            }

            if (cycle_size > 0) {
                total_swaps += (cycle_size - 1);
            }
        }

        return total_swaps;
    }
};