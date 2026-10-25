#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    const vector<int> daysPerMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dateToDayOfYear(const string& date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int dayOfYear = day;
        for (int i = 0; i < month - 1; i++) {
            dayOfYear += daysPerMonth[i];
        }

        return dayOfYear;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startA = dateToDayOfYear(arriveAlice);
        int endA = dateToDayOfYear(leaveAlice);
        int startB = dateToDayOfYear(arriveBob);
        int endB = dateToDayOfYear(leaveBob);

        int overlapStart = max(startA, startB);
        int overlapEnd = min(endA, endB);

        if (overlapStart <= overlapEnd) {
            return overlapEnd - overlapStart + 1;
        }

        return 0;
    }
};