#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>parsed_values;
int  min( short int a,short int b)
{
	return a>b?b:a;
}
class jug{
	public:
	short int capacity=0;
	short int value=0;
	bool isFull(){
		if(this->capacity==this->value)
		return true;
		else
		return false;
	}
	bool isEmpty()
	{
		if(this->value==0)
		return true;
		else
		return	false;	
	}
	
};
void show(int a,int b)
{
	cout<<"A= "<<a<<"  B= "<<b<<endl<<endl;
}
bool check_repeat(int a,int b)
{
	short int size=parsed_values.size();
	for(short i=0;i<size;i++){
		if(parsed_values[i].first==a&&parsed_values[i].second==b)return true;
	}
	return false;
	
}
int main()
{	parsed_values.push_back(make_pair(0,0));
    short int goalA,goalB;
	jug A,B;
	cout<<"Enter the capacity of the  jugA"<<endl;
	cin>>A.capacity;
	cout<<"Enter the capacity of the  jugB"<<endl;
	cin>>B.capacity;
	cout<<"-----------------------------------"<<endl<<"Enter the goal state of  jugA"<<endl;
	cin>>goalA;
	cout<<"Enter the goal state of the jugB"<<endl;cin>>goalB;cout<<"\n\n";
	cout<<"-----------------------------"<<endl<<endl;
	cout<<"Start State of jugs A=0  B=0\n\n"<<endl;
	if(goalA==0&&goalB==0){cout<<"! Done !";return 0;
	}
	try{
	while((A.value!=goalA || B.value!=goalB))
	{
		if(A.isEmpty())
		{
			A.value=A.capacity;
			cout<<"FIll  ";show(A.value,B.value);
		}
		else if(B.isFull())
		{  B.value=0;
			cout<<"Empty ";show(A.value,B.value);
		}
		else{
			short temp;
			temp=min(B.capacity-B.value,A.value);
			B.value=B.value+temp;
			A.value=A.value-temp;
			cout<<"Pour  ";show(A.value,B.value);
		}
		if(check_repeat(A.value,B.value))
		throw(0);
		parsed_values.push_back(make_pair(A.value,B.value));
		
}
}
catch(int i)
{
	cout<<"! Not Possible !";
	return 0;
}
cout<<"[+]]Executed succsefully[+]";
	return 0;
}
