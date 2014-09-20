#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "strqueue.h"

struct llnode{
    char *str;
    struct llnode *next;
};

struct strqueue{
 	int length;
    struct llnode *front;
    struct llnode *back;
};

//see .h file for documentation
StrQueue create_StrQueue(void){
 	struct strqueue *new = malloc(sizeof(struct strqueue));   
    new->front = NULL;
    new->back = NULL;
    new->length = 0;
    return new;
}

//see .h file for documentation
void destroy_StrQueue(StrQueue sq){
 	assert(sq != NULL);
    
	struct llnode *current = sq->front; 
	struct llnode *next;
	while (current != NULL) {
		next = current->next; // note the next pointer
        free(current->str);
		free(current); // delete the node
		current = next; // advance to the next node
	}
	free(sq); 
}

//see .h file for documentation
void sq_add_back(StrQueue sq, const char *str){
    assert(sq != NULL && str != NULL);
        
 	struct llnode *new = malloc(sizeof(struct llnode));
    char *newarr = malloc(sizeof(char) * (strlen(str)+1));
    strcpy(newarr, str);
    new->str = newarr;
    new->next = NULL;
    
    sq->length++;
    if(sq->front == NULL){
    	sq->front = new;
        sq->back = new;
        
    }else{
    	sq->back->next = new; //getting a memory accessing unknown address error
    	sq->back = new;
    }
}

//see .h file for documentation
char *sq_remove_front(StrQueue sq){
 	assert(sq != NULL);
    
    if(sq->front == NULL) return NULL;
    
    char *currstr = sq->front->str;
    struct llnode *prev = sq->front;
    sq->front = sq->front->next;
    free(prev);
    sq->length--;
    return currstr;
}

//see .h file for documentation
int sq_length(StrQueue sq){
    assert(sq != NULL);
    return sq->length;
}

static void print_queue(StrQueue sq) {
	struct llnode *current;
	for (current = sq->front; current != NULL; current = current->next)
		printf("%s\n", current->str);
}