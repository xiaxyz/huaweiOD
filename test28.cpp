#include <set>
#include <sstream>
#include <iostream>

using namespace std;

class S
{
private:
    int task1, task2, num;
    set<int> result;
public:
    S(int task1_, int task2_, int num_);
    ~S();
    set<int> func();
};

S::S(int task1_, int task2_, int num_) : task1(task1_), task2(task2_), num(num_)
{
}

S::~S()
{
}

set<int> S::func()
{
    int time = task1 * num;
    result.insert(time);
    for (int i = 0; i < num; ++i)
    {
        time += task2;
        time -= task1;
        result.insert(time);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);
    stringstream ss(str);
    string task1, task2, num;
    getline(ss, task1, ',');
    getline(ss, task2, ',');
    getline(ss, num, ',');
    S s0(stoi(task1), stoi(task2), stoi(num));
    auto result = s0.func();
    string res_str = "[";
    for (const auto &x : result)
    {
        res_str.append(to_string(x));
        res_str.append(", ");
    }
    res_str.pop_back();
    res_str.pop_back();
    res_str.push_back(']');
    cout << res_str << endl;
    return 0;
}
