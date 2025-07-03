#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class S
{
private:
    vector<string> arr;
    int min_num;
public:
    S(vector<string> _arr);
    ~S();
    int func();
    void func1(int index);
};

S::S(vector<string> _arr) : arr(_arr), min_num(-1)
{
}

S::~S()
{
}

int S::func()
{
    func1(0);
    return min_num;
}

void S::func1(int index)
{
    if (index == arr.size())
    {
        string num_str;
        for (int i = 0; i < arr.size(); ++i)
        {
            num_str.append(arr[i]);
        }
        int num = stoi(num_str);
        if (min_num == -1 || min_num > num)
        {
            min_num = num;
        }
        return;
    }
    func1(index + 1);
    for (int i = index + 1; i < arr.size(); ++i)
    {
        swap(arr[index], arr[i]);
        func1(i);
        swap(arr[index], arr[i]);
    }
    return;
}

int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);
    stringstream ss(str);
    string num_str;
    vector<int> arr;
    while(getline(ss, num_str, ','))
    {
        arr.push_back(stoi(num_str));
    }
    sort(arr.begin(), arr.end());
    vector<string> num_arr;
    for (int i = 0; i < 3 && i < arr.size(); ++i)
    {
        num_arr.push_back(to_string(arr[i]));
    }
    S s0(num_arr);
    cout << s0.func() << endl;
    return 0;
}
