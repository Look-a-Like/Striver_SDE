#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int el1 = 0, el2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (cnt1 == 0 && el2 != nums[i])
            {
                cnt1 = 1;
                el1 = nums[i];
            }
            else if (cnt2 == 0 && el1 != nums[i])
            {
                cnt2 = 1;
                el2 = nums[i];
            }
            else if (el1 == nums[i])
            {
                cnt1++;
            }
            else if (el2 == nums[i])
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == el1)
            {
                cnt1++;
            }
            if (nums[i] == el2 && el2 != el1)
            {
                cnt2++;
            }
        }
        int mini = (n / 3) + 1;
        if (cnt1 >= mini)
        {
            ans.push_back(el1);
        }
        if (cnt2 >= mini)
        {
            ans.push_back(el2);
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
    vector<int> ans = object.majorityElement(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}