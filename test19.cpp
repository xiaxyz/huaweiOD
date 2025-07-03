#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class S
{
private:
    vector<int> arr;
    int sum;
    int score_a;
public:
    S(vector<int> arr_);
    ~S();
    int func();
    void func1(int index, int now_score_a, int count);
};

S::S(vector<int> arr_) : arr(arr_), sum(0), score_a(0)
{
    for (auto x : arr)
    {
        sum += x;
    }
}

S::~S()
{
}

int S::func()
{
    func1(0, 0, 0);
    return abs(sum - 2 * score_a);
}

void S::func1(int index, int now_score_a, int count)
{
    if (count == 5)
    {
        if (abs(sum - 2 * now_score_a) < abs(sum - 2 * score_a))
        {
            score_a = now_score_a;
        }
        return;
    }
    else if (index == arr.size())
    {
        return;
    }
    for (int i = index; i < arr.size(); ++i)
    {
        now_score_a += arr[i];
        func1(i + 1, now_score_a, count + 1);
        now_score_a -= arr[i];
    }
    return;
}

int main(int argc, char const *argv[])
{
    vector<int> arr(10);
    for (int i = 0; i < 10; ++i)
    {
        cin >> arr[i];
    }
    S s0(arr);
    cout << s0.func() << endl;
    return 0;
}
