#ifndef resolved_price_response_TEST
#define resolved_price_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define resolved_price_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/resolved_price_response.h"
resolved_price_response_t* instantiate_resolved_price_response(int include_optional);



resolved_price_response_t* instantiate_resolved_price_response(int include_optional) {
  resolved_price_response_t* resolved_price_response = NULL;
  if (include_optional) {
    resolved_price_response = resolved_price_response_create(
      1,
      "0",
      "0",
      56,
      "0"
    );
  } else {
    resolved_price_response = resolved_price_response_create(
      1,
      "0",
      "0",
      56,
      "0"
    );
  }

  return resolved_price_response;
}


#ifdef resolved_price_response_MAIN

void test_resolved_price_response(int include_optional) {
    resolved_price_response_t* resolved_price_response_1 = instantiate_resolved_price_response(include_optional);

	cJSON* jsonresolved_price_response_1 = resolved_price_response_convertToJSON(resolved_price_response_1);
	printf("resolved_price_response :\n%s\n", cJSON_Print(jsonresolved_price_response_1));
	resolved_price_response_t* resolved_price_response_2 = resolved_price_response_parseFromJSON(jsonresolved_price_response_1);
	cJSON* jsonresolved_price_response_2 = resolved_price_response_convertToJSON(resolved_price_response_2);
	printf("repeating resolved_price_response:\n%s\n", cJSON_Print(jsonresolved_price_response_2));
}

int main() {
  test_resolved_price_response(1);
  test_resolved_price_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // resolved_price_response_MAIN
#endif // resolved_price_response_TEST
