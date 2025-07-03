#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class S
{
private:
    string front, back;

public:
    S(string _front, string _back);
    ~S();
    string func();
};

S::S(string _front, string _back) : front(_front), back(_back)
{
}

S::~S()
{
}

string S::func()
{
    while (!front.empty() && front.back() == '/')
    {
        front.pop_back();
    }
    while (!back.empty() && back.front() == '/')
    {
        back.erase(0, 1);
    }
    front.push_back('/');
    return front.append(back);
}

int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);
    stringstream ss(str);
    string front, back;
    getline(ss, front, ',');
    getline(ss, back, ',');
    S s0(front, back);
    cout << s0.func() << endl;
    return 0;
}
