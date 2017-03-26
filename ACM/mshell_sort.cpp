#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int a[]={56,96,72,45,15,60,38,83,23};
	int h,i,j,tmp;
	int len = 9;

	for(h=len/2;h>0;h/=2)
	{
		for (i=h;i<len;i++)
		{
			tmp = a[i];
			for (j=i-h;(j>=0 && tmp<a[j]);j-=h)
			{
				a[j+h] = a[j];
			}
			a[j+h]=tmp;
		}

	}

	for (i=0;i<len;i++)
		cout<<a[i]<<" ";

	return 0;
}