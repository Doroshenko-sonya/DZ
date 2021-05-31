#include <bits/stdc++.h>
using namespace std;

int comp (const int *i, const int *j){
    return *i - *j;
}

 
int main()
{
    
    int n;
    int arr[n];
    cout << "INPUT ARRAY SIZE (PARAMETER N): ";
    cin >> n;
    
   
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if( arr[i] == 0)
        {
          i = n+1;
        }
    }
  
    
    qsort(arr, n, sizeof(int), (int(*) (const void *, const void *)) comp);
    
    
    int x1;
    for ( int i = 0; i < n; i++)
    {
        if( arr[i] < 0 && arr[i] > arr[i-1] && x1 > arr[i])
        {
            x1 = arr[i];
        }
        else if ( arr[i] > 0 && arr[i] < arr[i-1] && x1 < arr[i])
        {
            x1 = arr[i];
        }
    }
    
    cout << x1 << endl;

    return 0;
}
 

