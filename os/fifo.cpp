#include<bits/stdc++.h>
using namespace std;

void fifo(vector<int>pg,int pn,int fn){
    vector<int>fr;
    queue<int>fifoQueue;
    vector<int>pageFaultsArray(pn,0);
    vector<int>pageHitsArray(pn,0);
    for(int i=0;i<pn;i++){
        int currentPage=pg[i];
        if(find(fr.begin(),fr.end(),currentPage)==fr.end()){
            pageFaultsArray[i]=1;
            if(fr.size()<fn){
                fr.push_back(currentPage);
                fifoQueue.push(currentPage);
            }
            else{
                int replacedPage=fifoQueue.front();
                fifoQueue.pop();
                for(int j=0;j<fr.size();j++){
                    if(fr[j]==replacedPage) fr[j]=currentPage;
                }
                fifoQueue.push(currentPage);
            }
        }
        else{
            pageHitsArray[i]=1;
        }
        cout<<"Page "<<currentPage<<" is in the frame. Frame Contents: ";
        for(auto ele:fr) cout<<ele<<" ";
        cout<<endl;
    }

    cout<<"\nPage Faults Array: ";
    for(auto ele:pageFaultsArray) cout<<ele<<" ";
    cout<<"\nPage Hits Array: ";
    for(auto ele:pageHitsArray) cout<<ele<<" ";
}


int main(){
    int pn,fn;
    cout<<"Enter the number of pages: ";
    cin>>pn;
    vector<int>pg(pn);
    cout<<"Enter the page numbers:\n";
    for(int i=0;i<pn;i++) cin>>pg[i];
    cout<<"Enter the number of frames: ";
    cin>>fn;
    fifo(pg,pn,fn);

    return 0;
}