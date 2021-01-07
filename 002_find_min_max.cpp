// Minimum and maximum of arrray using minimum number of comparison
#include <bits/stdc++.h>
using namespace std;
struct min_max
{
    int min;
    int max;
};
class Solution
{
public:
    min_max Find_Min_Max(int ar[], int n);         // brute force solution
    min_max Find_Min_Max_optimal(int ar[], int n); // optimal solution
    min_max divide_and_concure(int ar[], int left, int right);
};
min_max Solution::Find_Min_Max(int ar[], int n)
{
    min_max result;
    int min = ar[0];
    int max = ar[0];
    for (int i = 1; i < n; i++)
    {
        if (ar[i] > max)
            max = ar[i];
        else if (ar[i] < min)
            min = ar[i];
    }
    result.min = min;
    result.max = max;
    return result;
}
min_max Solution::Find_Min_Max_optimal(int ar[], int n)
{
    min_max result;
    if (n == 1)
    {
        result.min = ar[0];
        result.max = ar[0];
    }
    else if (n == 2)
    {
        if (ar[0] > ar[1])
        {
            result.min = ar[0];
            result.max = ar[1];
        }
        else
        {
            result.min = ar[1];
            result.max = ar[0];
        }
    }
    else
    {
        result = divide_and_concure(ar, 0, n - 1);
    }
    return result;
}

min_max Solution::divide_and_concure(int ar[], int left, int right)
{
    min_max result;
    if (left >= right)
    {
        result.min = ar[left];
        result.max = ar[left];
        return result;
    }
    else if (right == left + 1)
    {
        if (ar[left] > ar[right])
        {
            result.min = ar[right];
            result.max = ar[left];
        }
        else
        {
            result.min = ar[left];
            result.max = ar[right];
        }
        return result;
    }

    int mid = (left + right + 1) / 2;
    auto left_result = divide_and_concure(ar, left, mid - 1);
    auto right_result = divide_and_concure(ar, mid, right);

    if (left_result.min > right_result.min)
        result.min = right_result.min;
    else
        result.min = left_result.min;

    if (left_result.max > right_result.max)
        result.max = left_result.max;
    else
        result.max = right_result.max;

    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ar[n];
        for (int i = 0; i < n; i++)
            cin >> ar[i];
        Solution a;
        auto result = a.Find_Min_Max_optimal(ar, n);
        cout << "Min: " << result.min << "  Max:" << result.max << endl;
    }
    getchar();
    getchar();
    return 0;
}