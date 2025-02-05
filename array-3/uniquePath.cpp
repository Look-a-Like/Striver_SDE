#include <iostream>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int a = n + m - 2;
        int b = min(m - 1, n - 1);
        double r = 1;
        for (int i = 1; i <= b; i++)
        {
            r = r * (a - i + 1) / i;
        }
        return (int)r;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Solution object;
    int ans = object.uniquePaths(n, m);
    cout << ans << endl;
}