#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class S
{
private:
    vector<vector<int>> arr;
    vector<vector<int>> result;
    void func1()
    {
        for (int i = 0; i < arr.size() - 1; ++i)
        {
            if (arr[i][1] >= arr[i + 1][0])
            {
                result.push_back({arr[i + 1][0], min(arr[i][1], arr[i + 1][1])});
            }
        }
    }
    void func2()
    {
        for (int i = 0; i < arr.size() - 1; ++i)
        {
            if (arr[i][1] >= arr[i + 1][0])
            {
                result.push_back({arr[i][0], max(arr[i][1], arr[i + 1][1])});
            }
        }
    }

public:
    S(vector<vector<int>> arr_);
    ~S();

    vector<vector<int>> func()
    {
        bool mark = true;
        func1();
        if (result.size() == 0)
        {
            return result;
        }
        while (result.size() != 0)
        {
            arr = result;
            result.clear();
            func2();
        }
        return arr;
    }
};

S::S(vector<vector<int>> arr_) : arr(arr_)
{
}

S::~S()
{
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    int left, right;
    for (int i = 0; i < n; ++i)
    {
        cin >> left >> right;
        arr[i] = {left, right};
    }
    sort(arr.begin(), arr.end(), [](vector<int> x, vector<int> y) { return x[0] < y[0]; });
    S s0(arr);
    auto result = s0.func();
    if (result.size() == 0)
    {
        cout << "None" << endl;
    }
    else
    {
        for (const auto &result_x : result)
        {
            cout << result_x[0] << " " << result_x[1] << endl;
        }
    }
    return 0;
}
