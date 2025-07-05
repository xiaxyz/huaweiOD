#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class S
{
private:
    vector<vector<int>> mp;
    set<int> connected;
    int result;
    bool func1()
    {
        if (connected.size() == mp.size())
        {
            return true;
        }
        int mark = INT_MAX;
        int index = -1;
        for (const auto &connected_x : connected)
        {
            for (int i = 0; i < mp[connected_x].size(); ++i)
            {
                if (connected.find(i) == connected.end() && mark > mp[connected_x][i])
                {
                    mark = mp[connected_x][i];
                    index = i;
                }
            }
        }
        if (index != -1)
        {
            result += mark;
            connected.insert(index);
            return func1();
        }
        return false;
    }

public:
    S(vector<vector<int>> mp_);
    ~S();

    int func()
    {
        connected.insert(0);
        return func1() ? result : -1;
    }
};

S::S(vector<vector<int>> mp_) : mp(mp_), result(0)
{
}

S::~S()
{
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n, vector<int>(n, INT_MAX));
    int x, y, z, p;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y >> z >> p;
        --x;
        --y;
        if (p == 1)
        {
            mp[x][y] = 0;
            mp[y][x] = 0;
        }
        else
        {
            mp[x][y] = z;
            mp[y][x] = z;
        }
    }
    S s0(mp);
    cout << s0.func() << endl;
    return 0;
}
