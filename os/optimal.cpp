#include<bits/stdc++.h>
using namespace std;

int predictIdx(vector<int>fr,vector<int>pg,int currIdx){
    int maxIdx=-1;
    int pageToReplaceIdx=-1;
    for(int i=0;i<fr.size();i++){
        int j;
        for(j=currIdx;j<pg.size();j++){
            if(fr[i]==pg[j]){
                if(j>maxIdx){
                    maxIdx=j;
                    pageToReplaceIdx=i;
                }
                break;
            }
        }
        if(j==pg.size()) return i;
    }


    return pageToReplaceIdx;
}

void optimal(vector<int>pg,int pn,int fn){
    vector<int>fr;
    vector<int>pageFaultsArray(pn,0);
    vector<int>pageHitsArray(pn,0);
    for(int i=0;i<pn;i++){
        int currentPage=pg[i];
        if(find(fr.begin(),fr.end(),currentPage)==fr.end()){
            pageFaultsArray[i]=1;
            if(fr.size()<fn){
                fr.push_back(currentPage);
            }
            else{
                int replacedIdx=predictIdx(fr,pg,i+1);
                fr[replacedIdx]=currentPage;
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
    optimal(pg,pn,fn);

    return 0;
}