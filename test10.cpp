#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

class S
{
private:
    set<string> word;
    string front;
    vector<string> result;

public:
    S(set<string> _word, string _front);
    ~S();

    vector<string> func();
};

S::S(set<string> _word, string _front) : word(_word), front(_front)
{
}

S::~S()
{
}

vector<string> S::func()
{
    for (auto x : word)
    {
        if (x.find(front) == 0)
        {
            result.push_back(x);
        }
    }
    if (result.empty())
    {
        result.push_back(front);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    string str;
    string front;
    getline(cin, str);
    getline(cin, front);
    replace_if(str.begin(), str.end(), [](char c){return !isalpha(c);}, ' ');
    stringstream ss(str);
    set<string> word;
    string one;
    while (ss >> one)
    {
        word.insert(one);
    }
    S s0(word, front);
    for (auto x : s0.func())
    {
        cout << x << " ";
    }
    return 0;
}
