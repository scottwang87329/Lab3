#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    fstream fin("./file.in", ios::in);
    int N;
    vector<int> v;
    fin >> N;
    for(int i=0, in;i<N;i++)
    {
        fin >> in;
        v.push_back(in);
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for(int i=1;i<=5;i++)
        sum += v[N-i];
    cout << sum << endl;
    return 0;
}
