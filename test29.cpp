#include <iostream>
#include <vector>

using namespace std;

class S
{
private:
    vector<int> a;
    vector<int> b;
    int r;
    vector<vector<int>> result;
public:
    S(vector<int> a_, vector<int> b_, int r_);
    ~S();

    vector<vector<int>> func();
};

S::S(vector<int> a_, vector<int> b_, int r_) : a(a_), b(b_), r(r_)
{
}

S::~S()
{
}

vector<vector<int>> S::func()
{
    int mark = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        while (b[mark] < a[i])
        {
            ++mark;
        }
        if (b[mark] - a[i] <= r)
        {
            result.push_back({a[i], b[mark]});
            ++mark;
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int m, n, r;
    cin >> m >> n >> r;
    vector<int> a(m), b(n);
    for (int i = 0; i < m; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];
    }
    S s0(a, b, r);
    auto result = s0.func();
    for (const auto &x : result)
    {
        cout << x[0] << " " << x[1] << endl;
    }
    return 0;
}
