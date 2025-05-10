#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int column = matrix[0].size();
        vector<bool> zeroRows(row, false);
        vector<bool> zeroColumns(column, false);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (matrix[i][j] == 0)
                {
                    zeroRows[i] = true;
                    zeroColumns[j] = true;
                    continue;
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (zeroRows[i] || zeroColumns[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
}