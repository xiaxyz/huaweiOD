#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class S
{
private:
    vector<int> tree;
    vector<int> step;
    vector<int> result;
    int result_num;

public:
    S(vector<int> _tree);
    ~S();
    vector<int> func();
    void func1(int index);
};

S::S(vector<int> _tree) : tree(_tree), step(), result(), result_num(-1)
{
}

S::~S()
{
}

vector<int> S::func()
{
    step.push_back(tree[0]);
    func1(0);
    return result;
}

void S::func1(int index)
{
    int left = 2 * index + 1;
    int right = left + 1;
    if ((left >= tree.size() || tree[left] == -1) && (right >= tree.size() || tree[right] == -1))
    {
        if (result_num == -1 || tree[index] < result_num)
        {
            result_num = tree[index];
            result = step;
        }
        return;
    }
    if (left < tree.size() && tree[left] != -1)
    {
        step.push_back(tree[left]);
        func1(left);
        step.pop_back();
    }
    if (right < tree.size() && tree[right] != -1)
    {
        step.push_back(tree[right]);
        func1(right);
        step.pop_back();
    }
    return;
}

int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<int> tree;
    int temp_in;
    while(ss >> temp_in)
    {
        tree.push_back(temp_in);
    }
    S s0(tree);
    auto result = s0.func();
    for (auto x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
