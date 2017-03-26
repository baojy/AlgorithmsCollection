#include<iostream>

using namespace std;

void quick_sort(int a[],int low,int high)
{
    int qu,i,j;
    if(low<high)
    {
        qu = a[low];
        i = low;
        j = high;
        //cout<<"here";
        while(i<j)
        {
            while(i<j && a[j]>=qu)
                j--;
            if(i<j)
                a[i++] = a[j];
            while(i<j && a[i]<=qu)
                i++;
            if(i<j)
                a[j--] = a[i];

        }
        a[i] = qu;
        quick_sort(a,low,i-1);
        quick_sort(a,i+1,high);
    }
}

int main(int argc, char* argv[])
{
	int a[] = {56,96,72,45,15,60,38,83,23};
	quick_sort(a,0,8);
	for(int i =0;i<8;i++)
		cout<<a[i]<<" ";	
	return 0;
}
