/*C code  that implements the symbol table 
contains insert, modify, search and display functions
from http://forgetcode.com/C/101-Symbol-table
changes made:
 - indentattion
 - 
*/
#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

//variable declaration
int size=0;

//function prototypes
void Insert();
void Display();
void Delete();
int Search(char lab[]);
void Modify();

//Structure definition
struct SymbTab{
    //memebers of SymTab
    //removed label[10], changed to *symbol
    char * symbol;
    int addr;
    struct SymbTab *next;
};  //end SymtTab structure

//two pointers that default to null
struct SymbTab *first,*last;

 
void main(){
    //variable declaration
    int op,y;
    //removed char la[10];
    /*the main function takes in input from user*/
    do{ 
        printf("\n\tSYMBOL TABLE IMPLEMENTATION\n");
        printf("\n\t1.INSERT\n\t2.DISPLAY\n\t3.DELETE\n\t4.SEARCH\n\t5.MODIFY\n\t6.END\n");
        printf("\n\tEnter your option : ");
        scanf("%d",&op);

    /*calls a function in each case */
    switch(op){
        case 1:
            Insert();
            break;
        case 2:
            Display();
            break;
        case 3:
            Delete();
            break;
        /*case 4:
            printf("\n\tEnter the label to be searched : ");
            scanf("%s",la);
            y=Search(la);
            printf("\n\tSearch Result:");

            if(y==1)
                printf("\n\tThe label is present in the symbol table\n");
            else
                printf("\n\tThe label is not present in the symbol table\n");
            break;*/
        case 5:
            Modify();
            break;
        case 6:
            exit(0);
}//end switch
} while(op<6);

}  /* end of main */

/*a function to insert a new element into the symbol table*/
/*pre- condition - contains a label input*/
void Insert(){
    int n;
    char l[10];
    //printf("\n\tEnter the label : ");
    //scanf("%s",l);
    n=Search(l);

    if(n!=1){
        struct SymbTab *p;
        p=malloc(sizeof(struct SymbTab));
        //strcpy(p->label,l);
        printf("\n\tEnter the symbol : ");
        scanf("%s",p->symbol);
        printf("\n\tEnter the address : ");
        scanf("%d",&p->addr);
        p->next=NULL;

        if(size==0){
            first=p;
            last=p;
        }
        else {
            last->next=p;
            last=p;
        }
        size++;
    }
    //printf("\n\tLabel inserted\n");
}//end insert

//function to display all the elements in the symbol table
void Display(){
    int i;
    struct SymbTab *p;
    p=first;
    printf("\n\tSYMBOL\t\tADDRESS\n");

    for(i=0;i<size;i++){
        printf("\t%s\t\t%d\n",p->symbol,p->addr);
        p=p->next;
    }//end for loop
}//end display function

/*function to search for an element in the symbol table*/
int Search(char lab[]){
    int i,flag=0;
    struct SymbTab *p;
    p=first;

    for(i=0;i<size;i++){
        //if(strcmp(p->label,lab)==0)
            flag=1;
            p=p->next;
    }//end for loop

    return flag;
}/*end searcch function*/

/*function to modify a label in the symbol table*/
/*void Modify(){

    char l[10],nl[10];
    int add,choice,i,s;
    struct SymbTab *p;
    p=first;

    printf("\n\tWhat do you want to modify?\n");
    printf("\n\t2.Only the address\n\t3.Both the label and address\n");
    printf("\tEnter your choice : ");
    scanf("%d",&choice);

    switch(choice){
        /*case 1:
            printf("\n\tEnter the old label : ");
            scanf("%s",l);
            s=Search(l);

            if(s==0)
                printf("\n\tLabel not found\n");
            else{
                printf("\n\tEnter the new label : ");
                scanf("%s",nl);

                for(i=0;i<size;i++){
                    if(strcmp(p->label,l)==0)
                        strcpy(p->label,nl);
                        p=p->next;
                }//end inner fo loop
                printf("\n\tAfter Modification:\n");
                Display();
            }
            break;
        case 2:
           // printf("\n\tEnter the label where the address is to be modified : ");
           // scanf("%s",l);
            //s=Search(l);

            //if(s==0)
                //printf("\n\tLabel not found\n");
            //else{
                printf("\n\tEnter the new address : ");
                scanf("%d",&add);

                for(i=0;i<size;i++){
                    //if(strcmp(p->label,l)==0)
                        p->addr=add;
                        p=p->next;
                }//end inner for loop
                printf("\n\tAfter Modification:\n");
                Display();
            //}
            break;
        case 3:
            /*printf("\n\tEnter the old label : ");
            scanf("%s",l);
            s=Search(l);*/
            
           // if(s==0)
            //    printf("\n\tLabel not found\n");
            //else{
                /*printf("\n\tEnter the new label : ");
                scanf("%s",nl);*/
                printf("\n\tEnter the new address : ");
                scanf("%d",&add);

                for(i=0;i<size;i++){
                   // if(strcmp(p->label,l)==0){
                    //    strcpy(p->label,nl);
                        p->addr=add;
                    }
                    p=p->next;
               // }//end for loop

                //printf("\n\tAfter Modification:\n");
                //Display();
            //}
            break;
    }//end switch*/

}/*end modify  function*/

/*a function to delete and element in the symbol table */
void Delete(){
    int a;
    char l[10];
    struct SymbTab *p,*q;
    p=first;
    //printf("\n\tEnter the label to be deleted : ");
    //scanf("%s",l);
    //a=Search(l);

    if(a==0)
        printf("\n\tLabel not found\n");
    else{
        if(strcmp(first->label,l)==0)
            first=first->next;
        else if(strcmp(last->label,l)==0){
            q=p->next;

            while(strcmp(q->label,l)!=0){
                p=p->next;
                q=q->next;
            }
            p->next=NULL;
            last=p;
        }
        else{
            q=p->next;
            while(strcmp(q->label,l)!=0){
                p=p->next;
                q=q->next;
            }
            p->next=q->next;
        }
    size--;
    printf("\n\tAfter Deletion:\n");
    Display();
    }
}//end delete function

