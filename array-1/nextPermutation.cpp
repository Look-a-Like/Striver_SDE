#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int breakpoint = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                breakpoint = i;
                break;
            }
        }
        if (breakpoint != -1)
        {
            int index = breakpoint;
            int indexV = INT_MAX;
            for (int i = breakpoint + 1; i < n; i++)
            {
                if (nums[i] > nums[breakpoint])
                {
                    if (nums[i] < indexV)
                    {
                        index = i;
                        indexV = nums[i];
                    }
                }
            }
            swap(nums[breakpoint], nums[index]);
            sort(nums.begin() + breakpoint + 1, nums.end());
        }
        else
        {
            reverse(nums.begin(), nums.end());
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution object;
    object.nextPermutation(nums);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}