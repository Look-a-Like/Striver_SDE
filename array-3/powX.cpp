#include <iostream>

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long dup = n;
        if (dup < 0)
        {
            dup *= -1;
        }
        while (dup)
        {
            if (dup % 2)
            {
                ans *= x;
                dup--;
            }
            else
            {
                x *= x;
                dup /= 2;
            }
        }
        if (n < 0)
        {
            ans = (double)(1.0) / (double)(ans);
        }
        return ans;
    }
};

int main()
{
    int n;
    double x;
    cin >> n >> x;
    Solution object;
    double ans = object.myPow(x, n);
}