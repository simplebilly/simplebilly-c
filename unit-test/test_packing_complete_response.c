#ifndef packing_complete_response_TEST
#define packing_complete_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define packing_complete_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/packing_complete_response.h"
packing_complete_response_t* instantiate_packing_complete_response(int include_optional);



packing_complete_response_t* instantiate_packing_complete_response(int include_optional) {
  packing_complete_response_t* packing_complete_response = NULL;
  if (include_optional) {
    packing_complete_response = packing_complete_response_create(
      "0",
      "0",
      "0",
      1
    );
  } else {
    packing_complete_response = packing_complete_response_create(
      "0",
      "0",
      "0",
      1
    );
  }

  return packing_complete_response;
}


#ifdef packing_complete_response_MAIN

void test_packing_complete_response(int include_optional) {
    packing_complete_response_t* packing_complete_response_1 = instantiate_packing_complete_response(include_optional);

	cJSON* jsonpacking_complete_response_1 = packing_complete_response_convertToJSON(packing_complete_response_1);
	printf("packing_complete_response :\n%s\n", cJSON_Print(jsonpacking_complete_response_1));
	packing_complete_response_t* packing_complete_response_2 = packing_complete_response_parseFromJSON(jsonpacking_complete_response_1);
	cJSON* jsonpacking_complete_response_2 = packing_complete_response_convertToJSON(packing_complete_response_2);
	printf("repeating packing_complete_response:\n%s\n", cJSON_Print(jsonpacking_complete_response_2));
}

int main() {
  test_packing_complete_response(1);
  test_packing_complete_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // packing_complete_response_MAIN
#endif // packing_complete_response_TEST
