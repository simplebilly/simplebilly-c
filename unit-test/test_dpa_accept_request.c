#ifndef dpa_accept_request_TEST
#define dpa_accept_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dpa_accept_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dpa_accept_request.h"
dpa_accept_request_t* instantiate_dpa_accept_request(int include_optional);



dpa_accept_request_t* instantiate_dpa_accept_request(int include_optional) {
  dpa_accept_request_t* dpa_accept_request = NULL;
  if (include_optional) {
    dpa_accept_request = dpa_accept_request_create(
      "0",
      "0"
    );
  } else {
    dpa_accept_request = dpa_accept_request_create(
      "0",
      "0"
    );
  }

  return dpa_accept_request;
}


#ifdef dpa_accept_request_MAIN

void test_dpa_accept_request(int include_optional) {
    dpa_accept_request_t* dpa_accept_request_1 = instantiate_dpa_accept_request(include_optional);

	cJSON* jsondpa_accept_request_1 = dpa_accept_request_convertToJSON(dpa_accept_request_1);
	printf("dpa_accept_request :\n%s\n", cJSON_Print(jsondpa_accept_request_1));
	dpa_accept_request_t* dpa_accept_request_2 = dpa_accept_request_parseFromJSON(jsondpa_accept_request_1);
	cJSON* jsondpa_accept_request_2 = dpa_accept_request_convertToJSON(dpa_accept_request_2);
	printf("repeating dpa_accept_request:\n%s\n", cJSON_Print(jsondpa_accept_request_2));
}

int main() {
  test_dpa_accept_request(1);
  test_dpa_accept_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // dpa_accept_request_MAIN
#endif // dpa_accept_request_TEST
