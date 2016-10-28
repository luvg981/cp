#include <iostream>
using namespace std;

int main(){
	int t;
	long long int total;
	long long int a,b,c,d;
	cin>>t;
	for(int i=0;i<t;i++){
		total=0;
		cin>>a>>b>>c>>d;
		for(long long int j=a;j<=b;j++){
			if(j>=d)
				break;
			else if(c>j)
				total+=d-(c-1);
			else
				total+=d-j;
		}
		cout<<total<<"\n";
	}
}