#ifndef packing_complete_request_TEST
#define packing_complete_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define packing_complete_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/packing_complete_request.h"
packing_complete_request_t* instantiate_packing_complete_request(int include_optional);



packing_complete_request_t* instantiate_packing_complete_request(int include_optional) {
  packing_complete_request_t* packing_complete_request = NULL;
  if (include_optional) {
    packing_complete_request = packing_complete_request_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    packing_complete_request = packing_complete_request_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return packing_complete_request;
}


#ifdef packing_complete_request_MAIN

void test_packing_complete_request(int include_optional) {
    packing_complete_request_t* packing_complete_request_1 = instantiate_packing_complete_request(include_optional);

	cJSON* jsonpacking_complete_request_1 = packing_complete_request_convertToJSON(packing_complete_request_1);
	printf("packing_complete_request :\n%s\n", cJSON_Print(jsonpacking_complete_request_1));
	packing_complete_request_t* packing_complete_request_2 = packing_complete_request_parseFromJSON(jsonpacking_complete_request_1);
	cJSON* jsonpacking_complete_request_2 = packing_complete_request_convertToJSON(packing_complete_request_2);
	printf("repeating packing_complete_request:\n%s\n", cJSON_Print(jsonpacking_complete_request_2));
}

int main() {
  test_packing_complete_request(1);
  test_packing_complete_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // packing_complete_request_MAIN
#endif // packing_complete_request_TEST
