#ifndef suitability_request_TEST
#define suitability_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define suitability_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/suitability_request.h"
suitability_request_t* instantiate_suitability_request(int include_optional);

#include "test_address.c"
#include "test_address.c"


suitability_request_t* instantiate_suitability_request(int include_optional) {
  suitability_request_t* suitability_request = NULL;
  if (include_optional) {
    suitability_request = suitability_request_create(
      0,
      list_createList(),
       // false, not to have infinite recursion
      instantiate_address(0),
       // false, not to have infinite recursion
      instantiate_address(0)
    );
  } else {
    suitability_request = suitability_request_create(
      0,
      list_createList(),
      NULL,
      NULL
    );
  }

  return suitability_request;
}


#ifdef suitability_request_MAIN

void test_suitability_request(int include_optional) {
    suitability_request_t* suitability_request_1 = instantiate_suitability_request(include_optional);

	cJSON* jsonsuitability_request_1 = suitability_request_convertToJSON(suitability_request_1);
	printf("suitability_request :\n%s\n", cJSON_Print(jsonsuitability_request_1));
	suitability_request_t* suitability_request_2 = suitability_request_parseFromJSON(jsonsuitability_request_1);
	cJSON* jsonsuitability_request_2 = suitability_request_convertToJSON(suitability_request_2);
	printf("repeating suitability_request:\n%s\n", cJSON_Print(jsonsuitability_request_2));
}

int main() {
  test_suitability_request(1);
  test_suitability_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // suitability_request_MAIN
#endif // suitability_request_TEST
