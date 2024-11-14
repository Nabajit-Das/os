#include<bits/stdc++.h>
using namespace std;

struct symbolTableEntry{
    string symbol;
    int address;
    bool external;

    symbolTableEntry(){
        symbol="";
        address=0;
        external=false;
    }
    
    symbolTableEntry(string sym,int addr,bool ext=false){
        symbol=sym;
        address=addr;
        external=ext;
    }
};

struct programSegmentTableEntry{
    string segmentName;
    int baseAddress;
    int size;
    programSegmentTableEntry(string name,int base,int sz){
        segmentName=name;
        baseAddress=base;
        size=sz;
    }
};

struct relocationEntry{
    int offset;
    string symbol;
    bool absolute;
    relocationEntry(int off,string sym,bool t){
        offset=off;
        symbol=sym;
        absolute=t;
    }
};

class Loader{
private:
    map<string,symbolTableEntry> SymbolTable;
    vector<programSegmentTableEntry> ProgramSegmentTable;
    vector<relocationEntry> RelocationTable;
    int memoryStartAddress;

public:
    Loader(int startAddress) {
        memoryStartAddress=startAddress;
    }

    void addSymbol(string symbol,int address,bool external=false){
        SymbolTable[symbol]=symbolTableEntry(symbol,address,external);
    }

    void addSegment(string segment,int baseAddress,int size){
        ProgramSegmentTable.push_back(programSegmentTableEntry(segment,baseAddress,size));
    }

    void addRelocation(int offset,string symbol,bool absolute){
        RelocationTable.push_back(relocationEntry(offset,symbol,absolute));
    }

    void displaySymbolTable(){
        cout<<"Symbol Table \n";
        for(auto ele:SymbolTable){
            cout<<ele.second.symbol<<"\t"<<ele.second.address<<"\t"<<(ele.second.external?"Yes":"No")<<"\n";
        }
    }

    void displayProgramSegmentTable(){
        cout<<"Progam Segment Table \n";
        for(auto ele:ProgramSegmentTable){
            cout<<ele.segmentName<<"\t"<<ele.baseAddress<<"\t"<<ele.size<<"\n";
        }
    }

    void displayRelocationTable(){
        cout<<"Relocation Table \n";
        for(auto ele:RelocationTable){
            cout<<ele.offset<<"\t"<<ele.symbol<<"\t"<<(ele.absolute? "absolute":"relative")<<"\n";
        }
    }

    void loadProgram(){
        cout<<"Loading the program with relocation \n";
        for(auto relocation:RelocationTable){
            auto symbol=SymbolTable.find(relocation.symbol);
            if(symbol!=SymbolTable.end()){
                int newAddress;
                (relocation.absolute)? newAddress=memoryStartAddress+relocation.offset:newAddress=symbol->second.address+relocation.offset;
                symbol->second.address=newAddress;
                cout<<"Relocated "<<relocation.symbol<<" to "<<newAddress<<"\n";
            }
            else{
                cout<<"Symbol not found in Symbol Table\n";
            }
        }
    }
};


int main(){
    Loader loader(1000);
    loader.addSymbol("A",1000);
    loader.addSymbol("B",2000);
    loader.addSegment("Text",1000,100);
    loader.addSegment("Data",2000,100);
    loader.addRelocation(10,"A",false);
    loader.addRelocation(20,"B",true);
    loader.displaySymbolTable();
    loader.displayProgramSegmentTable();
    loader.displayRelocationTable();
    loader.loadProgram();
    loader.displaySymbolTable();
    loader.displayProgramSegmentTable();

    return 0;
}