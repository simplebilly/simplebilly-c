#ifndef api_response_user_profile_TEST
#define api_response_user_profile_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define api_response_user_profile_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/api_response_user_profile.h"
api_response_user_profile_t* instantiate_api_response_user_profile(int include_optional);

#include "test_api_response_user_profile_data.c"


api_response_user_profile_t* instantiate_api_response_user_profile(int include_optional) {
  api_response_user_profile_t* api_response_user_profile = NULL;
  if (include_optional) {
    api_response_user_profile = api_response_user_profile_create(
       // false, not to have infinite recursion
      instantiate_api_response_user_profile_data(0),
      "0",
      "0",
      1
    );
  } else {
    api_response_user_profile = api_response_user_profile_create(
      NULL,
      "0",
      "0",
      1
    );
  }

  return api_response_user_profile;
}


#ifdef api_response_user_profile_MAIN

void test_api_response_user_profile(int include_optional) {
    api_response_user_profile_t* api_response_user_profile_1 = instantiate_api_response_user_profile(include_optional);

	cJSON* jsonapi_response_user_profile_1 = api_response_user_profile_convertToJSON(api_response_user_profile_1);
	printf("api_response_user_profile :\n%s\n", cJSON_Print(jsonapi_response_user_profile_1));
	api_response_user_profile_t* api_response_user_profile_2 = api_response_user_profile_parseFromJSON(jsonapi_response_user_profile_1);
	cJSON* jsonapi_response_user_profile_2 = api_response_user_profile_convertToJSON(api_response_user_profile_2);
	printf("repeating api_response_user_profile:\n%s\n", cJSON_Print(jsonapi_response_user_profile_2));
}

int main() {
  test_api_response_user_profile(1);
  test_api_response_user_profile(0);

  printf("Hello world \n");
  return 0;
}

#endif // api_response_user_profile_MAIN
#endif // api_response_user_profile_TEST
