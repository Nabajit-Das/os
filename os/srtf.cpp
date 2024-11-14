#include<bits/stdc++.h>
using namespace std;

void calculate(vector<int> at,vector<int> bt,vector<int>wt,vector<int>tat,vector<int>start,vector<int>end,int n){
    vector<int> remainingTime=bt;
    int currentTime=0;
    int completed=0;
    int avgTAT=0;
    int avgWT=0;

    while(completed<n){
        int minRemTime=INT_MAX;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(at[i]<=currentTime && remainingTime[i]<minRemTime && remainingTime[i]>0){
                minRemTime=remainingTime[i];
                idx=i;
            }
            else if(at[i]<=currentTime && remainingTime[i]==minRemTime && at[i]<at[idx]){
                idx=i;
            }
        }
        if(idx!=-1){
            if(remainingTime[idx]==bt[idx]) start[idx]=currentTime;
            remainingTime[idx]--;
            currentTime++;
            if(remainingTime[idx]==0){
                end[idx]=currentTime;
                tat[idx]=end[idx]-at[idx];
                wt[idx]=tat[idx]-bt[idx];
                completed++;
            }
        }
        else{
            currentTime++;
        }
    }
    avgWT=accumulate(wt.begin(),wt.end(),0)/n;
    avgTAT=accumulate(tat.begin(),tat.end(),0)/n;
    cout<<"Process no.\tArrival Time\tBurst Time\tStart Time\tEnd Time\tTurnaround Time\tWaiting Time\n";
    for(int i=0;i<n;i++){
        cout<<(i+1)<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<start[i]<<"\t\t"<<end[i]<<"\t\t"<<tat[i]<<"\t\t"<<wt[i]<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    vector<int> at(n),bt(n),wt(n),tat(n),start(n),end(n);
    cout<<"Enter the arrival time and burst time for each process:\n";
    for(int i=0;i<n;i++){
        cin>>at[i]>>bt[i];
    }
    calculate(at,bt,wt,tat,start,end,n);

    return 0;
}