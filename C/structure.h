#include<stdlib.h>
//link listnode structure
typedef struct node
{
    int val;
    struct node *next;
} node;

//new node funtion 
node* newNode(int val){
    node* head=(node*)malloc(sizeof(node));
    head->val=val;
    head->next=NULL;
    return head;
}



//clear linklist 
void linkist(node** head,int val){
    if(*head==NULL){
        *head=(node*)malloc(sizeof(node));
        (*head)->val=val;
        (*head)->next=NULL;
    }else{
        node* temp=(*head);
        while(temp->next!=NULL) temp=temp->next;
        temp->next=(node*)malloc(sizeof(node));
        temp->next->val=val;
        temp->next->next=NULL;

    }
}


//tree structure

typedef struct tree{
    int  val;
    struct head* left;
    struct head* right;
} tree;

tree* newNodeTree(int val){
    tree* head=(tree*)malloc(sizeof(tree));
    head->val=val;
    head->left=head->right=NULL;
    return head;
}

void binarytree(tree** head,int val){
    if(*head=NULL){
        *head=newNodeTree(val);
    }
    else{
        tree* temp=*head;
        while(temp=NULL){
            if(temp->val>val){
                if(temp->left==NULL){
                    temp->left=newNodeTree(val);
                }else{
                    temp=temp->left;
                }
            }else{
                if(temp->right==NULL){
                    temp->right=newNodeTree(val);
                }else{
                    temp=temp->right;
                }
            }
        }
    }
}


//print binary tree
void printtree(tree*head){
    
}

