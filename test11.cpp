#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

class S
{
private:
    vector<int> score;
    vector<int> result;
    int min_score;
public:
    S(vector<int> _score);
    ~S();
    int func(int index);
};

S::S(vector<int> _score) : score(_score), min_score(0)
{
    for (auto x : score)
    {
        min_score += x;
    }
}

S::~S()
{
}

int S::func(int index)
{
    if (index == score.size())
    {
        bool flag = true;
        int num = result[0];
        for (auto x : result)
        {
            if (x != num)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return num;
        }
        return min_score;
    }
    result.push_back(score[index]);
    min_score = min(min_score, func(index + 1));
    for (int i = index + 1; i < score.size(); ++i)
    {
        result.back() += score[i];
        min_score = min(min_score, func(i + 1));
        result.back() -= score[i];
    }
    result.pop_back();
    return min_score;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> score(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> score[i];
    }
    S s0(score);
    cout << s0.func(0) << endl;
    return 0;
}
