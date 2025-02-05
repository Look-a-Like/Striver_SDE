#include <iostream>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (ans == nums[i])
            {
                count++;
            }
            else if (count == 0)
            {
                ans = nums[i];
                count++;
            }
            else
            {
                count--;
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
    int ans = object.majorityElement(arr);
    cout << ans << endl;
}