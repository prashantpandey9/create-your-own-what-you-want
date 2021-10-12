#include <bits/stdc++.h>
using namespace std;
bool compare(const string &a, const string &b)
{
    if (b.find(a) == 0)
    {
        return b.at(a.size()) < a.at(0);
    }
    else if (a.find(b) == 0)
        return a.at(b.size()) > b.at(0);
    else
    {
        return a > b;
    }
}
string concatenate(vector<int> numbers)
{
    //complete this method and return the largest number you can form as a string
    vector<string> vs;
    string out;
    for (auto x : numbers)
    {
        vs.push_back(to_string(x));
    }
    sort(vs.begin(), vs.end(), compare);
    for (auto x : vs)
    {
        //cout << x << " ";
        out += x;
    }
    //cout << "\n";
    return out;
}
int main()
{
    vector<int> numbers = {10, 20, 11, 30, 3};
    string st = concatenate(numbers);
    cout << st;
    return 0;
}
/*
345 34
43 45
*/
