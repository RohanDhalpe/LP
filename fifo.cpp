#include<iostream>
using namespace std;

void fifo(int arr[],int size,int frame[],int f_size){
    cout<<" Fifo page replacement"<<"\n";
    int hits=0;
    int miss=0;
    int ptr=0;
    for(int i=0; i<size;i++)
    {   bool flag=0;
        for(int j=0; j<f_size;j++){
            if(arr[i]==frame[j]){
                flag=true;
                break;
            }
        }

        if(flag==true) hits++;
        else{
            miss++;
            frame[ptr]=arr[i];
            if(ptr=f_size-1) ptr=0;
            ptr++;
        }

        for(int k=0; k<f_size;k++){
            cout<<frame[k]<<" ";
        }
      cout<<"\n";

    }
    cout<<"\n";
    cout<<"Total hit:"<<hits<<endl;
    cout<<"Total miss:"<<miss<<endl;

}
int main(){
  int size;
  cout<<"Enter the number of pages :";
  cin>>size;
  cout<<"\n";

  int arr[size];
  cout<<"Enter the pages:";
  for(int i=0;i<size;i++) cin>>arr[i];
  cout<<"\n";

  int f_size;
  cout<<"Enter the frame size:";
  cin>>f_size;
  cout<<"\n";

  int frame[f_size];
  for(int j=0;j<f_size;j++){
    frame[j]=-1;
  }

  fifo(arr,size,frame,f_size);
 cout<<"\n";
    return 0;
}
