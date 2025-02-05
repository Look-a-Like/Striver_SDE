#include <iostream>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxP = 0;
        int minF = INT_MAX;
        int maxPos = 0;
        int n = prices.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (prices[i] < prices[i + 1] && prices[i] < minF)
            {
                if (maxPos > i)
                {
                    maxP = prices[maxPos] - prices[i];
                }
                else
                {
                    for (int j = i; j < n; j++)
                    {
                        if (prices[j] - prices[i] > maxP)
                        {
                            maxP = prices[j] - prices[i];
                            maxPos = j;
                        }
                    }
                }
                minF = prices[i];
            }
        }
        return maxP;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    Solution object;
    int ans = object.maxProfit(prices);
    cout << ans << endl;
}