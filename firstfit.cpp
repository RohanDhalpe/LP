#include<bits/stdc++.h>
using namespace std;

void firstfit(int blocksize[], int m, int processsize[], int n)
{  
    int allocation[n];
  for(int j=0;j<n;j++){
    allocation[j]=-1;
  }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blocksize[j] >= processsize[i])
            {
                allocation[i] = j;
                blocksize[j]=blocksize[j]-processsize[i];
                break;
            }
        }
    }
 
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i+1 << "\t\t"
             << processsize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{
    int blocksize[] = {100, 500, 200, 300, 600};
    int processsize[] = {212, 417, 112, 426};
    int m = sizeof(blocksize) / sizeof(blocksize[0]);
    int n = sizeof(processsize) / sizeof(processsize[0]);
 
    firstfit(blocksize, m, processsize, n);
 
    return 0 ;
}
