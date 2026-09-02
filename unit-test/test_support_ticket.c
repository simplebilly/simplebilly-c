#ifndef support_ticket_TEST
#define support_ticket_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define support_ticket_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/support_ticket.h"
support_ticket_t* instantiate_support_ticket(int include_optional);



support_ticket_t* instantiate_support_ticket(int include_optional) {
  support_ticket_t* support_ticket = NULL;
  if (include_optional) {
    support_ticket = support_ticket_create(
      "0",
      "0",
      email,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      56,
      "0",
      simplebilly_api_support_ticket__normal,
      "0",
      simplebilly_api_support_ticket__open,
      "0",
      null,
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    support_ticket = support_ticket_create(
      "0",
      "0",
      email,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      56,
      "0",
      simplebilly_api_support_ticket__normal,
      "0",
      simplebilly_api_support_ticket__open,
      "0",
      null,
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return support_ticket;
}


#ifdef support_ticket_MAIN

void test_support_ticket(int include_optional) {
    support_ticket_t* support_ticket_1 = instantiate_support_ticket(include_optional);

	cJSON* jsonsupport_ticket_1 = support_ticket_convertToJSON(support_ticket_1);
	printf("support_ticket :\n%s\n", cJSON_Print(jsonsupport_ticket_1));
	support_ticket_t* support_ticket_2 = support_ticket_parseFromJSON(jsonsupport_ticket_1);
	cJSON* jsonsupport_ticket_2 = support_ticket_convertToJSON(support_ticket_2);
	printf("repeating support_ticket:\n%s\n", cJSON_Print(jsonsupport_ticket_2));
}

int main() {
  test_support_ticket(1);
  test_support_ticket(0);

  printf("Hello world \n");
  return 0;
}

#endif // support_ticket_MAIN
#endif // support_ticket_TEST
