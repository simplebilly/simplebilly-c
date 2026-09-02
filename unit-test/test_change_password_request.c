#ifndef change_password_request_TEST
#define change_password_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define change_password_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/change_password_request.h"
change_password_request_t* instantiate_change_password_request(int include_optional);



change_password_request_t* instantiate_change_password_request(int include_optional) {
  change_password_request_t* change_password_request = NULL;
  if (include_optional) {
    change_password_request = change_password_request_create(
      "0",
      "0"
    );
  } else {
    change_password_request = change_password_request_create(
      "0",
      "0"
    );
  }

  return change_password_request;
}


#ifdef change_password_request_MAIN

void test_change_password_request(int include_optional) {
    change_password_request_t* change_password_request_1 = instantiate_change_password_request(include_optional);

	cJSON* jsonchange_password_request_1 = change_password_request_convertToJSON(change_password_request_1);
	printf("change_password_request :\n%s\n", cJSON_Print(jsonchange_password_request_1));
	change_password_request_t* change_password_request_2 = change_password_request_parseFromJSON(jsonchange_password_request_1);
	cJSON* jsonchange_password_request_2 = change_password_request_convertToJSON(change_password_request_2);
	printf("repeating change_password_request:\n%s\n", cJSON_Print(jsonchange_password_request_2));
}

int main() {
  test_change_password_request(1);
  test_change_password_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // change_password_request_MAIN
#endif // change_password_request_TEST
