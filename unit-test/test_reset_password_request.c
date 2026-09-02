#ifndef reset_password_request_TEST
#define reset_password_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define reset_password_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/reset_password_request.h"
reset_password_request_t* instantiate_reset_password_request(int include_optional);



reset_password_request_t* instantiate_reset_password_request(int include_optional) {
  reset_password_request_t* reset_password_request = NULL;
  if (include_optional) {
    reset_password_request = reset_password_request_create(
      "0",
      "0"
    );
  } else {
    reset_password_request = reset_password_request_create(
      "0",
      "0"
    );
  }

  return reset_password_request;
}


#ifdef reset_password_request_MAIN

void test_reset_password_request(int include_optional) {
    reset_password_request_t* reset_password_request_1 = instantiate_reset_password_request(include_optional);

	cJSON* jsonreset_password_request_1 = reset_password_request_convertToJSON(reset_password_request_1);
	printf("reset_password_request :\n%s\n", cJSON_Print(jsonreset_password_request_1));
	reset_password_request_t* reset_password_request_2 = reset_password_request_parseFromJSON(jsonreset_password_request_1);
	cJSON* jsonreset_password_request_2 = reset_password_request_convertToJSON(reset_password_request_2);
	printf("repeating reset_password_request:\n%s\n", cJSON_Print(jsonreset_password_request_2));
}

int main() {
  test_reset_password_request(1);
  test_reset_password_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // reset_password_request_MAIN
#endif // reset_password_request_TEST
