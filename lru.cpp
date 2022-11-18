#include<bits/stdc++.h>
using namespace std;

 void lru_replace(int f_size,int n,int pages[])
{
    unordered_set<int> s;
    unordered_map<int, int> indexes;
 
    int page_faults = 0;
    for (int i=0; i<n; i++)
    {
 
        if(s.find(pages[i])!=s.end())
        {
            cout<<"Reference to page "<<pages[i]<<" did not cause a page fault\n";
        }
        else
        {
            if (s.size() < f_size)
            {
                s.insert(pages[i]);
                page_faults++;
            }
            else
            {
                int lru = INT_MAX, val;
                for (auto it : s)
                {
                    if (indexes[it] < lru)
                    {
                        lru = indexes[it];
                        val = it;
                    }
                }
                s.erase(val);
                s.insert(pages[i]);
                page_faults++;
            }
            cout<<"Reference to page "<<pages[i]<<" caused a page fault\n";
 
        }
        indexes[pages[i]] = i;
    }
 
    cout<<"\nTotal Page Faults: "<<page_faults;
}
 
int main()
{   
     int f_size;
     cout<<"Enter the frame size : ";
     cin>>f_size;

     int n;
     cout<<"Enter the number of pages : ";
     cin>>n;

     int pages[n];
     cout<<"Enter the pages:";
    for(int i=0; i<n; i++)
        cin>>pages[i];


lru_replace(f_size,n,pages);
    return 0;
}
