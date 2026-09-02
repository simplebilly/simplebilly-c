#ifndef contact_create_TEST
#define contact_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define contact_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/contact_create.h"
contact_create_t* instantiate_contact_create(int include_optional);



contact_create_t* instantiate_contact_create(int include_optional) {
  contact_create_t* contact_create = NULL;
  if (include_optional) {
    contact_create = contact_create_create(
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
      simplebilly_api_contact_create__customer,
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
    contact_create = contact_create_create(
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
      simplebilly_api_contact_create__customer,
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

  return contact_create;
}


#ifdef contact_create_MAIN

void test_contact_create(int include_optional) {
    contact_create_t* contact_create_1 = instantiate_contact_create(include_optional);

	cJSON* jsoncontact_create_1 = contact_create_convertToJSON(contact_create_1);
	printf("contact_create :\n%s\n", cJSON_Print(jsoncontact_create_1));
	contact_create_t* contact_create_2 = contact_create_parseFromJSON(jsoncontact_create_1);
	cJSON* jsoncontact_create_2 = contact_create_convertToJSON(contact_create_2);
	printf("repeating contact_create:\n%s\n", cJSON_Print(jsoncontact_create_2));
}

int main() {
  test_contact_create(1);
  test_contact_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // contact_create_MAIN
#endif // contact_create_TEST
