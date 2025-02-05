#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

class Solution
{
public:
    vector<ll> repeatedNumber(vector<ll> &A)
    {
        long long n = A.size();
        vector<bool> arr(n, true);
        vector<long long> ans(2);
        long long miss = 0;
        long long sum = 0;
        long long repeat = 0;
        long long Asum = n * (n + 1) / 2;
        for (long long i = 0; i < n; i++)
        {
            sum += A[i];
            if (arr[A[i]] == true)
            {
                arr[A[i]] = false;
            }
            else
            {
                repeat = A[i];
            }
        }
        miss = Asum - (sum - repeat);
        ans[0] = repeat;
        ans[1] = miss;
        return ans;
    }
};

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution object;
    vector<ll> ans = object.repeatedNumber(arr);
    cout << ans[0] << " " << ans[1];
}