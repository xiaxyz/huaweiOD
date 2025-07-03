#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class S
{
private:
    vector<int> m;
    vector<int> n;

public:
    S(int _m, vector<int> _n);
    ~S();
    int func();
};

S::S(int _m, vector<int> _n) : m(_m, 0), n(_n)
{
}

S::~S()
{
}

int S::func()
{
    for (int i = 0; i < n.size(); ++i)
    {
        m[i % m.size()] += n[i];
    }
    return m[(n.size() - 1) % m.size()];
}

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), less<int>());
    S s0(m, arr);
    cout << s0.func() << endl;
    return 0;
}
