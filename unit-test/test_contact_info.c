#ifndef contact_info_TEST
#define contact_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define contact_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/contact_info.h"
contact_info_t* instantiate_contact_info(int include_optional);



contact_info_t* instantiate_contact_info(int include_optional) {
  contact_info_t* contact_info = NULL;
  if (include_optional) {
    contact_info = contact_info_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    contact_info = contact_info_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return contact_info;
}


#ifdef contact_info_MAIN

void test_contact_info(int include_optional) {
    contact_info_t* contact_info_1 = instantiate_contact_info(include_optional);

	cJSON* jsoncontact_info_1 = contact_info_convertToJSON(contact_info_1);
	printf("contact_info :\n%s\n", cJSON_Print(jsoncontact_info_1));
	contact_info_t* contact_info_2 = contact_info_parseFromJSON(jsoncontact_info_1);
	cJSON* jsoncontact_info_2 = contact_info_convertToJSON(contact_info_2);
	printf("repeating contact_info:\n%s\n", cJSON_Print(jsoncontact_info_2));
}

int main() {
  test_contact_info(1);
  test_contact_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // contact_info_MAIN
#endif // contact_info_TEST
