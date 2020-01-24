#include<iostream>
#include<algorithm>
using namespace std;
bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{
	int midindex;
	sort(array,array+lastIndex);
	while(startIndex<lastIndex)
	{ 
		midindex=(startIndex+lastIndex)/2;
	
		if(array[midindex]>element)
		{
		    lastIndex=midindex-1;
		}	
	    else if(array[midindex]<element)
		{
			 startIndex=midindex+1;
		}
			else if(element==array[midindex])
		{
		    return true; 
		}	
   } 

}
bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{
	int midindex;
	sort(array,array+lastIndex);	
	midindex=(startIndex+lastIndex)/2;
    if(startIndex>lastIndex) 
	return false;
	 if(element==array[midindex])
	   return true;
	else if(array[midindex]>element)
		  binarySearchReacursive(array,startIndex,midindex-1,element);
	else if(array[midindex]<element)
	    binarySearchReacursive(array,midindex+1,lastIndex,element);
		  
}
int main()
{
	int a,n,array[20];
	bool result,result1=0;
	cout<<"enter the size of the array";
	cin>>n;
	cout<<"enter elements of array";
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}
	cout<<"enter the element to be searched";
	cin>>a;
	result=binarySearchIterative(array,0,n-1,a);
	if(result==0)
	{
	 cout<<"not found  by iteration \n";	
	}
	else
	cout<<"found by iteration \n";
	result1=binarySearchReacursive(array,0,n-1,a);
		if(result1==0)
	{
	 cout<<"not found by recursion \n";	
	}
	else
	cout<<"found by recursion";
	return 0;
}
