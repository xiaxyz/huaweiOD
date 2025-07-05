#include <iostream>
#include <string>
#include <vector>

using namespace std;

class S
{
private:
    vector<vector<string>> mp;
    string target;
    int result;
    vector<int> func1(string str)
    {
        vector<int> pos(2, 0);
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                pos[1] = pos[1] * 26 + (str[i] - 'A' + 1);
            }
            else
            {
                pos[0] = pos[0] * 10 + (str[i] - '0');
            }
        }
        --pos[0];
        --pos[1];
        return pos;
    }
    int func2(string str)
    {
        if (str[0] != '=')
        {
            return stoi(str);
        }
        int result = 0;
        string cell_a = "";
        string cell_b = "";
        int mark_index = -1;
        bool mark = false;
        for (int i = 1; i < str.size(); ++i)
        {
            if (str[i] == '+' || str[i] == '-')
            {
                mark_index = i;
                mark = true;
            }
            else
            {
                if (mark)
                {
                    cell_b.push_back(str[i]);
                }
                else
                {
                    cell_a.push_back(str[i]);
                }
            }
        }
        auto cell1 = func1(cell_a);
        if (mark_index == -1)
        {
            return stoi(mp[cell1[0]][cell1[1]]);
        }
        auto cell2 = func1(cell_b);
        if (cell1[1] == -1 && cell2[1] == -1)
        {
            if (str[mark_index] == '+')
            {
                return cell1[0] + cell2[0];
            }
            else
            {
                return cell1[0] - cell2[0];
            }
        }
        else if (cell1[1] == -1)
        {
            if (str[mark_index] == '+')
            {
                return (cell1[0] + 1) + stoi(mp[cell2[0]][cell2[1]]);
            }
            else
            {
                return (cell1[0] + 1) - stoi(mp[cell2[0]][cell2[1]]);
            }
        }
        else if (cell2[1] == -1)
        {
            if (str[mark_index] == '+')
            {
                return stoi(mp[cell1[0]][cell1[1]]) + (cell2[0] + 1);
            }
            else
            {
                return stoi(mp[cell1[0]][cell1[1]]) - (cell2[0] + 1);
            }
        }
        else
        {
            if (str[mark_index] == '+')
            {
                return stoi(mp[cell1[0]][cell1[1]]) + stoi(mp[cell2[0]][cell2[1]]);
            }
            else
            {
                return stoi(mp[cell1[0]][cell1[1]]) - stoi(mp[cell2[0]][cell2[1]]);
            }
        }
    }

public:
    S(vector<vector<string>> mp_, string target_);
    ~S();

    int func()
    {
        string cell_a = "";
        string cell_b = "";
        bool mark = false;
        for (int i = 0; i < target.size(); ++i)
        {
            if (target[i] == ':')
            {
                mark = true;
            }
            else
            {
                if (mark)
                {
                    cell_b.push_back(target[i]);
                }
                else
                {
                    cell_a.push_back(target[i]);
                }
            }
        }
        auto cell1 = func1(cell_a);
        auto cell2 = func1(cell_b);
        for (int i = cell1[0]; i <= cell2[0]; ++i)
        {
            for (int j = cell1[1]; j <= cell2[1]; ++j)
            {
                result += func2(mp[i][j]);
            }
        }
        return result;
    }
};

S::S(vector<vector<string>> mp_, string target_) : mp(mp_), target(target_), result(0)
{
}

S::~S()
{
}

int main(int argc, char const *argv[])
{
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<string>> mp(rows, vector<string>(cols));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> mp[i][j];
        }
    }
    string target;
    cin >> target;
    S s0(mp, target);
    cout << s0.func() << endl;
    return 0;
}
