#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class S
{
private:
    vector<vector<int>> arr;
public:
    S(vector<vector<int>> _arr);
    ~S();
    int func();
};

S::S(vector<vector<int>> _arr) : arr(_arr)
{
}

S::~S()
{
}

int S::func()
{
    vector<int> a(4);
    a[0] = max(arr[0][0], max(arr[1][0], arr[2][0]));
    a[1] = min(arr[0][1], min(arr[1][1], arr[2][1]));
    a[2] = min(arr[0][2], min(arr[1][2], arr[2][2]));
    a[3] = max(arr[0][3], max(arr[1][3], arr[2][3]));
    int result = (a[2] - a[0]) * (a[1] - a[3]);
    return max(result, 0);
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> arr(3, vector<int>(4));
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cin >> arr[i][j];
        }
        cin >> arr[i][2];
        arr[i][2] += arr[i][0];
        cin >> arr[i][3];
        arr[i][3] = arr[i][1] - arr[i][3];
    }
    S s0(arr);
    cout << s0.func() << endl;
    return 0;
}
