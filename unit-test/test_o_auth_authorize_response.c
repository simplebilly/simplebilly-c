#ifndef o_auth_authorize_response_TEST
#define o_auth_authorize_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define o_auth_authorize_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/o_auth_authorize_response.h"
o_auth_authorize_response_t* instantiate_o_auth_authorize_response(int include_optional);



o_auth_authorize_response_t* instantiate_o_auth_authorize_response(int include_optional) {
  o_auth_authorize_response_t* o_auth_authorize_response = NULL;
  if (include_optional) {
    o_auth_authorize_response = o_auth_authorize_response_create(
      "0",
      "0"
    );
  } else {
    o_auth_authorize_response = o_auth_authorize_response_create(
      "0",
      "0"
    );
  }

  return o_auth_authorize_response;
}


#ifdef o_auth_authorize_response_MAIN

void test_o_auth_authorize_response(int include_optional) {
    o_auth_authorize_response_t* o_auth_authorize_response_1 = instantiate_o_auth_authorize_response(include_optional);

	cJSON* jsono_auth_authorize_response_1 = o_auth_authorize_response_convertToJSON(o_auth_authorize_response_1);
	printf("o_auth_authorize_response :\n%s\n", cJSON_Print(jsono_auth_authorize_response_1));
	o_auth_authorize_response_t* o_auth_authorize_response_2 = o_auth_authorize_response_parseFromJSON(jsono_auth_authorize_response_1);
	cJSON* jsono_auth_authorize_response_2 = o_auth_authorize_response_convertToJSON(o_auth_authorize_response_2);
	printf("repeating o_auth_authorize_response:\n%s\n", cJSON_Print(jsono_auth_authorize_response_2));
}

int main() {
  test_o_auth_authorize_response(1);
  test_o_auth_authorize_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // o_auth_authorize_response_MAIN
#endif // o_auth_authorize_response_TEST
