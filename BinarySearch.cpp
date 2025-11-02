#include <stdio.h>
int main()
{
	int A[20],i,n,f=0,l,key,mid,pos,flag=0;
	printf("Enter no. of elements ");
	scanf("%d",&n);
	
	printf("Enter %d elements in sorted order: \n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("Enter value to be searched: ");
	scanf("%d",&key);
	
	l=n-1;
	
	for(i=0;i<n;i++)
	{
		mid = (f+l)/2;
		if (A[mid]==key)
		{
			flag = 1;
			pos = mid;
			break;
		}
		else if (A[mid]<key)
		   f = mid+1;
		else if (A[mid]>key)
		   l = mid-1;
	    }
	
	if (flag==1)
	   printf("Element found at %d",pos);
	else 
	   printf("Element not found. ");
}
