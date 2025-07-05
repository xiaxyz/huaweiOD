#include <iostream>

using namespace std;

class S
{
private:
    int m;
    int count;
    int target;
    int result;
    void func1(int num, int index)
    {
        if (index > count)
        {
            index = 1;
        }
        if (num <= 7)
        {
            if (num == 7 && index == target)
            {
                ++result;
            }
            return;
        }
        func1(num - 1, index + 1);
        func1(num - 2, index + 1);
    }
public:
    S(int m_, int count_, int target_);
    ~S();
    int func()
    {
        func1(m, 1);
        return result;
    }
};

S::S(int m_, int count_, int target_) : m(m_), count(count_), target(target_), result(0)
{
}

S::~S()
{
}

int main(int argc, char const *argv[])
{
    int m;
    cin >> m;
    S s0(m, 2, 2);
    cout << s0.func() << endl;
    return 0;
}
