#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX_NAME 256
#define MAX_TABLE 10

//array with hash funtions
typedef struct persion
{
    char name[MAX_NAME];
    int age;
} persion;

persion* hash_table[MAX_TABLE];

void init_hash_table(){
    for(int i=0;i<MAX_TABLE;i++){
        hash_table[i] = NULL;
    }
}

unsigned int hash(char *name){
    int len=strnlen(name,MAX_NAME);
    unsigned int hash_val=0;
    for(int i=0;i<len;i++){
        hash_val+=name[i];
        //hash_val=(hash_val*name[i])%MAX_TABLE;
    }
    return hash_val%MAX_TABLE;
}

void print_table(){
    printf("Hash table:\n");
    for(int i=0;i<MAX_TABLE;i++) {
        if (hash_table[i] != NULL) {
            printf("\t%d\t%s\n", i, hash_table[i]->name); 
        }else{
            printf("\t%d\t---\n",i);
        }
    }

}
bool hash_table_insert(persion *p){
    if(p==NULL) return false;
    int index=hash(p->name);
    if(hash_table[index]!=NULL){
        return false;
    }
    hash_table[index]=p;
    return true;
}
persion* lookup_table(char *name){
    int index=hash(name);
    if(hash_table[index]!=NULL){
        int result=strcmp(hash_table[index]->name,name);
        if(!result)return hash_table[index];

    }
    return NULL;
}
int main(){
    init_hash_table();
    print_table();
    persion person1={.name="Tom",.age=25};
    persion darkhornat={.name="darkhornat",.age=24};
    persion akanoob={.name="akanoob",.age=22};
    persion Animesh={.name="Animesh",.age=24};
    hash_table_insert(&person1);
    hash_table_insert(&darkhornat);
    hash_table_insert(&akanoob);
    hash_table_insert(&Animesh);

    print_table();
    persion *ob=lookup_table("Tom");
    if(ob==NULL)printf("Not Found!\n");
    else printf("%s is %d years old.\n",ob->name,ob->age);

    //using hash value
    printf("Animesh =%u\n",hash("Animesh"));
    printf("Akanoob =%u\n",hash("Akanoob"));
    printf("Darkhornat =%u\n",hash("Darkhornat"));
    printf("Shdow =%u\n",hash("Shdow"));
    printf("Warior =%u\n",hash("Warior"));
    printf("Dragon =%u\n",hash("Dragon"));
    return 0;
}
