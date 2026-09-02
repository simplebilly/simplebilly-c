#ifndef totp_setup_response_TEST
#define totp_setup_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define totp_setup_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/totp_setup_response.h"
totp_setup_response_t* instantiate_totp_setup_response(int include_optional);



totp_setup_response_t* instantiate_totp_setup_response(int include_optional) {
  totp_setup_response_t* totp_setup_response = NULL;
  if (include_optional) {
    totp_setup_response = totp_setup_response_create(
      list_createList(),
      "0",
      "0"
    );
  } else {
    totp_setup_response = totp_setup_response_create(
      list_createList(),
      "0",
      "0"
    );
  }

  return totp_setup_response;
}


#ifdef totp_setup_response_MAIN

void test_totp_setup_response(int include_optional) {
    totp_setup_response_t* totp_setup_response_1 = instantiate_totp_setup_response(include_optional);

	cJSON* jsontotp_setup_response_1 = totp_setup_response_convertToJSON(totp_setup_response_1);
	printf("totp_setup_response :\n%s\n", cJSON_Print(jsontotp_setup_response_1));
	totp_setup_response_t* totp_setup_response_2 = totp_setup_response_parseFromJSON(jsontotp_setup_response_1);
	cJSON* jsontotp_setup_response_2 = totp_setup_response_convertToJSON(totp_setup_response_2);
	printf("repeating totp_setup_response:\n%s\n", cJSON_Print(jsontotp_setup_response_2));
}

int main() {
  test_totp_setup_response(1);
  test_totp_setup_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // totp_setup_response_MAIN
#endif // totp_setup_response_TEST
