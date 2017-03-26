//bjy
#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int a[]={56,96,72,45,15,60,38,83,23};
	for(int n=0;n<8;n++)
	{
		int change = 0;
		for(int i=8-1;i>=n;i--)
		{
			if(a[i]>a[i+1])
			{
				int tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = tmp;
				change = 1;
			}

		}
		if(change == 0)break;
	}

	for (int i=0;i<8;++i)
		cout<<a[i]<<" ";
	return 0;
}
