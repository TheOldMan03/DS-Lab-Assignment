#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}; 
//structure of a BT

struct Node* root=NULL;

void Insert(int elem){

    struct Node* newNode=malloc(sizeof(struct Node));

    newNode->data=elem;
    newNode->left=NULL;
    newNode->right=NULL;
    //ek lotha node ko kithar place karna hai?

    if (root==NULL){
        root=newNode;
    }

    else{
        struct Node* prev;
        struct Node* curr=root;

        while(1){
            if(elem<curr->data){
                prev=curr;
                curr=curr->left;

                if(curr==NULL){
                    prev->left=newNode;
                    break;
                }
            }

            else{
                prev=curr;
                curr=curr->right;

                if(curr==NULL){
                    prev->right=newNode;
                    break;
                }
            }
        }
    }
}

int Search(int elem_search){
    struct Node* curr=root;

    if(curr==NULL){
        printf("\nThe BT is empty");
    }

    else{
        while(curr!=NULL){
            if(elem_search < curr->data){
                curr=curr->left;
            }

            else if (elem_search > curr->data){
                curr=curr->right;
            }

            else{
                return 1;
                break;
            }
        }

        if (curr==NULL){
            return 0;
        }
    }
}

void PreOrder(struct Node** ptr){ //DLR

    if(*ptr!=NULL){
        printf("%d ",(*ptr)->data);
        PreOrder(&((*ptr)->left));
        PreOrder(&((*ptr)->right));
    }
}

void InOrder(struct Node** ptr){ //LDR
    if (*ptr!=NULL){
        InOrder(&((*ptr)->left));
        printf("%d ",(*ptr)->data);
        InOrder(&((*ptr)->right));
    }
}

void PostOrder(struct Node** ptr){ //LRD

    if(*ptr!=NULL){
        PostOrder(&((*ptr)->left));
        PostOrder(&((*ptr)->right));
        printf("%d ",(*ptr)->data);
    }
}
//the traversals

int Successor(int elem){

    if (root==NULL){
        printf("\nBT is empty");
    }

    else{

        int s;
        struct Node* curr=root;

        while(curr!=NULL){
            
            if(elem<curr->data){
                s=curr->data;
                curr=curr->left;
            }

            else if(elem>=curr->data){
                curr=curr->right;
            }
        }
        return s;
    }

}

void Delete(int del_elem){
    if(root==NULL){
        printf("\nBT is empty");
    }

    else{
        int y=Search(del_elem);

        if(y==0){
            printf("\nThe element %d does not exist! ",del_elem);
        }

        else{
            struct Node* curr=root;
            struct Node* prev;

            while(curr!=NULL){
                if(del_elem<curr->data){
                    prev=curr;
                    curr=curr->left;
                }

                else if (del_elem>curr->data){
                    prev=curr;
                    curr=curr->right;
                }

                else{
                    break;
                }
            }

            if(curr->left==NULL && curr->right==NULL){//leaf Node deletion
                if (prev->right==curr){
                    prev->right=NULL;
                    free(curr);
                    curr=NULL;
                }

                else if (prev->left==curr){
                    prev->left=NULL;
                    free(curr);
                    curr=NULL;
                }
            }

            else if (curr->right==NULL && curr->left!=NULL){ //that is there one child in the left side
                prev->left=curr->left;
                curr->left=NULL;
                free(curr);
                curr=NULL;
            }

            else if (curr->left==NULL && curr->right!=NULL){ //that is there one child in the right side
                prev->right=curr->right;
                curr->left=NULL;
                free(curr);
                curr=NULL;
            }

            else{ //if there are 2 children

                int s=Successor(del_elem);
                Delete(s);
                curr->data=s;
            }

        }
    }
}

int main(){
    int choice;
    int elem;

    do{
        printf("\n1.Insert");
        printf("\n2.Search");
        printf("\n3.PreOrder");
        printf("\n4.InOrder");
        printf("\n5.PostOrder");
        printf("\n6.Delete");
        printf("\n7.Exit");

        printf("\n\nEnter Choice: ");
        scanf("%d",&choice);

        if (choice==1 || choice==2 || choice==6){
            printf("Enter the elem: ");
            scanf("%d",&elem);
        }

        switch(choice){
           
            case 1:
                Insert(elem);
                break;
                
            case 2:
                int y=Search(elem);
                if(y==0){
                    printf("\n%d does not exist! ",elem);
                }

                else{
                    printf("\nElement exists!");
                }
                break;
            

            case 3:
                PreOrder(&root);
                break;
            case 4:
                InOrder(&root);
                break;
            
            case 5:
                PostOrder(&root);
                break;
            
            case 6:
                Delete(elem);
                break;
            
            case 7:
                printf("\n");
                break;
            
            default:
                printf("\nInvalid Choice! ");
        }
    }while(choice!=7);

}