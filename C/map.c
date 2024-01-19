#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

typedef struct map{
    int *m;
    int len;
} map;

map* init_map(){
    //printf("%d",INT_MAX);
    map *M = malloc(sizeof(map));
    M->m = (int*)malloc(sizeof(int));
    M->len=0;
    return M;
}
void insert(map *M,int val){
    if(M->len>=val){
        M->m[val]=val;
    }else{
        M->m = (int*)realloc(M->m,(val+1)*sizeof(int));
        M->m[val]=val;
        M->len=val;
    }
}
bool find(map *M,int val){
    return (M->m[val]==val);
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    map *M=init_map();
     int i=0;
    while(i<(sizeof(arr)/sizeof(arr[0]))){
        printf("%d ",arr[i]);
        i++;
        insert(M,arr[i]);
    }
    if(M->m[100]==100){
        printf("found");
    }
}