#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class S
{
private:
    vector<int> arr;
    vector<int> result;
public:
    S(vector<int> arr_);
    ~S();

    vector<int> func();
};

S::S(vector<int> arr_) : arr(arr_), result()
{
}

S::~S()
{
}

vector<int> S::func()
{
    vector<vector<int>> flag;
    for (int i = arr.size() - 1; i >= 0; --i)
    {
        if (arr[i] >= 4)
        {
            flag.push_back({arr[i], i});
            arr[i] = 0;
        }
    }
    sort(flag.begin(), flag.end(), [](vector<int> x, vector<int> y){if (x[0] != y[0]){ return x[0] > y[0]; } else { return x[1] > y[1]; }});
    for (auto x : flag)
    {
        for (int i = 0; i < x[0]; ++i)
        {
            result.push_back(x[1] + 1);
        }
    }
    flag.clear();
    for (int i = arr.size() - 1; i >= 0; --i)
    {
        if (arr[i] >= 3)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (arr[j] >= 2)
                {
                    flag.push_back({3, i, 2, j});
                    arr[i] -= 3;
                    arr[j] -= 2;
                    break;
                }
            }
        }
    }
    for (auto x : flag)
    {
        for (int i = 0; i < x[0]; ++i)
        {
            result.push_back(x[1] + 1);
        }
        for (int i = 0; i < x[2]; ++i)
        {
            result.push_back(x[3] + 1);
        }
    }
    flag.clear();
    for (int i = arr.size() - 1; i >= 0; --i)
    {
        if (arr[i] >= 3)
        {
            flag.push_back({3, i});
            arr[i] -= 3;
        }
    }
    for (auto x : flag)
    {
        for (int i = 0; i < x[0]; ++i)
        {
            result.push_back(x[1] + 1);
        }
    }
    flag.clear();
    for (int i = arr.size() - 1; i >= 0; --i)
    {
        if (arr[i] >= 2)
        {
            flag.push_back({2, i});
            arr[i] -= 2;
        }
    }
    for (auto x : flag)
    {
        for (int i = 0; i < x[0]; ++i)
        {
            result.push_back(x[1] + 1);
        }
    }
    flag.clear();
    for (int i = arr.size() - 1; i >= 0; --i)
    {
        if (arr[i] >= 1)
        {
            flag.push_back({1, i});
            arr[i] -= 1;
        }
    }
    for (auto x : flag)
    {
        for (int i = 0; i < x[0]; ++i)
        {
            result.push_back(x[1] + 1);
        }
    }
    flag.clear();
    return result;
}

int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> arr(13);
    while(ss >> num)
    {
        ++arr[num - 1];
    }
    S s0(arr);
    auto result = s0.func();
    for (auto x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
