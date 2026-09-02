#ifndef contact_history_response_TEST
#define contact_history_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define contact_history_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/contact_history_response.h"
contact_history_response_t* instantiate_contact_history_response(int include_optional);



contact_history_response_t* instantiate_contact_history_response(int include_optional) {
  contact_history_response_t* contact_history_response = NULL;
  if (include_optional) {
    contact_history_response = contact_history_response_create(
      "0",
      0,
      list_createList(),
      0
    );
  } else {
    contact_history_response = contact_history_response_create(
      "0",
      0,
      list_createList(),
      0
    );
  }

  return contact_history_response;
}


#ifdef contact_history_response_MAIN

void test_contact_history_response(int include_optional) {
    contact_history_response_t* contact_history_response_1 = instantiate_contact_history_response(include_optional);

	cJSON* jsoncontact_history_response_1 = contact_history_response_convertToJSON(contact_history_response_1);
	printf("contact_history_response :\n%s\n", cJSON_Print(jsoncontact_history_response_1));
	contact_history_response_t* contact_history_response_2 = contact_history_response_parseFromJSON(jsoncontact_history_response_1);
	cJSON* jsoncontact_history_response_2 = contact_history_response_convertToJSON(contact_history_response_2);
	printf("repeating contact_history_response:\n%s\n", cJSON_Print(jsoncontact_history_response_2));
}

int main() {
  test_contact_history_response(1);
  test_contact_history_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // contact_history_response_MAIN
#endif // contact_history_response_TEST
