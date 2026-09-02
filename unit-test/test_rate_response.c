#ifndef rate_response_TEST
#define rate_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define rate_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/rate_response.h"
rate_response_t* instantiate_rate_response(int include_optional);



rate_response_t* instantiate_rate_response(int include_optional) {
  rate_response_t* rate_response = NULL;
  if (include_optional) {
    rate_response = rate_response_create(
      list_createList()
    );
  } else {
    rate_response = rate_response_create(
      list_createList()
    );
  }

  return rate_response;
}


#ifdef rate_response_MAIN

void test_rate_response(int include_optional) {
    rate_response_t* rate_response_1 = instantiate_rate_response(include_optional);

	cJSON* jsonrate_response_1 = rate_response_convertToJSON(rate_response_1);
	printf("rate_response :\n%s\n", cJSON_Print(jsonrate_response_1));
	rate_response_t* rate_response_2 = rate_response_parseFromJSON(jsonrate_response_1);
	cJSON* jsonrate_response_2 = rate_response_convertToJSON(rate_response_2);
	printf("repeating rate_response:\n%s\n", cJSON_Print(jsonrate_response_2));
}

int main() {
  test_rate_response(1);
  test_rate_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // rate_response_MAIN
#endif // rate_response_TEST
