#include <string>
#include <vector>
#include <iostream>

using namespace std;

class S
{
private:
    string str;
    int k;
    vector<string> arr;
    string result;

public:
    S(string str_, int k_);
    ~S();
    string func();
    void func1();
    void func2();
};

S::S(string str_, int k_) : str(str_), k(k_)
{
}

S::~S()
{
}

string S::func()
{
    func1();
    func2();
    return result;
}

void S::func1()
{
    bool flag = false;
    int mark = 0;
    arr.push_back("");
    for (int i = 0; i < str.size(); ++i)
    {
        if (flag)
        {
            if (str[i] != '-' && mark != k)
            {
                arr.back().push_back(str[i]);
                ++mark;
            }
            else if (str[i] != '-' && mark == k)
            {
                arr.push_back("");
                arr.back().push_back(str[i]);
                mark = 1;
            }
        }
        else
        {
            if (str[i] != '-')
            {
                arr.back().push_back(str[i]);
            }
            else
            {
                arr.push_back("");
                flag = true;
            }
        }
    }
}

void S::func2()
{
    for (auto x : arr)
    {
        int upper = 0;
        int lower = 0;
        for (auto y : x)
        {
            if (isupper(y))
            {
                ++upper;
            }
            else if (islower(y))
            {
                ++lower;
            }
        }
        if (upper > lower)
        {
            for (auto &y : x)
            {
                y = toupper(y);
            }
        }
        else if (upper < lower)
        {
            for (auto &y : x)
            {
                y = tolower(y);
            }
        }
        result.append(x);
        result.push_back('-');
    }
    result.pop_back();
}

int main(int argc, char const *argv[])
{
    int k;
    string str;
    cin >> k;
    cin.ignore();
    getline(cin, str);
    S s0(str, k);
    cout << s0.func() << endl;
    return 0;
}
