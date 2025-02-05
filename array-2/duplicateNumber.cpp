#include <iostream>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> arr(n, true);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[nums[i]] == true)
            {
                arr[nums[i]] = false;
            }
            else
            {
                ans = nums[i];
                return ans;
            }
        }
        return ans;
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
    int ans = object.findDuplicate(arr);
    cout << ans << endl;
}