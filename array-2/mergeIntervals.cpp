#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for (int i = 1; i < n; i++)
        {
            vector<int> &last = merged.back();
            if (intervals[i][0] <= last[1])
            {
                last[1] = max(last[1], intervals[i][1]);
            }
            else
            {
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> grid[i][j];
        }
    }
    Solution object;
    grid = object.merge(grid);
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}