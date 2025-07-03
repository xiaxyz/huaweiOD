#include <regex>
#include <string>
#include <iostream>

using namespace std;

class S
{
private:
    string a, b;
public:
    S(string a_, string b_);
    ~S();

    int func();
};

S::S(string a_, string b_): a(a_), b(b_)
{
}

S::~S()
{
}

int S::func()
{
    regex pattern(b);
    smatch match;
    if (regex_search(a, match, pattern))
    {
        return match.position();
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    string a, b;
    cin >> a >> b;
    S s0(a, b);
    cout << s0.func() << endl;
    return 0;
}
