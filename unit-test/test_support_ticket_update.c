#ifndef support_ticket_update_TEST
#define support_ticket_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define support_ticket_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/support_ticket_update.h"
support_ticket_update_t* instantiate_support_ticket_update(int include_optional);



support_ticket_update_t* instantiate_support_ticket_update(int include_optional) {
  support_ticket_update_t* support_ticket_update = NULL;
  if (include_optional) {
    support_ticket_update = support_ticket_update_create(
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
      normal,
      "0",
      open,
      "0",
      null,
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    support_ticket_update = support_ticket_update_create(
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
      normal,
      "0",
      open,
      "0",
      null,
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return support_ticket_update;
}


#ifdef support_ticket_update_MAIN

void test_support_ticket_update(int include_optional) {
    support_ticket_update_t* support_ticket_update_1 = instantiate_support_ticket_update(include_optional);

	cJSON* jsonsupport_ticket_update_1 = support_ticket_update_convertToJSON(support_ticket_update_1);
	printf("support_ticket_update :\n%s\n", cJSON_Print(jsonsupport_ticket_update_1));
	support_ticket_update_t* support_ticket_update_2 = support_ticket_update_parseFromJSON(jsonsupport_ticket_update_1);
	cJSON* jsonsupport_ticket_update_2 = support_ticket_update_convertToJSON(support_ticket_update_2);
	printf("repeating support_ticket_update:\n%s\n", cJSON_Print(jsonsupport_ticket_update_2));
}

int main() {
  test_support_ticket_update(1);
  test_support_ticket_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // support_ticket_update_MAIN
#endif // support_ticket_update_TEST
