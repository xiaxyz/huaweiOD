#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

class S
{
private:
    vector<vector<char>> mp;
    vector<vector<int>> xy;
    set<string> checked;
    ;

public:
    S(vector<vector<char>> _mp);
    ~S();
    vector<int> func();
    int func1(int x, int y);
};

S::S(vector<vector<char>> _mp) : mp(_mp)
{
}

S::~S()
{
}

vector<int> S::func()
{
    int num = 0;
    vector<int> result;
    for (int i = 0; i < mp.size(); ++i)
    {
        for (int j = 0; j < mp[i].size(); ++j)
        {
            xy.clear();
            int temp_num = func1(i, j);
            if (xy.size() == 1)
            {
                if (temp_num > num)
                {
                    result.clear();
                    num = temp_num;
                    result = xy[0];
                    result.push_back(num);
                }
                else if (temp_num == num)
                {
                    result.clear();
                    result.push_back(num);
                }
            }
        }
    }
    return result;
}

int S::func1(int x, int y)
{
    if (x < 0 || x >= mp.size() || y < 0 || y >= mp[x].size())
    {
        return 0;
    }
    if (mp[x][y] == 'X')
    {
        return 0;
    }
    if (mp[x][y] == 'O')
    {
        string mark = string(to_string(x) + "," + to_string(y));
        if (checked.find(mark) != checked.end())
        {
            return 0;
        }
        checked.insert(mark);
        if (x == 0 || x == mp.size() - 1 || y == 0 || y == mp[x].size() - 1)
        {
            xy.push_back({x, y});
        }
        int count = 1;
        count += func1(x - 1, y);
        count += func1(x + 1, y);
        count += func1(x, y - 1);
        count += func1(x, y + 1);
        return count;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> mp(m, vector<char>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> mp[i][j];
        }
    }
    S s0(mp);
    vector<int> result = s0.func();
    if (result.size() == 0)
    {
        cout << "NULL" << endl;
    }
    else
    {
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
