// rotate the array by k-cycle
#include <iostream>
using namespace std;
class Solution
{
public:
    void print_rotate_array(int ar[], int n, int k);
};
void Solution::print_rotate_array(int ar[], int n, int k)
{
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = ar[i];
    }
    k = k % n;
    int index;
    for (int i = 0; i < n; i++)
    {
        index = (i + k) % n;
        ar[index] = temp[i];
    }
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
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
        int k;
        cin >> k;
        int ar[n];
        for (int i = 0; i < n; i++)
            cin >> ar[i];
        Solution a;
        a.print_rotate_array(ar, n, k);
    }
    getchar();
    getchar();
    return 0;
}