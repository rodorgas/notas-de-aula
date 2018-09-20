#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int* v;
	int sz;
	int end;
	int begin;
}	queue;

queue* new_queue(int sz){
	queue* f = malloc(sz*sizeof(queue));
	f->begin=0;
	f->end=0;
	f->sz=sz;
	f->v=malloc(sz*sizeof(int));
	return f;
}

void push(queue* f, int x){
	if( (f->end+1)%(f->sz) == f->begin){
		int *aux = malloc(2*f->sz*sizeof(int));
		for(int i=0;i<f->sz;i++)
			aux[i]=f->v[i];
		free(f->v);
		f->v=aux;
		f->sz*=2;
	}
	f->v[f->end]=x;
	f->end=(f->end+1)%f->sz;
}

int is_empty(queue* f){
	return (f->begin==f->end);
}

void pop(queue* f){
	if(is_empty(f))
		return;
	f->begin=(f->begin+1)%f->sz;
}

int top(queue* f){
	return (f->v[f->begin]);
}


int main(){

}

