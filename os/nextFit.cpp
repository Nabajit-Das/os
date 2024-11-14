#include<bits/stdc++.h>
using namespace std;

void nextFit(int blockSize[],int m,int processSize[],int n){
    int allocation[n];
    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }
    int j=0;
    for(int i=0;i<n;i++){
        int startIdx=j;
        while(j<m){
            if(blockSize[j]>=processSize[i]){
                allocation[i]=j;
                blockSize[j]-=processSize[i];
                break;
            }
            j=(j+1)%m;
            if(j==startIdx) break;
        }
    }
    cout<<"Process No. \t Process Size \t Block no.\n";
    for(int i=0;i<n;i++){
        cout<<" "<<i+1<<"\t\t"<<processSize[i]<<"\t\t";
        if(allocation[i]!=-1) cout<<allocation[i]+1<<endl;
        else cout<<"Not Allocated"<<endl;
    }
}

int main(){
    cout<<"Enter the number of blocks: ";
    int m;
    cin>>m;
    cout<<"Enter the number of processes: ";
    int n;
    cin>>n;
    int blockSize[m],processSize[n];
    cout<<"Enter the block sizes: ";
    for(int i=0;i<m;i++){
        cin>>blockSize[i];
    }
    cout<<"Enter the process sizes: ";
    for(int i=0;i<n;i++){
        cin>>processSize[i];
    }
    nextFit(blockSize,m,processSize,n);

    return 0;
}