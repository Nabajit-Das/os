#include<bits/stdc++.h>
using namespace std;

void worstFit(int blockSize[],int m,int processSize[],int n){
    vector<int> allocation(n,-1);
    for(int i=0;i<n;i++){
        int worstIdx=-1;
        for(int j=0;j<m;j++){
            if(blockSize[j]>=processSize[i]){
                if(worstIdx==-1){
                    worstIdx=j;
                }
                else if(blockSize[j]>blockSize[worstIdx]){
                    worstIdx=j;
                }
            }
        }
        if(worstIdx!=-1){
            allocation[i]=worstIdx;
            blockSize[worstIdx]-=processSize[i];
        }
    }

    cout<<"Process no.\tProcess Size\tBlock no.\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<"\t\t"<<processSize[i]<<"\t\t";
        if(allocation[i]!=-1) cout<<allocation[i]+1<<endl;
        else cout<<"Not Allocated"<<endl;
    }
}
int main(){
    int m,n;
    cout<<"Enter the number of blocks and processes: ";
    cin>>m>>n;
    int blockSize[m],processSize[n];
    cout<<"Enter the sizes of each block:\n";
    for(int i=0;i<m;i++){
        cin>>blockSize[i];
    }
    cout<<"Enter the sizes of each process:\n";
    for(int i=0;i<n;i++){
        cin>>processSize[i];
    }
    worstFit(blockSize,m,processSize,n);

    return 0;
}