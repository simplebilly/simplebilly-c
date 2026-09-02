#ifndef api_response_subscription_overview_TEST
#define api_response_subscription_overview_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define api_response_subscription_overview_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/api_response_subscription_overview.h"
api_response_subscription_overview_t* instantiate_api_response_subscription_overview(int include_optional);

#include "test_api_response_subscription_overview_data.c"


api_response_subscription_overview_t* instantiate_api_response_subscription_overview(int include_optional) {
  api_response_subscription_overview_t* api_response_subscription_overview = NULL;
  if (include_optional) {
    api_response_subscription_overview = api_response_subscription_overview_create(
       // false, not to have infinite recursion
      instantiate_api_response_subscription_overview_data(0),
      "0",
      "0",
      1
    );
  } else {
    api_response_subscription_overview = api_response_subscription_overview_create(
      NULL,
      "0",
      "0",
      1
    );
  }

  return api_response_subscription_overview;
}


#ifdef api_response_subscription_overview_MAIN

void test_api_response_subscription_overview(int include_optional) {
    api_response_subscription_overview_t* api_response_subscription_overview_1 = instantiate_api_response_subscription_overview(include_optional);

	cJSON* jsonapi_response_subscription_overview_1 = api_response_subscription_overview_convertToJSON(api_response_subscription_overview_1);
	printf("api_response_subscription_overview :\n%s\n", cJSON_Print(jsonapi_response_subscription_overview_1));
	api_response_subscription_overview_t* api_response_subscription_overview_2 = api_response_subscription_overview_parseFromJSON(jsonapi_response_subscription_overview_1);
	cJSON* jsonapi_response_subscription_overview_2 = api_response_subscription_overview_convertToJSON(api_response_subscription_overview_2);
	printf("repeating api_response_subscription_overview:\n%s\n", cJSON_Print(jsonapi_response_subscription_overview_2));
}

int main() {
  test_api_response_subscription_overview(1);
  test_api_response_subscription_overview(0);

  printf("Hello world \n");
  return 0;
}

#endif // api_response_subscription_overview_MAIN
#endif // api_response_subscription_overview_TEST
