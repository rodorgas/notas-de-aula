#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

const int INF = 0x3f3f3f3f;

typedef struct {
	int sz;
	int top;
	int *v;
} stack;

stack* new_stack(int new_sz){
	stack *p = malloc(sizeof(stack));
	p->v = malloc(new_sz*sizeof(int));
	p->sz=new_sz;
	p->top=0;
	return p;
}

void del_stack(stack *p){
	free(p->v);
	free(p);
}

void push(stack *p, int x){
	if(p->top == p->sz){
		p->v = realloc(p->v,2*sizeof(int)*p->sz);
		p->sz*=2;
	}
	p->v[p->top] = x;
	p->top++;
}

int get_top(stack *p){
	if(p->top==0)
		return -INF;
	return p->v[p->top-1];
}

void pop(stack *p){
	if(p->top==0)
		return;
	p->top--;
}

int is_full(stack *p){
	if(p->top==p->sz)
		return 1;
	else
		return 0;
}

int is_empty(stack *p){
	if(p->top==0)
		return 1;
	else
		return 0;
}

int main(){

}
