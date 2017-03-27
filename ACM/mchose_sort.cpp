#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int a[]={56,96,72,45,15,60,38,83,23};
	int i,j,x,l;
	int len = 9;

	for(i = 0;i<len;i++)
	{
		x = a[i];
		l = i;
		for(j = i;j<len;j++)
		{
			if(a[j]<x)
			{
				x = a[j];
				l = j;

			}

		}
		a[l] = a[i];
		a[i] = x;
	}

	for (i = 0;i < len;i++)
		cout<<a[i]<<" ";

	return 0;
}