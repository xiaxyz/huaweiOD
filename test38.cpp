#include <iostream>
#include <map>
#include <vector>

using namespace std;

class S
{
private:
    map<int, int> used;
    int start;
    int end;

public:
    S(int start_, int end_);
    ~S();

    int REQUEST(int x)
    {
        int empty_start;
        int empty_end;
        for (auto it = used.begin(); next(it) != used.end(); ++it)
        {
            empty_start = it->second + 1;
            empty_end = next(it)->first - 1;
            if (empty_end - empty_start + 1 >= x)
            {
                used.insert({empty_start, empty_start + x - 1});
                return empty_start;
            }
        }
        throw string("Request");
    }
    void RELEAS(int x)
    {
        if (used.find(x) != used.end())
        {
            used.erase(x);
            return;
        }
        throw string("Releas");
    }
};

S::S(int start_, int end_) : used(), start(start_), end(end_)
{
    used.insert({start - 1, start - 1});
    used.insert({end + 1, end + 1});
}

S::~S()
{
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<string> str(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> str[i];
    }
    S s0(0, 99);
    int f;
    for (const auto &str_x : str)
    {
        f = str_x.find('=');
        try
        {
            if (str_x.find("REQUEST") != string::npos)
            {
                cout << s0.REQUEST(stoi(str_x.substr(str_x.find('=') + 1))) << endl;
            }
            else if (str_x.find("") != string::npos)
            {
                s0.RELEAS(stoi(str_x.substr(str_x.find('=') + 1)));
            }
        }
        catch (const string &e)
        {
            std::cout << "Error" << endl;
        }
    }
    return 0;
}
