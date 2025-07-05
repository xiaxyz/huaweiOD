#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class S
{
private:
    vector<int> speed;
    int limit;
    vector<int> dp;

public:
    S(vector<int> speed_, int limit_);
    ~S();
    string func()
    {
        if (speed.size() <= 2)
        {
            for (int i = 0; i < speed.size(); ++i)
            {
                dp.push_back(speed[i]);
                if (dp[i] >= limit)
                {
                    return string(to_string(i) + ' ' + to_string(i - 1 >= 0 ? dp[i - 1] : 0));
                }
            }
        }
        else
        {
            for (int i = 0; i < 2; ++i)
            {
                dp.push_back(speed[i]);
                if (dp[i] >= limit)
                {
                    return string(to_string(i) + ' ' + to_string(i - 1 >= 0 ? dp[i - 1] : 0));
                }
            }
            for (int i = 2; i < speed.size(); ++i)
            {
                dp.push_back(min(dp[i - 1] + speed[0] + speed[i], dp[i - 2] + speed[0] + speed[i] + speed[1] + speed[1]));
                if (dp[i] > limit)
                {
                    return string(to_string(i) + ' ' + to_string(i - 1 >= 0 ? dp[i - 1] : 0));
                }
            }
        }
        return string(to_string(dp.size()) + ' ' + to_string(dp.size() >= 0 ? dp.back() : 0));
    }
};

S::S(vector<int> speed_, int limit_) : speed(speed_), limit(limit_), dp()
{
}

S::~S()
{
}

int main(int argc, char const *argv[])
{
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    S s0(arr, t);
    cout << s0.func() << endl;
    return 0;
}
