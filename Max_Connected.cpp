#include<iostream>
using namespace std;

int getValue(int arr[][5],int i,int j,int l,int h)
{
	if(i<0 || j>=h || i>=l || j<0)
	{
		return 0;
	}
	else
	{
		return arr[i][j];
	}
}

void getMax(int arr[][5],int i,int j,int l,int h,int size,int &maxSize,int carr[][5])
{
	if(i>=l || j>=h)
	{
		return;
	}
	carr[i][j]=1;
	size++;
	if(maxSize<size)
	{
		maxSize=size;
	}
	int brr[][2]={{1,0},{0,1},{1,1},{1,-1},{-1,1},{-1,-1},{-1,0},{0,-1}};
	for(int p=0;p<8;p++)
	{
		int newi=i+brr[p][0];
		int newj=j+brr[p][1];
		int val=getValue(arr,newi,newj,l,h);
		if(val>0 && carr[newi][newj]==0)
		{
			getMax(arr,newi,newj,l,h,size,maxSize,carr);	
		}
	}	
}

int main()
{
	int maxSize=0;
	int zarr[5][5]={{1,1,0,0,0},{0,1,1,0,1},{0,0,1,0,1},{1,0,1,0,1},{0,0,0,0,1}};
	int carr[5][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(zarr[i][j]==1)
			{
				getMax(zarr,i,j,5,5,0,maxSize,carr);
			}
		}
	}
	cout<<"Max connected points are : "<<maxSize<<endl;
	return 0;
}

