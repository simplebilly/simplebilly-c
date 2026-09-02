#ifndef contact_timeline_response_TEST
#define contact_timeline_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define contact_timeline_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/contact_timeline_response.h"
contact_timeline_response_t* instantiate_contact_timeline_response(int include_optional);



contact_timeline_response_t* instantiate_contact_timeline_response(int include_optional) {
  contact_timeline_response_t* contact_timeline_response = NULL;
  if (include_optional) {
    contact_timeline_response = contact_timeline_response_create(
      "0",
      list_createList()
    );
  } else {
    contact_timeline_response = contact_timeline_response_create(
      "0",
      list_createList()
    );
  }

  return contact_timeline_response;
}


#ifdef contact_timeline_response_MAIN

void test_contact_timeline_response(int include_optional) {
    contact_timeline_response_t* contact_timeline_response_1 = instantiate_contact_timeline_response(include_optional);

	cJSON* jsoncontact_timeline_response_1 = contact_timeline_response_convertToJSON(contact_timeline_response_1);
	printf("contact_timeline_response :\n%s\n", cJSON_Print(jsoncontact_timeline_response_1));
	contact_timeline_response_t* contact_timeline_response_2 = contact_timeline_response_parseFromJSON(jsoncontact_timeline_response_1);
	cJSON* jsoncontact_timeline_response_2 = contact_timeline_response_convertToJSON(contact_timeline_response_2);
	printf("repeating contact_timeline_response:\n%s\n", cJSON_Print(jsoncontact_timeline_response_2));
}

int main() {
  test_contact_timeline_response(1);
  test_contact_timeline_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // contact_timeline_response_MAIN
#endif // contact_timeline_response_TEST
