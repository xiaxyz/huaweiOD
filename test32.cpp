#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

class S
{
private:
    vector<vector<char>> mp;
    int k;
    set<string> mark;
    vector<vector<int>> offset;
    int result;

    int func1(int x, int y)
    {
        mark.insert(string(to_string(x) + "," + to_string(y)));
        int count = 0;
        if (mp[x][y] == 'E')
        {
            ++count;
        }
        int new_x, new_y;
        for (const auto &offset_x : offset)
        {
            new_x = x + offset_x[0];
            new_y = y + offset_x[1];
            if (new_x >= 0 && new_x < mp.size() && new_y >= 0 && new_y < mp[new_x].size() && mp[new_x][new_y] != '#' && mark.find(string(to_string(new_x) + "," + to_string(new_y))) == mark.end())
            {
                count += func1(new_x, new_y);
            }
        }
        return count;
    }

public:
    S(vector<vector<char>> mp_, int k_);
    ~S();

    int func()
    {
        for (int i = 0; i < mp.size(); ++i)
        {
            for (int j = 0; j < mp[i].size(); ++j)
            {
                if (mp[i][j] != '#' && mark.find(string(to_string(i) + "," + to_string(j))) == mark.end())
                {
                    if (func1(i, j) <= k)
                    {
                        ++result;
                    }
                }
            }
        }
        return result;
    }


};

S::S(vector<vector<char>> mp_, int k_) : mp(mp_), k(k_), offset({{1, 0}, {0, 1}, {-1, 0}, {0, -1}}), result(0)
{
}

S::~S()
{
}


int main(int argc, char const *argv[])
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> mp(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> mp[i][j];
        }
    }
    S s0(mp, k);
    cout << s0.func() << endl;
    return 0;
}
