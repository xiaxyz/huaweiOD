#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class S
{
private:
    string num_str;
    map<char, int> used;
    map<char, int> unused;
    string result;
public:
    S(string num_str_);
    ~S();
    string func();
};

S::S(string num_str_) : num_str(num_str_)
{
    for (auto x : num_str)
    {
        unused[x]++;
    }
}

S::~S()
{
}

string S::func()
{
    result.push_back(num_str[0]);
    ++used[num_str[0]];
    --unused[num_str[0]];
    for (int i = 1; i < num_str.size(); ++i)
    {
        char temp_num = num_str[i];
        if (used[temp_num] < 2)
        {
            if (temp_num > result.back() && used[result.back()] + unused[result.back()] > 2)
            {
                --used[result.back()];
                result.pop_back();
            }
            ++used[temp_num];
            result.push_back(temp_num);
        }
        --unused[temp_num];
    }
    return result;
}

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    S s0(str);
    cout << s0.func() << endl;
    return 0;
}
