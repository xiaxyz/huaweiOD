#include <iostream>
#include <vector>

using namespace std;

class S
{
private:
    vector<vector<int>> arr;
    int result;
    vector<vector<int>> offset;

public:
    S(vector<vector<int>> arr_);
    ~S();

    int func();
    void func1(int x, int y);
};

S::S(vector<vector<int>> arr_) : arr(arr_), result(0), offset({{-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {-1, 0}, {0, -1}, {1, 0}, {0, 1}})
{
}

S::~S()
{
}

int S::func()
{
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr[i].size(); ++j)
        {
            if (arr[i][j] == 1)
            {
                func1(i, j);
                ++result;
            }
        }
    }
    return result;
}

void S::func1(int x, int y)
{
    arr[x][y] = 0;
    for (const auto offset_x : offset)
    {
        int new_x = x + offset_x[0];
        int new_y = y + offset_x[1];
        if (new_x >= 0 && new_x < arr.size() && new_y >= 0 && new_y < arr[new_x].size())
        {
            if (arr[new_x][new_y] == 1)
            {
                func1(new_x, new_y);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> arr[i][j];
        }
    }
    S s0(arr);
    cout << s0.func() << endl;
    return 0;
}
