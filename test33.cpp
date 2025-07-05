#include <string>
#include <map>
#include <iostream>

using namespace std;

class S
{
private:
    map<char, int> mp;
    int n;
    int result;
    string result_str;
    void func1()
    {
        if (result_str.size() == n)
        {
            ++result;
            return;
        }
        for (auto &mp_x : mp)
        {
            if (mp_x.second > 0 && (result_str.empty() || mp_x.first != result_str.back()))
            {
                result_str.push_back(mp_x.first);
                --mp_x.second;
                func1();
                result_str.pop_back();
                ++mp_x.second;
            }
        }
    }

public:
    S(map<char, int> mp_, int n_);
    ~S();

    int func()
    {
        func1();
        return result;
    }
};

S::S(map<char, int> mp_, int n_) : mp(mp_), n(n_), result(0)
{
}

S::~S()
{
}

int main(int argc, char const *argv[])
{
    string str;
    int n;
    cin >> str >> n;
    map<char, int> mp;
    for (const auto &str_x : str)
    {
        ++mp[str_x];
    }
    S s0(mp, n);
    cout << s0.func() << endl;
    return 0;
}
