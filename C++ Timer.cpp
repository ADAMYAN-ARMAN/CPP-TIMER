#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;
class Clock {
	int s, m, h;
	int *a, *b;
	public:
		Clock (){
			s=0;
			m=0;
			h=0;
			a=new int;
			b=new int;
		}
		 inline bool forcheckdigit (string a);
		 inline bool forcheckint (int k);
		 inline void clock ();
		 void starttime ();
		 void timer ();
		 
		 ~Clock (){
		 	delete a;
		 	delete b;
		 }
};
int main()
{
	string choice;
	Clock ob;
	
	
	again:
	cout<<"Start time(0) | Timer(1)    ";  getline(cin, choice);
	system("cls");
	
	try {
		if (choice!="0" && choice!="1")
			throw 1;
		
	}
	
	catch (int a){
		cout<<"There are no option for your choice: "<<endl;
		goto again;
	}
	
	
	if (choice=="0")
		ob.starttime();
	
	
	if (choice=="1")
		ob.timer();
	
	
	
	system("cls");
	
	
	return 0;
}



inline bool Clock::forcheckdigit (string a)
{
    if(a.size()==0) return false;
    
    
	for(unsigned int i=0; i<a.size(); i++)
	    if((a[i]>='0' && a[i]<='9')==false)	return false;
	
	    
	return true;
}






inline bool Clock::forcheckint (int k){
	if (k>=0 && k<60) return false;
	
		return true;
}





inline void Clock::clock(){
	
	/*Clock appearance*/
	
	
	//Timer box
	cout<<"\t\t\t\t\t";
	cout <<setfill ('-') <<setw (35)<<" "<<endl;

	
	cout<<"\t\t\t\t"<<"       ";
	cout<<"|"<<"\t\t\t\t"<<"  |"<<endl;
	
	
	cout<<"\t\t\t\t"<<"       ";
	cout<<"|"<<"\t       "<<"Timer"<<"\t\t"<<"  |"<<endl;
	
	
	cout<<"\t\t\t\t"<<"       ";
	cout<<"|"<<"\t\t\t\t"<<"  |"<<endl;
	
	
	cout<<"\t\t\t\t\t";
	cout<<setfill ('-') <<setw (35)<<" "<<endl;
	
	
	
	
	
	
	//Lines for second, minute and hour
	cout<<"\t\t\t\t"<<"       ";
	cout<<"|"<<"   Hour:  ";
	cout<<"|"<<"   Minute: ";
	cout<<"|"<<"  Second:  ";
	cout<<"|"<<endl;
	
	
	cout<<"\t\t\t\t\t";
	cout<<setfill ('-') <<setw (35)<<" "<<endl;
	
	
	
	
	//Lines for timer
	*a=11;
	*b=0;
	
	
	cout<<"\t\t\t\t"<<"       ";
	
	
	//Distance with '|' for hour, minute and second
	cout<<"|"<<setfill (' ') <<setw (--*a)<<h;
	cout<<setfill (' ') <<setw (++*b);
	
	cout<<"|"<<setfill (' ') <<setw (*a+1)<<m;
	cout<<setfill (' ') <<setw (*b);
	
	cout<<"|"<<setfill (' ') <<setw (*a+1)<<s;
	cout<<setfill (' ') <<setw (*b);
	
	
	cout<<"|"<<endl;
	cout<<"\t\t\t\t\t";
	cout<<setfill ('-') <<setw (35)<<" "<<endl;	
}




void Clock::starttime (){
	starttime:
		/*850 ms = 0.850 sec. I write 850ms instead 1000ms (1 second),
		because there are many conditions, functions and cycles in my code.
		Those ones spend a little time.*/
		Sleep (850);
		system ("cls");
		clock();
		++s;
	
	if (s==60){
		s=0;
		++m;
	}
	
	if (m==60){
		s=0;
		m=0;
		++h;
	}
	
	goto starttime;
}





void Clock::timer (){
	
	//ffs, ffm and ffh for check digit or not, then they convert to int
	string ffs, ffm, ffh;
	int fs, fm, fh;
	
	toh:
	cout<<"Hour: "; getline(cin, ffh);
	
	//string ffh to int fh
	if (forcheckdigit(ffh)){
		istringstream line (ffh);
		line>>fh;
	}
	
	else {
		system("cls");
		goto toh;
	}
	
	
	tom:
	system ("cls");
	cout<<"Hour: "<<fh<<endl;
	cout<<"Minute: "; getline(cin, ffm);
	
	
	//string ffm to int fm
	if (forcheckdigit(ffm)){
		istringstream line (ffm);
		line>>fm;
	}
		
	else goto tom;
	
	
	if (forcheckint(fm)) goto tom;
	
	
	
	tos:
	system ("cls");
	cout<<"Hour: "<<fh<<endl;
	cout<<"Minute: "<<fm<<endl;
	cout<<"Second: "; getline(cin, ffs);
	
	
	//string ffs to int fs
	if (forcheckdigit(ffs)){
		istringstream line (ffs);
		line>>fs;
	}
			
	else goto tos;
		
	
	if (forcheckint(fs)) goto tos;		
			
	
	
	
	
	starttime:
		/*863 ms = 0.863 sec. I write 863ms instead 1000ms (1 second),
		because there are many conditions, functions and cycles in my code.
		Those ones spend a little time.*/	
		Sleep (863);
		system ("cls");
		clock();
		++s;

	
	if (s==60){
		s=0;
		++m;
	}
	
	if (m==60){
		s=0;
		m=0;
		++h;
	}
	
	if (s==fs && m==fm && h==fh){
		//523 is hz, 3000 is 3 second
		system ("cls");
		clock();
		Beep(523,3000);
		system("pause");
		exit(1);
	}
	
	goto starttime;	
}

