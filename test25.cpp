#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

map<string, int> mp({{"3", 0}, {"4", 1}, {"5", 2}, {"6", 3}, {"7", 4}, {"8", 5}, {"9", 6}, {"10", 7}, {"J", 8}, {"Q", 9}, {"K", 10}, {"A", 11}, {"2", 12}});
string func1(int);
int func2(string);

class S
{
private:
    vector<int> arr;
    vector<vector<string>> result;

public:
    S(vector<int> arr_);
    ~S();

    vector<vector<string>> func();
};

S::S(vector<int> arr_) : arr(arr_)
{
}

S::~S()
{
}

vector<vector<string>> S::func()
{
    int left = -1, right = 0;
    int temp_count = -1;
    while (temp_count != result.size())
    {
        temp_count = result.size();
        left = -1;
        right = 0;
        while (right < arr.size() - 1)
        {
            if (arr[right] > 0)
            {
                if (left == -1)
                {
                    left = right;
                    result.push_back({func1(right)});
                }
                else
                {
                    result.back().push_back(func1(right));
                }
                --arr[right];
            }
            else
            {
                if (result.back().size() < 5)
                {
                    for (int i = 0; i < result.back().size(); ++i)
                    {
                        ++arr[func2(result.back()[i])];
                    }
                    result.pop_back();
                }
                left = -1;
            }
            ++right;
        }
        if (result.back().size() < 5)
        {
            for (int i = 0; i < result.back().size(); ++i)
            {
                ++arr[func2(result.back()[i])];
            }
            result.pop_back();
        }
    }
    return result;
}

string func1(int x)
{
    for (auto mp_x : mp)
    {
        if (mp_x.second == x)
        {
            return mp_x.first;
        }
    }
    return "";
}

int func2(string x)
{
    return mp[x];
}

int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);
    stringstream ss(str);
    string card;
    vector<int> arr(13, 0);
    while (ss >> card)
    {
        ++arr[func2(card)];
    }
    S s0(arr);
    auto result = s0.func();
    if (result.size() == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        for (auto result_x : result)
        {
            for (auto result_y : result_x)
            {
                cout << result_y << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
