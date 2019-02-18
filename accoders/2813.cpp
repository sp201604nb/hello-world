#include <cstdio>
using namespace std;
int A[1000009];
int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++)scanf("%d",&A[i]);
    int maxSum = A[0];
    int low=0;
    int high=0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        
        for (int j = i+1; j>=0; j--)
        {
            sum += A[j];
            if (sum>maxSum)
            {
                maxSum = sum;
                low = j;
                high = i + 1;
            }
        }
    }
    printf("%d\n%d\n%d", low, high,maxSum);
    return 0;
}
