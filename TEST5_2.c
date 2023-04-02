#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef int element ;
typedef struct {
    element data[MAX_SIZE] ;
    int top ;
} StackType ;

//스택 초기화 함수
void init_stack(StackType *sp) {
    sp -> top = -1 ;
}

//empty 함수
int is_empty(StackType *sp) {
    return(sp -> top == -1) ;
}

//full 함수
int is_full(StackType *sp) {
    return(sp -> top == MAX_SIZE - 1) ;
}

//push 함수
void push(StackType *sp, element item) {
    if(is_full(sp)) {
        fprintf(stderr, "Stack Full") ;
    }
    else {
        sp -> data[++(sp -> top)] = item ;
        printf("%d push \n", item) ;
    }
}

//pop 함수
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