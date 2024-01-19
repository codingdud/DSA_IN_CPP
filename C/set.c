#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct set{
    int *memeber;
    int len;
}set;

set* init();
bool is_empty(set *s);
void insert(set* s,int val);
void printSet(set* s);
set* set_union(set *A,set *B);
set* set_intersection(set* A,set* B);
set* set_difrence(set* A,set* B);
bool is_subset(set* A,set* B);


int main(){
    set * n_set=init();
    if(is_empty(n_set)){
        printf("empty !\n");
    }
    int size;
    printf("enter a size of set 1:");
    scanf("%d",&size);
    int num;
    for(int i =0 ;i < size ;i++){
        printf("Enter number %d : ",i+1);
        scanf("%d",&num);
        insert(n_set,num);
    }
    set* m_set=init();
    printf("enter a size of set 2:");
    scanf("%d",&size);
    for(int i =0 ;i < size ;i++){
        printf("Enter number %d : ",i+1);
        scanf("%d",&num);
        insert(m_set,num);
    }
    printf("n_set:");
    printSet(n_set);
    printf("m_set:");
    printSet(m_set);
    set* c=set_union(n_set,m_set);
    printSet(c);
    set* x=set_intersection(n_set,m_set);
    printSet(x);
    set* z=set_difrence(n_set,m_set);
    printSet(z);
    set* q=set_difrence(m_set,n_set);
    printSet(q);
    printf("%d \n",is_subset(n_set,m_set));
}

set* init(){
    set *s = (set*)malloc(sizeof(set));
    s->len=0;
    s->memeber=(int*)malloc(sizeof(int));
    return s;
}

bool is_empty(set *s){
    return (s->len==0);
}

void insert(set* s,int val){
    bool is_present=false;
    for(int i=0;i<s->len;i++){
        if(val == s->memeber[i]) is_present=true;
    }
    if(!is_present) {
        s->memeber = (int*)realloc(s->memeber,(s->len+1)*sizeof(int));
        s->memeber[s->len]=val;
        s->len=s->len+1;
    }
}

void printSet(set* s){
    printf("{");
    for(int i=0;i<s->len;i++){
        if(i==s->len-1)printf("%d",s->memeber[i]);
        else printf("%d,",s->memeber[i]);
    }
    printf("}\n");
}
set* set_union(set *A,set *B){
    set* c=init();
    for(int i=0;i<A->len;i++){
        insert(c,A->memeber[i]);
    }
    for(int i=0;i<B->len;i++){
        insert(c,B->memeber[i]);
    }
    return c;
}
set* set_intersection(set* A,set* B){
    set* c=init();
    for(int i=0;i<A->len;i++){
        for(int j=0;j<B->len;j++){
            if(A->memeber[i]==B->memeber[j]){
                insert(c,A->memeber[i]);
            }
        }
    }
    return c;
}
set* set_difrence(set* A,set* B){
    set* c=init();
    bool is_present=false;
    for(int i=0;i<A->len;i++){
        is_present=false;
        for(int j=0;j<B->len;j++){
            if(A->memeber[i]==B->memeber[j]){
                is_present=true;
                break;
            }
        }
        if(!is_present)insert(c,A->memeber[i]);
    }
    return c;
}

bool is_subset(set* A,set* B){
    //A is subset of B
    bool issubset=true;
    for(int i=0;i<A->len;i++){
        issubset=false;
        for(int j=0;j<B->len;j++){
            if(A->memeber[i]==B->memeber[j]){
                issubset=true;
            }
        }
        if(!issubset)return issubset;
    }
    return issubset;
}