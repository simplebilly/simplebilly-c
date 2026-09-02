#ifndef contact_TEST
#define contact_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define contact_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/contact.h"
contact_t* instantiate_contact(int include_optional);



contact_t* instantiate_contact(int include_optional) {
  contact_t* contact = NULL;
  if (include_optional) {
    contact = contact_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      null,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      "0",
      56,
      "0",
      1,
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      1,
      1,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      56,
      list_createList(),
      "0",
      "0",
      56,
      "0",
      null,
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      "0",
      "0",
      56,
      "0",
      "0",
      "0",
      1,
      "0",
      "0",
      "0"
    );
  } else {
    contact = contact_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      null,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      "0",
      56,
      "0",
      1,
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      1,
      1,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      1,
      56,
      list_createList(),
      "0",
      "0",
      56,
      "0",
      null,
      "0",
      "0",
      "0",
      "0",
      "0",
      list_createList(),
      "0",
      "0",
      "0",
      56,
      "0",
      "0",
      "0",
      1,
      "0",
      "0",
      "0"
    );
  }

  return contact;
}


#ifdef contact_MAIN

void test_contact(int include_optional) {
    contact_t* contact_1 = instantiate_contact(include_optional);

	cJSON* jsoncontact_1 = contact_convertToJSON(contact_1);
	printf("contact :\n%s\n", cJSON_Print(jsoncontact_1));
	contact_t* contact_2 = contact_parseFromJSON(jsoncontact_1);
	cJSON* jsoncontact_2 = contact_convertToJSON(contact_2);
	printf("repeating contact:\n%s\n", cJSON_Print(jsoncontact_2));
}

int main() {
  test_contact(1);
  test_contact(0);

  printf("Hello world \n");
  return 0;
}

#endif // contact_MAIN
#endif // contact_TEST
