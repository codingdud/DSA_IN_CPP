#include<stdbool.h>
#include<time.h>
#include<stdlib.h>

time_t t;


void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


//learn sort
int* lsort(int *arr,int len){
    int temp;
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            if(arr[i]>arr[j]){
                swap((arr+i),(arr+j));
            }
        }
    }
}

//display arr
void display_arr(int* arr,int len){
    for(int i=0;i<len;i++){
        printf("%d ",*(arr+i));
    }
    printf("\n");
}


//bubble short
int bubble(int *arr,int len){
    bool var;
    for(int i=0;i<len-1;i++){
        var=false;
        for(int j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr+j,arr+j+1);
                var=true;
            }
        }
        if(!var){
            break;
        }
    }

}

//quick sort
int partion(int *arr,int low,int high){
    int i=low,j=high,piv=arr[low];
    while(i<j){
        while(piv>arr[++i]);
        while(piv<arr[--j]);
        if(i<=j){
            swap(arr+i,arr+j);
        }
    }
    swap(arr+low,arr+j);
    return j;
}

void quick(int *arr,int low,int high){
    if(low<high){
        int mid=partion(arr,low,high);
        quick(arr,low,mid);
        quick(arr,mid+1,high);
    }
}

int rpartion(int *arr,int low,int high){
    int i=low,j=high;
    srand((unsigned) time(&t));
    int mid=(rand()%(high - low)) + low;
    printf("rand:%d\n",mid);
    while(i<j){
        while(arr[mid]>arr[i]) i++;
        while(arr[mid]<arr[j]) j--;
        if(i<=j){
            swap(arr+i,arr+j);
        }
    }
    swap(arr+mid,arr+j);
    return j;
}
void rquick(int *arr,int low,int high){
    if(low<high){
        int mid=rpartion(arr,low,high);
        rquick(arr,low,mid-1);
        rquick(arr,mid+1,high);
    }
}


void isort(int* arr,int len){
    int key,j;
    for(int i=0;i<len;i++){
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}



//heap sort  start
void maxheap(int *arr,int i,int len){
    int left,right,max=i;
    left=i*2+1;
    right=i*2+2;
    if(left<len&&arr[left]>arr[i]) max=left;
    if(right<len&&arr[right]>arr[max]) max=right;
    if(max!=i){
        swap(arr+max,arr+i);
        maxheap(arr,max,len);
    }

}
void buildmaxheap(int *arr,int len){
    for(int i=(len/2);i>=0;i--){
        maxheap(arr,i,len);
    }
}

void hsort(int *arr,int len){
    buildmaxheap(arr,len);
    for(int i=len-1;i>0;i--){
        swap(arr,arr+i);
        maxheap(arr,0,i);
    }
}

//heap sort end
