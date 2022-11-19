
#include <bits/stdc++.h>
using namespace std;
void nextfit(int blocksize[],int m,int processsize[] ,int n)
{   int allocation[n];
   for(int j=0;j<n;j++){
       allocation[j]=-1;
   }
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        int j;
        for( j=cnt; j<m; j++)
        {
            if(blocksize[j]>=processsize[i])
            {
                allocation[i]=j;
                blocksize[j]=blocksize[j]-processsize[i];
                break;
            }
            
        }cnt=j;
    }
    
    cout<<"\nprocessno.\tprocesssize\tblock no\n";
    for(int i=0;i<n;i++){
        cout<<" "<<i+1<<"\t\t";
        cout<<processsize[i]<<"\t\t";
        if(allocation[i]!=-1){
            cout<<allocation[i]+1;
        }
        else{
            cout<<"not allocation";
        }
        cout<<endl;
    }
    
}
int main()
{ int blocksize[] = {100, 500, 200, 300, 600};
	int processsize[] = {212, 417, 112, 426};
	int m = sizeof(blocksize) / sizeof(blocksize[0]);
	int n = sizeof(processsize) / sizeof(processsize[0]);
	
   nextfit(blocksize,m,processsize,n);

    return 0;
}

