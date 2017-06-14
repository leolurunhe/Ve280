#include<iostream>
#include<cmath>
#include<string>

using namespace std;

void test1(int tnum);// For test case 1
void test2(int tnum);// For test case 2
void test3(int tnum);// For test case 3
void test4(int tnum);// For test case 4

int main(){
	int choice=0;	//choice number
	int tnum;	//testnumber
	while(choice<=0 || choice>4){
		cout<<"Please enter the test choice: ";
    	cin>>choice;
	}

	if(choice==1||2||3||4){
		cout<<"Please enter the number for test: ";
	    cin>>tnum;
	}
	while(tnum<0||tnum>10000000){
		cout<<"Please enter the number for test: ";
		cin>>tnum;
	}
	if(choice==1)
		test1(tnum);
	if(choice==2)
		test2(tnum);
	if(choice==3)
		test3(tnum);
	if(choice==4)
		test4(tnum);
	cout<<endl;
	return 0;
}

void test1(int tnum){
	int x=0,y=1;
	int temp;
	if(tnum<0)
		cout<<"Fail";
	if(tnum==0)
		cout<<"Pass";
	while(y<tnum){
		temp=x;
		x=y;
		y=temp+y;
	}                // Generate all fibonacci numbers less than tnum
	if(y==tnum)
		cout<<"Pass";
	else
		cout<<"Fail";
}

void test2(int tnum){
	int n=sqrt(tnum);
	int test;
	int m=1;
	double sqrttnum=sqrt(tnum);
	while(n<=sqrttnum){
		if(tnum==0){
			cout<<"Pass";
			break;
		}
		if(n==sqrttnum){
			cout<<"Pass";
			break;
		}
		test=(n*(n+1)*(2*n+1)-(m-1)*m*(2*m-1))/6;// m^2+...+n^2
		if(test==tnum){
			cout<<"Pass";
			break;
		}
		if(test!=tnum && m<n)
				m=m+1;
		if(m==n){
			n=n-1;
			m=1;
		}
		if(n<1){
			cout<<"Fail";
			break;
		}
	}
}

void test3(int tnum){
	int i=0;
	int j=1;
	string testnum=to_string(tnum);
	string result="";
	int length=testnum.length();
	while(i<=length){
		if(length==1)
			break;
		if(j>=tnum)
			break;
		while(result.length()<length)
			result=to_string(j)+result;// use all numbers less than tnum to generate result
		i=result.length();
		if(result==testnum){
			cout<<"Pass";
			break;
		}
		if(i==result.length()){
		j=j+1;
		result="";
		}
	}
	if(result!=testnum)
		cout<<"Fail";
}

void test4(int tnum){
	int i,remainder;
	int a[tnum]={};// a[tnum] instore all tnum's divisors
	int j=0;
	int sum=0;
	if(tnum<=0)
		cout<<"Fail";
	if(tnum>0){
		for(i=1;i<tnum;i++){
			remainder=tnum%i;
			if(remainder==0){
				a[j]=i;
				j=j+1;
			}
		}
		for(i=0;i<tnum;i++)
			sum=a[i]+sum;
		if(sum==tnum)
			cout<<"Pass";
		else
			cout<<"Fail";
	}
}
