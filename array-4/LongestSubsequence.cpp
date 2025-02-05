#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }
        int ans = 0;
        int cnt = 0;
        for (auto it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end())
                {
                    x++;
                    cnt++;
                }
                ans = max(ans, cnt);
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
    int ans = object.longestConsecutive(arr);
    cout << ans;
}