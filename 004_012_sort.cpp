// Given an array which consist of only 0,1,2 sort the array using any sorting algorithm
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void splecial_sort(int ar[], int n);
    void non_inplace_sorting(int ar[], int n);
    void simple_count_method(int ar[], int n);
};
void Solution::non_inplace_sorting(int ar[], int n)
{
    int new_ar[n];
    int zero_index = 0;
    int two_index = n - 1;

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] == 0)
        {
            new_ar[zero_index] = 0;
            zero_index++;
        }
        else if (ar[i] == 2)
        {
            new_ar[two_index] = 2;
            two_index--;
        }
    }
    while (zero_index != two_index + 1)
    {
        new_ar[zero_index] = 1;
        zero_index++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << new_ar[i] << " ";
    }
    cout << endl;
}
void Solution::simple_count_method(int ar[], int n)
{
    int zero_count = 0;
    int one_count = 0;
    int two_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] == 0)
            zero_count++;
        else if (ar[i] == 1)
            one_count++;
        else
            two_count++;
    }
    int index = 0;
    int i = 0;
    while (i != zero_count)
    {
        ar[index] = 0;
        i++;
        index++;
    }
    i = 0;
    while (i != one_count)
    {
        ar[index] = 1;
        i++;
        index++;
    }
    i = 0;
    while (i != two_count)
    {
        ar[index] = 2;
        i++;
        index++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}
void Solution::splecial_sort(int ar[], int n)
{
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
        Solution s;
        s.simple_count_method(ar, n);
    }
    getchar();
    getchar();
    return 0;
}