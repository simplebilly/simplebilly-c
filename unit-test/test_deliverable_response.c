#ifndef deliverable_response_TEST
#define deliverable_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define deliverable_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/deliverable_response.h"
deliverable_response_t* instantiate_deliverable_response(int include_optional);



deliverable_response_t* instantiate_deliverable_response(int include_optional) {
  deliverable_response_t* deliverable_response = NULL;
  if (include_optional) {
    deliverable_response = deliverable_response_create(
      56,
      56,
      56,
      "0",
      56,
      "0"
    );
  } else {
    deliverable_response = deliverable_response_create(
      56,
      56,
      56,
      "0",
      56,
      "0"
    );
  }

  return deliverable_response;
}


#ifdef deliverable_response_MAIN

void test_deliverable_response(int include_optional) {
    deliverable_response_t* deliverable_response_1 = instantiate_deliverable_response(include_optional);

	cJSON* jsondeliverable_response_1 = deliverable_response_convertToJSON(deliverable_response_1);
	printf("deliverable_response :\n%s\n", cJSON_Print(jsondeliverable_response_1));
	deliverable_response_t* deliverable_response_2 = deliverable_response_parseFromJSON(jsondeliverable_response_1);
	cJSON* jsondeliverable_response_2 = deliverable_response_convertToJSON(deliverable_response_2);
	printf("repeating deliverable_response:\n%s\n", cJSON_Print(jsondeliverable_response_2));
}

int main() {
  test_deliverable_response(1);
  test_deliverable_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // deliverable_response_MAIN
#endif // deliverable_response_TEST
