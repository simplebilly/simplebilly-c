#ifndef x_rechnung_response_TEST
#define x_rechnung_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define x_rechnung_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/x_rechnung_response.h"
x_rechnung_response_t* instantiate_x_rechnung_response(int include_optional);



x_rechnung_response_t* instantiate_x_rechnung_response(int include_optional) {
  x_rechnung_response_t* x_rechnung_response = NULL;
  if (include_optional) {
    x_rechnung_response = x_rechnung_response_create(
      "0",
      "0",
      "0"
    );
  } else {
    x_rechnung_response = x_rechnung_response_create(
      "0",
      "0",
      "0"
    );
  }

  return x_rechnung_response;
}


#ifdef x_rechnung_response_MAIN

void test_x_rechnung_response(int include_optional) {
    x_rechnung_response_t* x_rechnung_response_1 = instantiate_x_rechnung_response(include_optional);

	cJSON* jsonx_rechnung_response_1 = x_rechnung_response_convertToJSON(x_rechnung_response_1);
	printf("x_rechnung_response :\n%s\n", cJSON_Print(jsonx_rechnung_response_1));
	x_rechnung_response_t* x_rechnung_response_2 = x_rechnung_response_parseFromJSON(jsonx_rechnung_response_1);
	cJSON* jsonx_rechnung_response_2 = x_rechnung_response_convertToJSON(x_rechnung_response_2);
	printf("repeating x_rechnung_response:\n%s\n", cJSON_Print(jsonx_rechnung_response_2));
}

int main() {
  test_x_rechnung_response(1);
  test_x_rechnung_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // x_rechnung_response_MAIN
#endif // x_rechnung_response_TEST
