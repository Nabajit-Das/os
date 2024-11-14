#include<iostream>

#include<unistd.h>

using namespace std;

int main(){

	pid_t pid=fork();

	

	if(pid<0){

		cout<<"Error in getting in child"<<endl;

		return 1;

	}

	else if(pid==0){

		cout<<"Child Process"<<endl;

		cout<<"PID of Child Process: "<<getpid()<<endl;

		cout<<"PID of Parent Process: "<<getppid()<<endl;

	}

	else{

		cout<<"Parent Process"<<endl;

		cout<<"PID of Parent Process: "<<getpid()<<endl;

		cout<<"PID of Parent's Parent Process: "<<getppid()<<endl;

		cout<<"PID of Child Process: "<<pid<<endl;

	}



	return 0;

}