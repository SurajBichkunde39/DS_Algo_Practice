// Move all the negative elements to one side of the array
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void with_extra_space(int ar[], int n);
    void without_extra_space(int ar[], int n);
};
void Solution::with_extra_space(int ar[], int n)
{
    int new_ar[n];
    int pos_index = n - 1;
    int neg_index = 0;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] >= 0)
        {
            new_ar[pos_index] = ar[i];
            pos_index--;
        }
        else
        {
            new_ar[neg_index] = ar[i];
            neg_index++;
        }
    }
    for (int i = 0; i < n; i++)
        cout << new_ar[i] << " ";
    cout << endl;
}
void Solution::without_extra_space(int ar[], int n)
{
    int first_positive = 0;
    int last_negative = n - 1;
    while (ar[first_positive] <= 0 && first_positive < n)
        first_positive++;
    while (ar[last_negative] > 0 && last_negative >= 0)
        last_negative--;
    cout << first_positive << " " << last_negative;
    while (first_positive <= last_negative)
    {
        // swap the first_positive and last_negative
        int temp = ar[first_positive];
        ar[first_positive] = ar[last_negative];
        ar[last_negative] = temp;

        //Find next positive value
        while (ar[first_positive] <= 0 && first_positive < n)
            first_positive++;
        //find previous negative value
        while (ar[last_negative] > 0 && last_negative >= 0)
            last_negative--;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
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
        {
            cin >> ar[i];
        }
        Solution s;
        s.without_extra_space(ar, n);
    }

    getchar();
    getchar();
    return 0;
}