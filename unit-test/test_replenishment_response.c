#ifndef replenishment_response_TEST
#define replenishment_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define replenishment_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/replenishment_response.h"
replenishment_response_t* instantiate_replenishment_response(int include_optional);



replenishment_response_t* instantiate_replenishment_response(int include_optional) {
  replenishment_response_t* replenishment_response = NULL;
  if (include_optional) {
    replenishment_response = replenishment_response_create(
      "2013-10-20T19:20:30+01:00",
      list_createList(),
      "0",
      56
    );
  } else {
    replenishment_response = replenishment_response_create(
      "2013-10-20T19:20:30+01:00",
      list_createList(),
      "0",
      56
    );
  }

  return replenishment_response;
}


#ifdef replenishment_response_MAIN

void test_replenishment_response(int include_optional) {
    replenishment_response_t* replenishment_response_1 = instantiate_replenishment_response(include_optional);

	cJSON* jsonreplenishment_response_1 = replenishment_response_convertToJSON(replenishment_response_1);
	printf("replenishment_response :\n%s\n", cJSON_Print(jsonreplenishment_response_1));
	replenishment_response_t* replenishment_response_2 = replenishment_response_parseFromJSON(jsonreplenishment_response_1);
	cJSON* jsonreplenishment_response_2 = replenishment_response_convertToJSON(replenishment_response_2);
	printf("repeating replenishment_response:\n%s\n", cJSON_Print(jsonreplenishment_response_2));
}

int main() {
  test_replenishment_response(1);
  test_replenishment_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // replenishment_response_MAIN
#endif // replenishment_response_TEST
