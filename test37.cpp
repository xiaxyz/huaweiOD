#include <vector>
#include <string>
#include <utility>
#include <iostream>

using namespace std;

class S
{
private:
    vector<pair<int, string>> arr1;
    vector<pair<int, string>> arr2;
    int count;
    int difference;

public:
    S(vector<pair<int, string>> arr1_, vector<pair<int, string>> arr2_);
    ~S();
    string func()
    {
        int index1 = 0;
        int step1 = 0;
        int index2 = 0;
        int step2 = 0;
        int step = 0;
        while (step <= count)
        {
            if (step1 > arr1[index1].first)
            {
                step1 = 0;
                ++index1;
            }
            if (step2 > arr2[index2].first)
            {
                step2 = 0;
                ++index2;
            }
            if (arr1[index1].second != arr2[index2].second)
            {
                ++difference;
            }
            ++step1;
            ++step2;
            ++step;
        }
        return string(to_string(difference) + '/' + to_string(count));
    }
};

S::S(vector<pair<int, string>> arr1_, vector<pair<int, string>> arr2_) : arr1(arr1_), arr2(arr2_), count(0), difference(0)
{
    for (int i = 0; i < arr1.size(); ++i)
    {
        count += arr1[i].first;
    }
}

S::~S()
{
}

int main(int argc, char const *argv[])
{
    string a, b;
    cin >> a >> b;
    vector<pair<int, string>> arr1, arr2;
    string count;
    string str;
    bool mark = false;
    for (const auto &a_x : a)
    {
        if (a_x >= '0' && a_x <= '9')
        {
            if (mark)
            {
                mark = false;
                arr1.push_back({stoi(count), str});
                count.clear();
                str.clear();
            }
            count.push_back(a_x);
        }
        else
        {
            mark = true;
            str.push_back(a_x);
        }
    }
    if (mark)
    {
        mark = false;
        arr1.push_back({stoi(count), str});
        count.clear();
        str.clear();
    }
    for (const auto &b_x : b)
    {
        if (b_x >= '0' && b_x <= '9')
        {
            if (mark)
            {
                mark = false;
                arr2.push_back({stoi(count), str});
                count.clear();
                str.clear();
            }
            count.push_back(b_x);
        }
        else
        {
            mark = true;
            str.push_back(b_x);
        }
    }
    if (mark)
    {
        mark = false;
        arr2.push_back({stoi(count), str});
        count.clear();
        str.clear();
    }
    S s0(arr1, arr2);
    cout << s0.func() << endl;
    return 0;
}
