#include <vector>
#include <iostream>

using namespace std;

class S
{
private:
    vector<int> arr;
    vector<int> start;
    vector<int> result;
public:
    S(vector<int> arr_, vector<int> start_);
    ~S();
    vector<int> func();
    void func1(int index);
};

S::S(vector<int> arr_, vector<int> start_) : arr(arr_), start(start_), result(0)
{
}

S::~S()
{
}

vector<int> S::func()
{
    for (const auto &start_x : start)
    {
        func1(start_x);
    }
    result.push_back(0);
    for (int i = 0; i < arr.size(); ++i)
    {
        if (result[0] < arr[i])
        {
            result.clear();
            result.push_back(arr[i]);
            result.push_back(i);
        }
        else if (result[0] == arr[i])
        {
            result.push_back(i);
        }
    }
    result[0] = result.size() - 1;
    return result;
}

void S::func1(int index)
{
    int left = (index - 1 + arr.size()) % arr.size();
    int right = (index + 1) % arr.size();
    if (arr[left] == -1 || arr[left]  > arr[index] + 1)
    {
        arr[left] = arr[index] + 1;
        func1(left);
    }
    if (arr[right] == -1 || arr[right] > arr[index] + 1)
    {
        arr[right] = arr[index] + 1;
        func1(right);
    }
}

int main(int argc, char const *argv[])
{
    int n, e;
    cin >> n >> e;
    vector<int> arr(n, -1);
    int t, p;
    vector<int> start;
    for (int i = 0; i < e; ++i)
    {
        cin >> t >> p;
        start.push_back(p);
        arr[p] = t;
    }
    S s0(arr, start);
    auto result = s0.func();
    cout << result[0] << endl;
    for (int i = 1; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
