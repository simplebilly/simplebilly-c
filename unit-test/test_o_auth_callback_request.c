#ifndef o_auth_callback_request_TEST
#define o_auth_callback_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define o_auth_callback_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/o_auth_callback_request.h"
o_auth_callback_request_t* instantiate_o_auth_callback_request(int include_optional);



o_auth_callback_request_t* instantiate_o_auth_callback_request(int include_optional) {
  o_auth_callback_request_t* o_auth_callback_request = NULL;
  if (include_optional) {
    o_auth_callback_request = o_auth_callback_request_create(
      "0",
      null,
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    o_auth_callback_request = o_auth_callback_request_create(
      "0",
      null,
      "0",
      "0",
      "0",
      "0"
    );
  }

  return o_auth_callback_request;
}


#ifdef o_auth_callback_request_MAIN

void test_o_auth_callback_request(int include_optional) {
    o_auth_callback_request_t* o_auth_callback_request_1 = instantiate_o_auth_callback_request(include_optional);

	cJSON* jsono_auth_callback_request_1 = o_auth_callback_request_convertToJSON(o_auth_callback_request_1);
	printf("o_auth_callback_request :\n%s\n", cJSON_Print(jsono_auth_callback_request_1));
	o_auth_callback_request_t* o_auth_callback_request_2 = o_auth_callback_request_parseFromJSON(jsono_auth_callback_request_1);
	cJSON* jsono_auth_callback_request_2 = o_auth_callback_request_convertToJSON(o_auth_callback_request_2);
	printf("repeating o_auth_callback_request:\n%s\n", cJSON_Print(jsono_auth_callback_request_2));
}

int main() {
  test_o_auth_callback_request(1);
  test_o_auth_callback_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // o_auth_callback_request_MAIN
#endif // o_auth_callback_request_TEST
