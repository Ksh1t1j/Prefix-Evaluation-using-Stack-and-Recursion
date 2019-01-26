#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct ListNode{
    struct NumOp* record;
    struct ListNode* next;
};
struct NumOp{
    char type;
    double num;
    char op;
};
struct ListNode* CreateNode(){
    struct ListNode* n;
    n= (struct ListNode*)malloc(sizeof(struct ListNode));
    return(n);
}
int IsEmpty(struct ListNode* S){
    if(S==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void Push(struct ListNode** S, struct NumOp* key){
    struct ListNode* n;
    n=CreateNode();
    if(n!=NULL){
        n->record =key;
        n->next=*S;
        *S=n;
        // printf("$\n");
    }
}
struct NumOp* Top(struct ListNode* S){
    return S->record;
}
struct NumOp* Pop(struct ListNode** S){
    struct ListNode* r;
    struct NumOp* i;
    i=(*S)->record;
    r=*S;    
    *S=r->next;
    free(r);
    return i;
}
double apply(char op, double a, double b) {
    switch (op) { 
       case '+': return a + b;
       case '-': return a - b;
       case '/': return a / b;
       case '*': return a * b;
       default: return 0;
    }
}
struct NumOp* inputting(char* a,struct NumOp* j){
    if(*a=='+'||*a=='-'||*a=='*'||*a=='/'){
        j->type= 'o';
        j->num=0;
        j->op=*a;
    }
    else{
        char *endstr;
        double b=strtod(a,&endstr);
        j->type='n';
        j->num=b;
        j->op='\0';
    }
    return j;
}
void evaluate(struct NumOp* s, struct ListNode* S){
    if(IsEmpty(S)&& s->type!='o'){
        printf("%lf\n", s->num);
    }
    else{
        if(s->type=='o'){
            Push(&S,s);
            char a[500];
            scanf(" %s",a);
            struct NumOp* j=(struct NumOp*) malloc(sizeof(struct NumOp));
            j=inputting(a,j);
            evaluate(j,S);
        }
        else{
            if(Top(S)->type=='o'){
                Push(&S,s);
                char a[500];
                scanf(" %s",a);
                struct NumOp* j=(struct NumOp*) malloc(sizeof(struct NumOp));
                j=inputting(a,j);
                evaluate(j,S);
            }
            else{
                double b=s->num;
                struct NumOp* a_ch= Pop(&S);
                double a=a_ch->num;
                struct NumOp* operation=Pop(&S);
                char out=operation->op;
                a = apply(out,a,b);
                struct NumOp* j=(struct NumOp*) malloc(sizeof(struct NumOp));
                j->type='n';
                j->num=a;
                j->op='\0';
                evaluate(j,S);
            }
        }
    }
}
int main() {
    char s[500];
    scanf("%s",s);
    struct NumOp* j=(struct NumOp*) malloc(sizeof(struct NumOp));
    j=inputting(s,j);
    struct ListNode* S = NULL;
    evaluate(j,S);    
    return 0;
}
