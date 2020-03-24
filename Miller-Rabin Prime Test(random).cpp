#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
unsigned long long powmod(unsigned long long a,unsigned long long b,unsigned long long c) //用蒙哥马利算法做大数幂模运算 
{
	unsigned long long result;                                                            //a^b%c 
	int count1,count2;
	int binaryb[100];
	a=a%c;
	for(count1=1;b>0;++count1)
	{
		binaryb[count1-1]=b%2;
		b=b/2;
	}
	unsigned long long mod[count1]={a};
	for(count2=2;count2<=count1;count2++)
		mod[count2-1]=(unsigned long long)pow(mod[count2-2],2)%c;
	for(result=1,count2=1;count2<=count1;count2++)
		if(binaryb[count2-1]==1)
		result=result*mod[count2-1]%c;
	return result;
}
int main()
{
	unsigned long long n,s=0,d,a;                                                        //n-1=2^s*d 1<=a<=n-1 0<=r<=s-1
	int r,judge=0,timesoftest;
	cout<<"Enter a positive number:\n";
	cin>>n;
	cout<<"Is it a prime number?"<<endl;
	if(n==2)
	cout<<"Yes";
	else if(n%2==0)
	cout<<"No"; 
	else
	{
		d=n-1;
		while(d%2==0)
		{
			s+=1;
		    d=d/2;
		}
		srand(time(NULL));
		for(timesoftest=1;timesoftest<=5;timesoftest++)
		{
			a=rand()%(n-1);
			if(a==0||a==1)
			a=2;
			if(powmod(a,d,n)==1)
			{
				judge=1;
				continue;
			}
			for(r=s-1;r>=0;r--)
			{
				if(powmod(a,d*(unsigned long long)pow(2,r),n)==n-1)
				{
					judge=1;
				}
			}
		}
		if(judge==0)
		cout<<"No";
		else
		cout<<"Yes";
	}
}
