#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> grid;
        grid.push_back({1});
        if (numRows == 1)
        {
            return grid;
        }
        grid.push_back({1, 1});
        if (numRows == 2)
        {
            return grid;
        }
        for (int i = 2; i < numRows; i++)
        {
            vector<int> row;
            row.push_back(1);
            int j = 1;
            while (j < grid[i - 1].size())
            {
                row.push_back(grid[i - 1][j - 1] + grid[i - 1][j]);
                j++;
            }
            row.push_back(1);
            grid.push_back(row);
        }
        return grid;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution object;
    vector<vector<int>> ans = object.generate(n);
    for (const auto &row : ans)
    {
        for (const auto &elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
}