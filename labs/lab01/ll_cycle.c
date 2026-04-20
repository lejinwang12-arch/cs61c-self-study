#include <stddef.h>
#include "ll_cycle.h"
#include <stdio.h>

int ll_has_cycle(node *head) {
    if (!head) return 0;
    node *tortoise, *hare;
    tortoise = head;
    hare = head;
    while(1) {
	    if (!hare->next || !hare->next->next) {
		return 0;
	    }
	    hare = hare->next->next;

	    tortoise = tortoise->next;

	    if (tortoise == hare) {
	    	printf("There is a cycle.\n");
		return 1;
	    }
    }
    return 0;
}
