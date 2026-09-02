#ifndef rate_request_TEST
#define rate_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define rate_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/rate_request.h"
rate_request_t* instantiate_rate_request(int include_optional);

#include "test_customer_info.c"
#include "test_address.c"
#include "test_address.c"


rate_request_t* instantiate_rate_request(int include_optional) {
  rate_request_t* rate_request = NULL;
  if (include_optional) {
    rate_request = rate_request_create(
       // false, not to have infinite recursion
      instantiate_customer_info(0),
      list_createList(),
       // false, not to have infinite recursion
      instantiate_address(0),
       // false, not to have infinite recursion
      instantiate_address(0)
    );
  } else {
    rate_request = rate_request_create(
      NULL,
      list_createList(),
      NULL,
      NULL
    );
  }

  return rate_request;
}


#ifdef rate_request_MAIN

void test_rate_request(int include_optional) {
    rate_request_t* rate_request_1 = instantiate_rate_request(include_optional);

	cJSON* jsonrate_request_1 = rate_request_convertToJSON(rate_request_1);
	printf("rate_request :\n%s\n", cJSON_Print(jsonrate_request_1));
	rate_request_t* rate_request_2 = rate_request_parseFromJSON(jsonrate_request_1);
	cJSON* jsonrate_request_2 = rate_request_convertToJSON(rate_request_2);
	printf("repeating rate_request:\n%s\n", cJSON_Print(jsonrate_request_2));
}

int main() {
  test_rate_request(1);
  test_rate_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // rate_request_MAIN
#endif // rate_request_TEST
