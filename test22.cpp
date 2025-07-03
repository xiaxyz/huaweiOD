#include <string>
#include <iostream>

using namespace std;

class S
{
private:
    string s;
    string l;
public:
    S(string s_, string l_);
    ~S();

    int func();
};

S::S(string s_, string l_) : s(s_), l(l_)
{
}

S::~S()
{
}

int S::func()
{
    int i = 0;
    int j = 0;
    while(i < s.size() && j < l.size())
    {
        if (s[i] == l[j])
        {
            ++i;
        }
        ++j;
    }
    if (i >= s.size())
    {
        return j - 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    string s, l;
    cin >> s >> l;
    S s0(s, l);
    cout << s0.func() << endl;
    return 0;
}

