#ifndef api_response_vec_plan_data_inner_TEST
#define api_response_vec_plan_data_inner_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define api_response_vec_plan_data_inner_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/api_response_vec_plan_data_inner.h"
api_response_vec_plan_data_inner_t* instantiate_api_response_vec_plan_data_inner(int include_optional);

#include "test_plan_features.c"
#include "test_plan_limits.c"


api_response_vec_plan_data_inner_t* instantiate_api_response_vec_plan_data_inner(int include_optional) {
  api_response_vec_plan_data_inner_t* api_response_vec_plan_data_inner = NULL;
  if (include_optional) {
    api_response_vec_plan_data_inner = api_response_vec_plan_data_inner_create(
       // false, not to have infinite recursion
      instantiate_plan_features(0),
      "0",
       // false, not to have infinite recursion
      instantiate_plan_limits(0),
      "0",
      1.337
    );
  } else {
    api_response_vec_plan_data_inner = api_response_vec_plan_data_inner_create(
      NULL,
      "0",
      NULL,
      "0",
      1.337
    );
  }

  return api_response_vec_plan_data_inner;
}


#ifdef api_response_vec_plan_data_inner_MAIN

void test_api_response_vec_plan_data_inner(int include_optional) {
    api_response_vec_plan_data_inner_t* api_response_vec_plan_data_inner_1 = instantiate_api_response_vec_plan_data_inner(include_optional);

	cJSON* jsonapi_response_vec_plan_data_inner_1 = api_response_vec_plan_data_inner_convertToJSON(api_response_vec_plan_data_inner_1);
	printf("api_response_vec_plan_data_inner :\n%s\n", cJSON_Print(jsonapi_response_vec_plan_data_inner_1));
	api_response_vec_plan_data_inner_t* api_response_vec_plan_data_inner_2 = api_response_vec_plan_data_inner_parseFromJSON(jsonapi_response_vec_plan_data_inner_1);
	cJSON* jsonapi_response_vec_plan_data_inner_2 = api_response_vec_plan_data_inner_convertToJSON(api_response_vec_plan_data_inner_2);
	printf("repeating api_response_vec_plan_data_inner:\n%s\n", cJSON_Print(jsonapi_response_vec_plan_data_inner_2));
}

int main() {
  test_api_response_vec_plan_data_inner(1);
  test_api_response_vec_plan_data_inner(0);

  printf("Hello world \n");
  return 0;
}

#endif // api_response_vec_plan_data_inner_MAIN
#endif // api_response_vec_plan_data_inner_TEST
