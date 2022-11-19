#include<iostream>
using namespace std;

void worstfit(int blocksize[],int m,int processsize[],int n)
{    
    int allocation[n];
    for(int j=0;j<n;j++){
        allocation[j]=-1;
    }
   
    for(int i=0;i<n;i++)
    {  int worstidx=-1;
       for(int j=0;j<m;j++)
       {
          if(blocksize[j]>=processsize[i])
          {
             if(worstidx==-1)
             {
              worstidx=j;
             } else if(blocksize[worstidx]<blocksize[j])
             {
               worstidx=j;
             }
          }
       }
       
    if(worstidx!=-1)
    {
      allocation[i]=worstidx;
        blocksize[worstidx] =blocksize[worstidx]- processsize[i];
    }
   }
  
 cout<<"\nprocessno\tprocesssize\tprocessno\n";
 for(int i=0;i<n;i++){
   cout<<" "<<i+1<<"\t\t"<<processsize[i]<<"\t\t";
   if(allocation[i]!=-1) cout<<allocation[i]+1;
   else cout<<"not allocated";
   cout<<endl;
 }

}
int main(){
    int blocksize[]={500,400,300,450,250};
    int processsize[]={110,210,320,410,150};
    int m=sizeof(blocksize)/sizeof(blocksize[0]);
    int n=sizeof(processsize)/sizeof(processsize[0]);
    worstfit(blocksize,m,processsize,n);
    return 0;
}
