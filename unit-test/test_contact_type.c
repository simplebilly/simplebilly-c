#ifndef contact_type_TEST
#define contact_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define contact_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/contact_type.h"
contact_type_t* instantiate_contact_type(int include_optional);



contact_type_t* instantiate_contact_type(int include_optional) {
  contact_type_t* contact_type = NULL;
  if (include_optional) {
    contact_type = contact_type_create(
    );
  } else {
    contact_type = contact_type_create(
    );
  }

  return contact_type;
}


#ifdef contact_type_MAIN

void test_contact_type(int include_optional) {
    contact_type_t* contact_type_1 = instantiate_contact_type(include_optional);

	cJSON* jsoncontact_type_1 = contact_type_convertToJSON(contact_type_1);
	printf("contact_type :\n%s\n", cJSON_Print(jsoncontact_type_1));
	contact_type_t* contact_type_2 = contact_type_parseFromJSON(jsoncontact_type_1);
	cJSON* jsoncontact_type_2 = contact_type_convertToJSON(contact_type_2);
	printf("repeating contact_type:\n%s\n", cJSON_Print(jsoncontact_type_2));
}

int main() {
  test_contact_type(1);
  test_contact_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // contact_type_MAIN
#endif // contact_type_TEST
