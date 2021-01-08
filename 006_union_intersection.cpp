// Find the union and intersection of two sorted arrays
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> interseciton(vector<int> ar1, vector<int> ar2);
    vector<int> union_(vector<int> ar1, vector<int> ar2);
};
vector<int> Solution::interseciton(vector<int> ar1, vector<int> ar2)
{
    vector<int> result;
    int len1 = ar1.size();
    int len2 = ar2.size();
    int fp = 0;
    int sp = 0;
    int res_len = 0;
    while (fp < len1 && sp < len2)
    {
        if (ar1[fp] == ar2[sp])
        {
            result.push_back(ar1[fp]);
            int val = ar1[fp];
            while (fp < len1 && ar1[fp] == val)
                fp++;
            while (sp < len2 && ar2[sp] == val)
                sp++;
        }
        while (fp < len1 && sp < len2 && ar1[fp] < ar2[sp])
            fp++;
        while (fp < len1 && sp < len2 && ar2[sp] < ar1[fp])
            sp++;
    }
    return result;
}
vector<int> Solution::union_(vector<int> ar1, vector<int> ar2)
{
    vector<int> result;
    int len1 = ar1.size();
    int len2 = ar2.size();
    int fp = 0;
    int sp = 0;

    while (fp < len1 && sp < len2)
    {
        if (ar1[fp] == ar2[sp])
        {
            result.push_back(ar1[fp]);
            int val = ar1[fp];
            while (ar1[fp] == val)
                fp++;
            while (ar2[sp] == val)
                sp++;
        }
        while (fp < len1 && sp < len2 && ar1[fp] < ar2[sp])
        {
            result.push_back(ar1[fp]);
            fp++;
        }
        while (fp < len1 && sp < len2 && ar2[sp] < ar1[fp])
        {
            result.push_back(ar2[sp]);
            fp++;
        }
    }
    while (fp < len1)
    {
        result.push_back(ar1[fp]);
        fp++;
    }
    while (sp < len2)
    {
        result.push_back(ar2[sp]);
        sp++;
    }
    return result;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> ar1, ar2;
        int temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            ar1.push_back(temp);
        }
        for (int i = 0; i < m; i++)
        {
            cin >> temp;
            ar2.push_back(temp);
        }
        Solution a;
        vector<int> u = a.union_(ar1, ar2);
        vector<int> i = a.interseciton(ar1, ar2);
        cout << "union of the sorted arrays" << endl;
        for (int x : u)
            cout << x << " ";
        cout << endl
             << "intersection of the sorted arrays" << endl;
        for (int x : i)
            cout << x << " ";
    }
    getchar();
    getchar();
    return 0;
}