#ifndef accept_invite_request_TEST
#define accept_invite_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define accept_invite_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/accept_invite_request.h"
accept_invite_request_t* instantiate_accept_invite_request(int include_optional);



accept_invite_request_t* instantiate_accept_invite_request(int include_optional) {
  accept_invite_request_t* accept_invite_request = NULL;
  if (include_optional) {
    accept_invite_request = accept_invite_request_create(
      "0",
      "0",
      "0",
      1,
      "0"
    );
  } else {
    accept_invite_request = accept_invite_request_create(
      "0",
      "0",
      "0",
      1,
      "0"
    );
  }

  return accept_invite_request;
}


#ifdef accept_invite_request_MAIN

void test_accept_invite_request(int include_optional) {
    accept_invite_request_t* accept_invite_request_1 = instantiate_accept_invite_request(include_optional);

	cJSON* jsonaccept_invite_request_1 = accept_invite_request_convertToJSON(accept_invite_request_1);
	printf("accept_invite_request :\n%s\n", cJSON_Print(jsonaccept_invite_request_1));
	accept_invite_request_t* accept_invite_request_2 = accept_invite_request_parseFromJSON(jsonaccept_invite_request_1);
	cJSON* jsonaccept_invite_request_2 = accept_invite_request_convertToJSON(accept_invite_request_2);
	printf("repeating accept_invite_request:\n%s\n", cJSON_Print(jsonaccept_invite_request_2));
}

int main() {
  test_accept_invite_request(1);
  test_accept_invite_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // accept_invite_request_MAIN
#endif // accept_invite_request_TEST
