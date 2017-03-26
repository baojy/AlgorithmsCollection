#include<iostream>

using namespace std;

int main(int argc,char* argv[])
{
	int i,j,tmp;
	int a[] = {56,96,72,45,15,60,38,83,23};
	for (i =1;i<8;i++)
	{
		tmp = a[i];
		for (j = i-1;j>=0 && tmp<a[j];--j)
		{
			a[j+1] = a[j];
		}
		a[j+1] = tmp;

	}


	for(i=0;i<8;++i)
		cout<<a[i]<<" ";
	return 0;
}