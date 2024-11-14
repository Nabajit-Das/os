#include<bits/stdc++.h>
 using namespace std;

struct process{
    int arrivalTime,burstTime,priority;
};

bool compare(process a,process b){
    if(a.arrivalTime==b.arrivalTime){
        return a.priority<b.priority;
    }
    return a.arrivalTime<b.arrivalTime;
}

void findWaitingTime(process proc[],int n,int wt[]){
    int service[n];
    service[0]=proc[0].arrivalTime;
    wt[0]=0;
    for(int i=1;i<n;i++){
        service[i]=service[i-1]+proc[i-1].burstTime;
        wt[i]=service[i]-proc[i].arrivalTime;
        if(wt[i]<0) wt[i]=0;
    }
}

void findTurnAroundTime(process proc[],int n,int wt[],int tat[]){
    for(int i=0;i<n;i++){
        tat[i]=proc[i].burstTime+wt[i];
    }
}

void findAvgWaitingTime(process proc[],int n){
    int wt[n], tat[n];
    findWaitingTime(proc,n,wt);
    findTurnAroundTime(proc,n,wt,tat);

    int stime[n],ctime[n];
    
    for(int i=0;i<n;i++){
        stime[i]=proc[i].arrivalTime+wt[i];
        ctime[i]=stime[i]+proc[i].burstTime;
    }

    int avgWaitTime=0,avgTurnAroundTime=0;
    cout<<" Start Time"<<"\t"<<" Completion Time"<<"\t"<<" Wait Time"<<"\t"<<" Turn Around Time \n";
    for(int i=0;i<n;i++){
        avgWaitTime+=wt[i];
        avgTurnAroundTime+=tat[i];
        cout<<"\t"<<stime[i]<<"\t\t"<<ctime[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }
    cout<<"Average wait time: "<<(avgWaitTime/(double)n)<<endl;
    cout<<"Average turn around time: "<<(avgTurnAroundTime/(double)n)<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    process proc[n];

    for(int i=0;i<n;i++){
        cout<<"Enter the arrival time, burst time and priority of process "<<i+1<<": ";
        cin>>proc[i].arrivalTime>>proc[i].burstTime>>proc[i].priority;
    }
    sort(proc,proc+n,compare);

    findAvgWaitingTime(proc,n);
    return 0;
}