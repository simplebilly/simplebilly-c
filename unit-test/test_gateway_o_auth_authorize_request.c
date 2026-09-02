#ifndef gateway_o_auth_authorize_request_TEST
#define gateway_o_auth_authorize_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gateway_o_auth_authorize_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gateway_o_auth_authorize_request.h"
gateway_o_auth_authorize_request_t* instantiate_gateway_o_auth_authorize_request(int include_optional);



gateway_o_auth_authorize_request_t* instantiate_gateway_o_auth_authorize_request(int include_optional) {
  gateway_o_auth_authorize_request_t* gateway_o_auth_authorize_request = NULL;
  if (include_optional) {
    gateway_o_auth_authorize_request = gateway_o_auth_authorize_request_create(
      "0",
      "0"
    );
  } else {
    gateway_o_auth_authorize_request = gateway_o_auth_authorize_request_create(
      "0",
      "0"
    );
  }

  return gateway_o_auth_authorize_request;
}


#ifdef gateway_o_auth_authorize_request_MAIN

void test_gateway_o_auth_authorize_request(int include_optional) {
    gateway_o_auth_authorize_request_t* gateway_o_auth_authorize_request_1 = instantiate_gateway_o_auth_authorize_request(include_optional);

	cJSON* jsongateway_o_auth_authorize_request_1 = gateway_o_auth_authorize_request_convertToJSON(gateway_o_auth_authorize_request_1);
	printf("gateway_o_auth_authorize_request :\n%s\n", cJSON_Print(jsongateway_o_auth_authorize_request_1));
	gateway_o_auth_authorize_request_t* gateway_o_auth_authorize_request_2 = gateway_o_auth_authorize_request_parseFromJSON(jsongateway_o_auth_authorize_request_1);
	cJSON* jsongateway_o_auth_authorize_request_2 = gateway_o_auth_authorize_request_convertToJSON(gateway_o_auth_authorize_request_2);
	printf("repeating gateway_o_auth_authorize_request:\n%s\n", cJSON_Print(jsongateway_o_auth_authorize_request_2));
}

int main() {
  test_gateway_o_auth_authorize_request(1);
  test_gateway_o_auth_authorize_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // gateway_o_auth_authorize_request_MAIN
#endif // gateway_o_auth_authorize_request_TEST
