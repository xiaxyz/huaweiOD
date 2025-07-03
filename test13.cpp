#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

class S
{
private:
    vector<pair<int, string>> arr;
    double result;
public:
    S(vector<pair<int, string>> _arr);
    ~S();
    int func();
    double func1(int a, string b);
};

S::S(vector<pair<int, string>> _arr) : arr(_arr)
{
}

S::~S()
{
}

int S::func()
{
    for (int i = 0; i < arr.size(); ++i)
    {
        result += func1(arr[i].first, arr[i].second);
    }
    return int(result);
}

double S::func1(int a, string b)
{
    if (b == "fen")
    {
        return a * 1.0;
    }
    else if (b == "cents")
    {
        return a * 100.0 / 123;
    }
    else if (b == "sen")
    {
        return a * 100.0 / 1825;
    }
    else if (b == "eurocents")
    {
        return a * 100.0 / 14;
    }
    else if (b == "pence")
    {
        return a * 100.0 / 12;
    }
    else if (b == "CNY")
    {
        return func1(a * 100, "fen");
    }
    else if (b == "JPY")
    {
        return func1(a * 100, "sen");
    }
    else if (b == "HKD")
    {
        return func1(a * 100, "cents");
    }
    else if (b == "EUR")
    {
        return func1(a * 100, "eurocents");
    }
    else if (b == "GBP")
    {
        return func1(a * 100, "pence");
    }
    return 0.0;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cin.ignore();
    vector<pair<int, string>> amount;
    for (int i = 0; i < n; ++i)
    {
        string str;
        getline(cin, str);
        for (int j = 0; j < str.size();)
        {
            string num_str;
            string unit;
            while(j < str.size() && isdigit(str[j]))
            {
                num_str.push_back(str[j]);
                ++j;
            }
            while (j < str.size() && !isdigit(str[j]))
            {
                unit.push_back(str[j]);
                ++j;
            }
            amount.push_back({stoi(num_str), unit});
        }
    }
    S s0(amount);
    cout << s0.func() << endl;
    return 0;
}
