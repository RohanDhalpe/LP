#include<iostream>
using namespace std;

void bestfit(int blocksize[],int m,int processsize[],int n)
{    
    int allocation[n];
    for(int j=0;j<n;j++){
        allocation[j]=-1;
    }
   
    for(int i=0;i<n;i++)
    {  int bestidx=-1;
       for(int j=0;j<m;j++)
       {
          if(blocksize[j]>=processsize[i])
          {
             if(bestidx==-1)
             {
              bestidx=j;
             } else if(blocksize[bestidx]>blocksize[j])
             {
               bestidx=j;
             }
          }
       }
       
    if(bestidx!=-1)
    {
      allocation[i]=bestidx;
        blocksize[bestidx] =blocksize[bestidx]- processsize[i];
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
    bestfit(blocksize,m,processsize,n);
    return 0;
}
