#include <stdio.h>

void LinearSearch(int a[],int n,int elem){
    int i,flag=0;
    for(i=0;i<n;i++){
        if(a[i]==elem){
            flag=1;
            break;
        }
    }

    if(flag==0){
        printf("\n%d does not exist! ");
    }

    else{
        printf("%d found in position %d",elem,i+1);
    }
}

void BinarySearch(int a[],int n,int elem){//arr should be sorted

    int beg=0,end=n-1,flag=0;
    int mid;

    while(beg<=end){
        mid=(beg+end)/2;

        if(a[mid]==elem){
            flag=1;
            break;
        }

        else if (a[mid]>elem){
            end=mid-1;
        }

        else{
            beg=mid+1;
        }
    }
}