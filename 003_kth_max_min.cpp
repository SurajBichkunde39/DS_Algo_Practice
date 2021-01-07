// Find Kth max and min element in an array
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kth_max_element(int ar[], int k, int n);
    int kth_max_element_heap(int ar[], int k, int n);
};
int Solution::kth_max_element(int ar[], int k, int n)
{
    //using cpp-STL
    priority_queue<int> tracker;
    for (int i = 0; i < n; i++)
        tracker.push(ar[i]);
    int result;
    for (int i = 0; i < k - 1; i++)
    {
        // cout << tracker.top() << " ";
        tracker.pop();
    }
    // cout << endl;
    result = tracker.top();
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
        int k;
        cin >> k;
        Solution a;
        cout << a.kth_max_element(ar, k, n) << endl;
    }
    getchar();
    getchar();
    return 0;
}