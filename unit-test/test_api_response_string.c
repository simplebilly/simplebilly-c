#ifndef api_response_string_TEST
#define api_response_string_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define api_response_string_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/api_response_string.h"
api_response_string_t* instantiate_api_response_string(int include_optional);



api_response_string_t* instantiate_api_response_string(int include_optional) {
  api_response_string_t* api_response_string = NULL;
  if (include_optional) {
    api_response_string = api_response_string_create(
      "0",
      "0",
      "0",
      1
    );
  } else {
    api_response_string = api_response_string_create(
      "0",
      "0",
      "0",
      1
    );
  }

  return api_response_string;
}


#ifdef api_response_string_MAIN

void test_api_response_string(int include_optional) {
    api_response_string_t* api_response_string_1 = instantiate_api_response_string(include_optional);

	cJSON* jsonapi_response_string_1 = api_response_string_convertToJSON(api_response_string_1);
	printf("api_response_string :\n%s\n", cJSON_Print(jsonapi_response_string_1));
	api_response_string_t* api_response_string_2 = api_response_string_parseFromJSON(jsonapi_response_string_1);
	cJSON* jsonapi_response_string_2 = api_response_string_convertToJSON(api_response_string_2);
	printf("repeating api_response_string:\n%s\n", cJSON_Print(jsonapi_response_string_2));
}

int main() {
  test_api_response_string(1);
  test_api_response_string(0);

  printf("Hello world \n");
  return 0;
}

#endif // api_response_string_MAIN
#endif // api_response_string_TEST
