#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

const int INF = 0x3f3f3f3f;

typedef struct {
	int sz;
	int top;
	char *v;
} stack;

stack* new_stack(int new_sz){
	stack *p = malloc(sizeof(stack));
	p->v = malloc(new_sz*sizeof(char));
	p->sz=new_sz;
	p->top=0;
	return p;
}

void del_stack(stack *p){
	free(p->v);
	free(p);
}

void push(stack *p, char x){
	if(p->top == p->sz){
		p->v = realloc(p->v,2*sizeof(char)*p->sz);
		p->sz*=2;
	}
	p->v[p->top] = x;
	p->top++;
}

char get_top(stack *p){
	if(p->top==0)
		return -INF;
	return p->v[p->top-1];
}

void pop(stack *p){
	if(p->top==0)
		return;
	p->top--;
}

int is_empty(stack *p){
	return (p->top==0);
}

int operador(char x){
	return (x=='+' || x=='-' || x=='*' || x=='/' || x=='^');
}

int prec(char x){

	switch(x){
		case '(' : return 0;
		case '+' :
		case '-' : return 1;
		case '*' :
		case '/' : return 2;
		case '^' : return 4;	
		default : return -1;
	}

}

void postfix( char expr[] ){

	stack *p = new_stack(200);
	int i;
	char c;

	for(i=0;expr[i]!='\0';i++){	//processa a string inteira
		
		if(expr[i]=='(')		//lida com abertura de parenteses
			push(p,'(');

		else if(expr[i]==')'){	//se fechou parenteses, coloco as operacoes
			
			c = get_top(p);

			while(c!='(' && !is_empty(p)){
				printf("%c",c);
				pop(p);
				c=get_top(p);
			}
			pop(p);
		}

		else if( operador(expr[i]) ){	//se le operador, precisa decidir se empilha

			if(is_empty(p))			//empilho se nao tem nada ainda
				push(p,expr[i]);

			else{
				c=get_top(p);	
				//assim que encontro um operador de menor prioridade do que os do stack, saio imprimindo e desempilhando
				while( prec(c) >= prec(expr[i]) && !is_empty(p) ){
					printf("%c",c);
					pop(p);
					if(!is_empty(p))
						c=get_top(p);
				}
				//assim que nada no stack tem prioridade maior ou igual ao que encontrei na string, posso empilhar
				push(p,expr[i]);
			}

		}

		else
			printf("%c",expr[i]);

	}

	while(!is_empty(p)){
		printf("%c",get_top(p));
		pop(p);
	}

	printf("\n");

}

int main(){

	int t; scanf("%d",&t);
	while(t--){
		char expr[200];
		scanf("%s",expr);
		postfix(expr);
	}
}