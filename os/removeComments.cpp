#include<bits/stdc++.h>
using namespace std;

void removeComments(string inputFile,string outputFile){
    ifstream fin(inputFile);
    ofstream fout(outputFile);
    if(!fin.is_open() || !fout.is_open()){
        cout<<"Error in opening files"<<endl;
        return;
    }
    bool inBlockcomment=false;
    string line;
    while(getline(fin,line)){
        string result;
        int len=line.length();
        for(int i=0;i<len;i++){
            if(inBlockcomment){
                if(i+1<len && line[i]=='*' && line[i+1]=='/'){
                    inBlockcomment=false;
                    i++;
                }
            }
            else{
                if(i+1<len && line[i]=='/' && line[i+1]=='/'){
                    break;
                }
                else if(i+1<len && line[i]=='*' && line[i+1]=='/'){
                    inBlockcomment=true;
                    i++;
                }
                else{
                    result+=line[i];
                }
            }
        }
        if(!result.empty() && !inBlockcomment){
            fout<<result<<endl;
        }
    }
    fin.close();
    fout.close();
    cout<<"Comments removed successfully"<<endl;
}


int main(){
    string inputFile="semaphore.cpp";
    string outputFile="semaphore[1].cpp";
    removeComments(inputFile,outputFile);

    return 0;
}