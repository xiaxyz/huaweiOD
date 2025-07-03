#include <iostream>
#include <string>

using namespace std;

class S
{
private:
    int flaw;
    string str;

public:
    S(int flaw_, string str_);
    ~S();

    int func();
};

S::S(int flaw_, string str_) : flaw(flaw_), str(str_)
{
}

S::~S()
{
}

int S::func()
{
    int left = 0, right = 0;
    int temp_flaw = 0;
    int result = 0;
    string find_str = "aeiouAEIOU";
    while (right < str.size())
    {
        if (find_str.find(str[right]) == string::npos)
        {
            ++temp_flaw;
            if (temp_flaw > flaw)
            {
                result = result > right - left ? result : right - left;
                while(find_str.find(str[left]) != string::npos)
                {
                    ++left;
                }
                ++left;
            }
        }
        ++right;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int flaw;
    string str;
    cin >> flaw >> str;
    S s0(flaw, str);
    cout << s0.func() << endl;
    return 0;
}
