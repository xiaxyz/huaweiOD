#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

class S
{
private:
    vector<vector<int>> user;
    unordered_map<int, int> message;
    vector<vector<int>> result;
public:
    S(vector<vector<int>> _user, unordered_map<int, int> _message);
    ~S();
    vector<vector<int>> func();
};

S::S(vector<vector<int>> _user, unordered_map<int, int> _message) : user(_user), message(_message)
{
    result.assign(user.size(), vector<int>());
}

S::~S()
{
}

vector<vector<int>> S::func()
{
    for (auto x : message)
    {
        for (int i = user.size() - 1; i >= 0; --i)
        {
            if (user[i][0] <= x.first && user[i][1] > x.first)
            {
                result[i].push_back(x.second);
                break;
            }
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    unordered_map<int, int> message;
    vector<vector<int>> user;
    string line;
    getline(cin, line);
    stringstream ss;
    ss.str(line);
    int num;
    while(ss >> num)
    {
        ss >> message[num];
    }
    getline(cin, line);
    ss.clear();
    ss.str(line);
    while(ss >> num)
    {
        user.push_back(vector<int>(2));
        user.back()[0] = num;
        ss >> num;
        user.back()[1] = num;
    }
    S s0(user, message);
    vector<vector<int>> result = s0.func();
    for (int i = 0; i < result.size(); ++i)
    {
        if (result[i].empty())
        {
            cout << -1 << endl;
        }
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
