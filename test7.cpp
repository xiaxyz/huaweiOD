#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class S
{
private:
    int count;
    int size;
    unordered_map<char, int> mark;
public:
    S(int _count, int _size, unordered_map<char, int> _mark);
    ~S();

    int func();
};

S::S(int _count, int _size, unordered_map<char, int> _mark) : count(_count), size(_size), mark(_mark)
{
}

S::~S()
{
}

int S::func()
{
    int a = size / count;
    int b = size % count;
    int num = 1;
    for (int i = 0; i < a - 1; ++i)
    {
        num *= 10;
    }
    if (b != 0)
    {
        return num * 10 + b - count;
    }
    for (int i = num - 1; i < num * 10 - count + 1; ++i)
    {
        unordered_map<char, int> n_count;
        for (int j = i; j < i + count; ++j)
        {
            for (auto x : to_string(j))
            {
                n_count[x]++;
            }
        }
        bool flag = true;
        for (auto x : n_count)
        {
            if (x.second != mark[x.first])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return i;
        }
    }
    return -1;
}


int main(int argc, char const *argv[])
{
    string str;
    int count;
    cin >> str >> count;
    unordered_map<char, int> mark;
    for (int i = 0; i < str.size(); ++i)
    {
        mark[str[i]]++;
    }
    S s0(count, str.size(), mark);
    cout << s0.func() << endl;
    return 0;
}
