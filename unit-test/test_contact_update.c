#ifndef contact_update_TEST
#define contact_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define contact_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/contact_update.h"
contact_update_t* instantiate_contact_update(int include_optional);



contact_update_t* instantiate_contact_update(int include_optional) {
  contact_update_t* contact_update = NULL;
  if (include_optional) {
    contact_update = contact_update_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "a",
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20",
      "0",
      "0",
      null,
      customer,
      ABW,
      "0",
      "0",
      "0",
      "0",
      null,
      "0",
      "0",
      "0",
      "0",
      1,
      "0",
      0,
      "0",
      1,
      "0",
      "0",
      "a",
      "a",
      "0",
      1,
      1,
      1,
      "2013-10-20",
      "2013-10-20",
      "0",
      "0",
      "2013-10-20",
      "0",
      1,
      "2013-10-20T19:20:30+01:00",
      "0",
      "a",
      "0",
      "2013-10-20",
      "0",
      "0",
      "2013-10-20",
      "0",
      1,
      0,
      list_createList(),
      "0",
      "a",
      1,
      "0",
      1,
      FRST,
      null,
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      ABW,
      "0",
      "0",
      56,
      "0",
      "a",
      1,
      "2013-10-20",
      "0",
      "0"
    );
  } else {
    contact_update = contact_update_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "a",
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20",
      "0",
      "0",
      null,
      customer,
      ABW,
      "0",
      "0",
      "0",
      "0",
      null,
      "0",
      "0",
      "0",
      "0",
      1,
      "0",
      0,
      "0",
      1,
      "0",
      "0",
      "a",
      "a",
      "0",
      1,
      1,
      1,
      "2013-10-20",
      "2013-10-20",
      "0",
      "0",
      "2013-10-20",
      "0",
      1,
      "2013-10-20T19:20:30+01:00",
      "0",
      "a",
      "0",
      "2013-10-20",
      "0",
      "0",
      "2013-10-20",
      "0",
      1,
      0,
      list_createList(),
      "0",
      "a",
      1,
      "0",
      1,
      FRST,
      null,
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      ABW,
      "0",
      "0",
      56,
      "0",
      "a",
      1,
      "2013-10-20",
      "0",
      "0"
    );
  }

  return contact_update;
}


#ifdef contact_update_MAIN

void test_contact_update(int include_optional) {
    contact_update_t* contact_update_1 = instantiate_contact_update(include_optional);

	cJSON* jsoncontact_update_1 = contact_update_convertToJSON(contact_update_1);
	printf("contact_update :\n%s\n", cJSON_Print(jsoncontact_update_1));
	contact_update_t* contact_update_2 = contact_update_parseFromJSON(jsoncontact_update_1);
	cJSON* jsoncontact_update_2 = contact_update_convertToJSON(contact_update_2);
	printf("repeating contact_update:\n%s\n", cJSON_Print(jsoncontact_update_2));
}

int main() {
  test_contact_update(1);
  test_contact_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // contact_update_MAIN
#endif // contact_update_TEST
