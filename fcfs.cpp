#include<iostream>
using namespace std;
int main(){
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    cout<<"Enter the total number of processes";
    cin>>n;

    cout<<"\nEnter process burst time:\n";
    for( i=0;i<n;i++)
    {
      cout<<"p["<<i+1<<"]:";
      cin>>bt[i];
    }

    wt[0]=0;
    //calculating waiting time
    for( i=1;i<n;i++){
        wt[i]=0;
        for( j=0;j<i;j++){
            wt[i]=wt[i]+bt[j];
        }
    }
    //calculating turnaround time
   for( i=0;i<n;i++)
   {   tat[i]=bt[i]+wt[i];
       avwt=avwt+wt[i];
       avtat=avtat+tat[i];
       cout<<"\nprocess\tBurst time\twaiting time\tturnaround time\n";
       cout<<"p["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\n";

   }
   avwt=avwt/i;
   avtat=avtat/i;

   cout<<"\nAVG WAITING TIME:"<<avwt<<endl;
   cout<<"\n AVG  TURNAROUND TIME:"<<avtat<<endl;



 return 0;
}
