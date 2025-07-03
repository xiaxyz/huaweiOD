#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

class S
{
private:
    vector<vector<string>> arr;
    vector<set<string>> result;
public:
    S(vector<vector<string>> arr_);
    ~S();

    vector<set<string>> func();
};

S::S(vector<vector<string>> arr_) : arr(arr_), result(2)
{
}

S::~S()
{
}

vector<set<string>> S::func()
{
    bool flag = false;
    result[0].insert(arr[0][0]);
    for (int i = 1; i < arr.size(); ++i)
    {
        if ((!flag && arr[i][1] == "Y") || (flag && arr[i][1] == "N"))
        {
            result[0].insert(arr[i][0]);
        }
        else 
        {
            result[1].insert(arr[i][0]);
        }
        if (arr[i][1] == "N")
        {
            flag = !flag;
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    string str;
    getline(cin, str);
    stringstream ss(str);
    string student;
    vector<vector<string>> arr;
    while(getline(ss, student, ' '))
    {
        stringstream temp(student);
        string a,b;
        getline(temp, a, '/');
        getline(temp, b, '/');
        arr.push_back({a, b});
    }
    S s0(arr);
    auto result = s0.func();
    for (const auto &x : result[0])
    {
        cout << x << " ";
    }
    cout << endl;
    for (const auto &x : result[1])
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
