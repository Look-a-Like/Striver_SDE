#include <iostream>

using namespace std;

class Solution
{
public:
    int maxLen(vector<int> &arr)
    {
        }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution object;
    int ans = object.maxLen(arr);
    cout << ans;
}