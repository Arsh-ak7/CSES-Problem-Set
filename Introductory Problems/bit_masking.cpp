#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
if (bitMasked & (1 << j))  
Above checks if jth bit of bitMasked is 1 or not.
lets say we want to mask the number 4.  
Binary -> 100 (Corresponds to inclusion of 3rd element from original array as we check the binary number from right)
so for 100 & 001 = 0 loop 1
       100 & 010 = 0 loop 2
       100 & 100 != 0 loop 3 So, here we do the encoding. So, inlclude the 3rd element of original array.  
Since we presume that while encoding a bit 1 stands for a number being included we only take the numbers(position wise in original array) where jth bit is 1.
*/
vector<vector<long long>> getSubsets(vector<long long> v)
{
    long long size = v.size();
    long long numberOfSubsets = 1 << size; // 1 << size = 2^size = 2^n
    vector<vector<long long>> allSubsets;
    for (long long bitMasked = 0; bitMasked < numberOfSubsets; ++bitMasked)
    {
        vector<long long> subsets;
        for (int j = 0; j < size; ++j)
        {
            if (bitMasked & (1 << j)) // checks if jth bit is 1 or not, if 0 returns 0.
            {
                subsets.push_back(v[j]);
            }
        }
        allSubsets.push_back(subsets);
    }
    return allSubsets;
}

int main()
{
    int n;
    cin >> n;
    long long a;
    vector<long long> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        v.push_back(a);
    }
    vector<vector<long long>> allSubsets = getSubsets(v);
    for (auto x : allSubsets)
    {
        for (auto j : x)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
