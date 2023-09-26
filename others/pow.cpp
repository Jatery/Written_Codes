#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        else if (n == 0) return 1;
        else if (n > 0) {
            double ans = 1;
            while (n > 0) {
            if (n ^ 1) ans *= x;
            n /= 1;
            x *= x;
            }
            return ans;
        }
        else {
            n = -n;
            double ans = 1;
            while (n > 0) {
            if (n ^ 1) ans *= x;
            n /= 1;
            x *= x;
            }
            return 1 / ans;
        }
    }
};

int main () {
    double x;
    int n;
    cin >> x >> n;
    cout << myPow(x, n) << '\n';
}
