#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class S
{
private:
    int s, m;
    vector<vector<int>> matrix;
public:
    S(int _s, int _m, vector<vector<int>> _matrix) : s(_s), m(_m), matrix(_matrix)
    {
    }
    int func()
    {
        int count = 0;
        for (int i = 0; i < matrix.size() - s + 1; ++i)
        {
            for (int j = 0; j < matrix[i].size() - s + 1; ++j)
            {
                int sum = 0;
                for (int x = i; x < i + s; ++x)
                {
                    for (int y = j; y < j + s; ++y)
                    {
                        sum += matrix[x][y];
                    }
                }
                if (sum >= m)
                {
                    ++count;
                }
            }
        }
        return count;
    }
};



int main(void)
 {
    int r, c, s, m;
    cin >> r >> c >> s >> m;
    vector<vector<int>> matrix(r, vector<int>(c));
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    S s0(s, m, matrix);
    cout << s0.func() << endl;
    return 0;
 }