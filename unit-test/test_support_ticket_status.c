#ifndef support_ticket_status_TEST
#define support_ticket_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define support_ticket_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/support_ticket_status.h"
support_ticket_status_t* instantiate_support_ticket_status(int include_optional);



support_ticket_status_t* instantiate_support_ticket_status(int include_optional) {
  support_ticket_status_t* support_ticket_status = NULL;
  if (include_optional) {
    support_ticket_status = support_ticket_status_create(
    );
  } else {
    support_ticket_status = support_ticket_status_create(
    );
  }

  return support_ticket_status;
}


#ifdef support_ticket_status_MAIN

void test_support_ticket_status(int include_optional) {
    support_ticket_status_t* support_ticket_status_1 = instantiate_support_ticket_status(include_optional);

	cJSON* jsonsupport_ticket_status_1 = support_ticket_status_convertToJSON(support_ticket_status_1);
	printf("support_ticket_status :\n%s\n", cJSON_Print(jsonsupport_ticket_status_1));
	support_ticket_status_t* support_ticket_status_2 = support_ticket_status_parseFromJSON(jsonsupport_ticket_status_1);
	cJSON* jsonsupport_ticket_status_2 = support_ticket_status_convertToJSON(support_ticket_status_2);
	printf("repeating support_ticket_status:\n%s\n", cJSON_Print(jsonsupport_ticket_status_2));
}

int main() {
  test_support_ticket_status(1);
  test_support_ticket_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // support_ticket_status_MAIN
#endif // support_ticket_status_TEST
