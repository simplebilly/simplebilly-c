#ifndef auth_response_TEST
#define auth_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define auth_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/auth_response.h"
auth_response_t* instantiate_auth_response(int include_optional);

#include "test_model.c"


auth_response_t* instantiate_auth_response(int include_optional) {
  auth_response_t* auth_response = NULL;
  if (include_optional) {
    auth_response = auth_response_create(
      "0",
      "0",
      "0",
      1,
       // false, not to have infinite recursion
      instantiate_model(0)
    );
  } else {
    auth_response = auth_response_create(
      "0",
      "0",
      "0",
      1,
      NULL
    );
  }

  return auth_response;
}


#ifdef auth_response_MAIN

void test_auth_response(int include_optional) {
    auth_response_t* auth_response_1 = instantiate_auth_response(include_optional);

	cJSON* jsonauth_response_1 = auth_response_convertToJSON(auth_response_1);
	printf("auth_response :\n%s\n", cJSON_Print(jsonauth_response_1));
	auth_response_t* auth_response_2 = auth_response_parseFromJSON(jsonauth_response_1);
	cJSON* jsonauth_response_2 = auth_response_convertToJSON(auth_response_2);
	printf("repeating auth_response:\n%s\n", cJSON_Print(jsonauth_response_2));
}

int main() {
  test_auth_response(1);
  test_auth_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // auth_response_MAIN
#endif // auth_response_TEST
