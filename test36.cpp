#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

class S
{
private:
    vector<vector<int>> mp;
    vector<vector<int>> start;
    vector<vector<int>> end;
    vector<vector<int>> offset;
    set<string> flag;
    int result;
    bool func1(int x1, int y1, int x2, int y2)
    {
        if (x1 == x2 && y1 == y2)
        {
            return true;
        }
        string xy = string(to_string(x1) + "," + to_string(y1));
        if (flag.find(xy) != flag.end())
        {
            return false;
        }
        flag.insert(xy);
        int new_x, new_y;
        for (const auto &offset_x : offset)
        {
            new_x = x1 + offset_x[0];
            new_y = y1 + offset_x[1];
            if (new_x >= 0 && new_x < mp.size() && new_y >= 0 && new_y < mp[new_x].size() && mp[new_x][new_y] != 1)
            {
                if (func1(new_x, new_y, x2, y2))
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    S(vector<vector<int>> mp_);
    ~S();
    int func()
    {
        for (const auto &end_x : end)
        {
            bool mark = true;
            for (const auto &start_x: start)
            {
                mark = mark && func1(start_x[0], start_x[1], end_x[0], end_x[1]);
                flag.clear();
            }
            if (mark)
            {
                ++result;
            }
        }
        return result;
    }
};

S::S(vector<vector<int>> mp_) : mp(mp_), start(), end(), offset({{1, 0}, {0, 1}, {-1, 0}, {0, -1}}), result(0), flag()
{
    for (int i = 0; i < mp.size(); ++i)
    {
        for (int j = 0; j < mp[i].size(); ++j)
        {
            if (mp[i][j] == 2)
            {
                start.push_back({i, j});
            }
            else if (mp[i][j] == 3)
            {
                end.push_back({i, j});
            }
        }
    }
}

S::~S()
{
}


int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mp(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> mp[i][j];
        }
    }
    S s0(mp);
    cout << s0.func() << endl;
    return 0;
}
