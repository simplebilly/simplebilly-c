#ifndef ticket_priority_TEST
#define ticket_priority_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ticket_priority_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ticket_priority.h"
ticket_priority_t* instantiate_ticket_priority(int include_optional);



ticket_priority_t* instantiate_ticket_priority(int include_optional) {
  ticket_priority_t* ticket_priority = NULL;
  if (include_optional) {
    ticket_priority = ticket_priority_create(
    );
  } else {
    ticket_priority = ticket_priority_create(
    );
  }

  return ticket_priority;
}


#ifdef ticket_priority_MAIN

void test_ticket_priority(int include_optional) {
    ticket_priority_t* ticket_priority_1 = instantiate_ticket_priority(include_optional);

	cJSON* jsonticket_priority_1 = ticket_priority_convertToJSON(ticket_priority_1);
	printf("ticket_priority :\n%s\n", cJSON_Print(jsonticket_priority_1));
	ticket_priority_t* ticket_priority_2 = ticket_priority_parseFromJSON(jsonticket_priority_1);
	cJSON* jsonticket_priority_2 = ticket_priority_convertToJSON(ticket_priority_2);
	printf("repeating ticket_priority:\n%s\n", cJSON_Print(jsonticket_priority_2));
}

int main() {
  test_ticket_priority(1);
  test_ticket_priority(0);

  printf("Hello world \n");
  return 0;
}

#endif // ticket_priority_MAIN
#endif // ticket_priority_TEST
