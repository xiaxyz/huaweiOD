#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class S
{
private:
    vector<vector<int>> mp;
    queue<pair<int, int>> que;

public:
    S(vector<vector<int>> _mp, queue<pair<int, int>> _que);
    ~S();
    int func(int step);
};

S::S(vector<vector<int>> _mp, queue<pair<int, int>> _que) : mp(_mp), que(_que)
{
}

S::~S()
{
}

int S::func(int step)
{
    if (que.empty())
    {
        return step - 1;
    }
    int n = que.size();
    for (int i = 0; i < n; ++i)
    {
        pair<int, int> xy = que.front();
        que.pop();
        if (xy.first > 0 && mp[xy.first - 1][xy.second] == 0)
        {
            mp[xy.first - 1][xy.second] = 1;
            que.push({xy.first - 1, xy.second});
        }
        if (xy.first < mp.size() - 1 && mp[xy.first + 1][xy.second] == 0)
        {
            mp[xy.first + 1][xy.second] = 1;
            que.push({xy.first + 1, xy.second});
        }
        if (xy.second > 0 && mp[xy.first][xy.second - 1] == 0)
        {
            mp[xy.first][xy.second - 1] = 1;
            que.push({xy.first, xy.second - 1});
        }
        if (xy.second < mp[xy.first].size() - 1 && mp[xy.first][xy.second + 1] == 0)
        {
            mp[xy.first][xy.second + 1] = 1;
            que.push({xy.first, xy.second + 1});
        }
    }
    return func(step + 1);
}

int main(int argc, char const *argv[])
{
    vector<int> arr;
    string str;
    getline(cin, str);
    stringstream ss(str);
    string temp_in;
    while(getline(ss, temp_in, ','))
    {
        arr.push_back(stoi(temp_in));
    }
    vector<vector<int>> mp(arr[0], vector<int>(arr[1], 0));
    mp[arr[2]][arr[3]] = 1;
    mp[arr[4]][arr[5]] = 1;
    S s0(mp, queue<pair<int, int>>({{arr[2], arr[3]}, {arr[4], arr[5]}}));
    cout << s0.func(0) << endl;
    return 0;
}
