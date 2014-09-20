// strqueue.h: an ADT for storing a Queue of Strings

struct strqueue;
typedef struct strqueue *StrQueue;

// create_StrQueue(): creates a new StrQueue
//   PRE:  true
//   POST: caller must call destroy_StrQueue
//   TIME: O(1)
StrQueue create_StrQueue(void);


// destroy_StrQueue(sq): frees the memory occupied by sq
//     and frees every string still in the queue
//   PRE:  sq is a valid StrQueue (not NULL)
//   POST: sq is no longer valid
//   TIME: O(n), where n is sq_length(sq)
void destroy_StrQueue(StrQueue sq);


// sq_add_back(sq, str): makes a copy of str and places it at the
//     end of the queue
//   PRE:  sq is a valid StrQueue (not NULL)
//         str is not NULL.
//   POST: sq length increased by 1
//         a copy of str is now at the end of sq
//   TIME: O(n), where n is strlen(str)
void sq_add_back(StrQueue sq, const char *str);


// sq_remove_front(sq): returns the string that was first in the queue 
//     or NULL if empty
//   PRE:  sq is a valid StrQueue (not NULL)
//   POST: if sq is empty, returns NULL 
//         otherwise, returns the first string (caller must free)
//         and sq length decreased by 1
//   TIME: O(1)
char *sq_remove_front(StrQueue sq);


// sq_length(sq) returns the number of items in the queue.
//   PRE:  sq is a valid StrQueue (not NULL)
//   POST: returns int >= 0
//   TIME: O(1)
int sq_length(StrQueue sq);
