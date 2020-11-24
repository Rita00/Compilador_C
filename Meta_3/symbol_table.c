#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include "symbol_table.h"


//Insere um novo identificador na cauda de uma lista ligada de simbolo
table_element *insert_el(table_element * target, char *str, char* t, int nparam, char** tparam)
{
	table_element *newSymbol=(table_element*) malloc(sizeof(table_element));
	table_element *aux;
	table_element* previous;

	strcpy(newSymbol->name, str);
	strcpy(newSymbol->type,t);
	newSymbol->nparam=nparam;
	newSymbol->tparam=tparam;
	newSymbol->next=NULL;	

	if(target)	//Se table ja tem elementos
	{	//Procura cauda da lista e verifica se simbolo ja existe (NOTA: assume-se uma tabela de simbolos globais!)
		for(aux=target; aux; previous=aux, aux=aux->next)
			if(strcmp(aux->name, str)==0)
				return NULL;
		
		previous->next=newSymbol;	//adiciona ao final da lista
	}
	else	//symtab tem um elemento -> o novo simbolo
		target=newSymbol;		
	
	return newSymbol; 
}

void print_global_table(table_element *target)
{
table_element *aux;
for(aux=target; aux; aux=aux->next){
	if(aux->nparam==0){
		printf("%s\t%s\n", aux->name, aux->type);
	}
	else{
		char params[32*aux->nparam]; 
		strcpy(params,aux->tparam[0]);
		for(int i = 1; i< aux->nparam;i++){
			sprintf(params,"%s,%s",params,aux->tparam[i]);
		}
		printf("%s\t%s\t(%s)\n", aux->name, aux->type, params);
	}
}
}

//Procura um identificador, devolve 0 caso nao exista
table_element *search_el(table_element *target,char *str)
{
table_element *aux;

for(aux=target; aux; aux=aux->next)
	if(strcmp(aux->name, str)==0)
		return aux;

return NULL;
}

table_element *create_global_table(AST_Node root){
	table_element *table = calloc(1, sizeof(struct _t1));
	for (int i = 0; i < root->n_children; i++) {
        	if(strcmp(root->children[i]->token,"FuncDefinition")==0){
        		char *aux = root->children[i]->children[1]->token;
        		char *id = (char*)calloc(1,sizeof(aux)-4*sizeof(char));
        		strncpy(id,aux+3,strlen(aux)-4);
				if(root->children[i]->n_children>2){
					char *params[root->children[i]->children[2]->n_children];
					for(int j = 0; j< root->children[i]->children[2]->n_children; j++){
						strcpy(params[j],root->children[i]->children[2]->children[j]->children[0]->token);
					}
					printf("cona");
					insert_el(table, id, root->children[i]->children[0]->token,root->children[i]->children[2]->n_children, params);
				}
				else{insert_el(table, id, root->children[i]->children[0]->token,0,NULL);}				
        	}
			else if(strcmp(root->children[i]->token,"Declaration")==0){
				char *aux = root->children[i]->children[1]->token;
        		char *id = (char*)calloc(1,sizeof(aux)-4*sizeof(char));
        		strncpy(id,aux+3,strlen(aux)-4);
				char *params[1];
				insert_el(table, id, root->children[i]->children[0]->token,0,NULL);
			}
  	}
	return table;
}
void free_table(table_element* root) {
    free(root);
}



