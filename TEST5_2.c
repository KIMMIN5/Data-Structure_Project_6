#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef int element ;
typedef struct {
    element data[MAX_SIZE] ;
    int top ;
} StackType ;

//���� �ʱ�ȭ �Լ�
void init_stack(StackType *sp) {
    sp -> top = -1 ;
}

//empty �Լ�
int is_empty(StackType *sp) {
    return(sp -> top == -1) ;
}

//full �Լ�
int is_full(StackType *sp) {
    return(sp -> top == MAX_SIZE - 1) ;
}

//push �Լ�
void push(StackType *sp, element item) {
    if(is_full(sp)) {
        fprintf(stderr, "Stack Full") ;
    }
    else {
        sp -> data[++(sp -> top)] = item ;
        printf("%d push \n", item) ;
    }
}

//pop �Լ�
element pop(StackType *sp) {
    if(is_empty(sp)) {
        fprintf(stderr, "Stack Empty") ;
        return -1 ;
    }
    else {
        element r = sp -> data[(sp -> top)--] ;
        printf("%d push \n", r) ;
        return r ;
    }
}

int main() {
    srand(time(NULL)) ;

    StackType s ;

    init_stack(&s) ;

    for(int i=0; i<30; i++) {
        int rand_num = rand() % 100 + 1 ;
        printf("[%d]", i + 1) ;
        if(rand_num % 2 == 0){
            push(&s, rand_num) ;
        }
        else{
            pop(&s) ;
        }
    }
    return 0 ;
}