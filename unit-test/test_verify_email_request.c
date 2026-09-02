#ifndef verify_email_request_TEST
#define verify_email_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define verify_email_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/verify_email_request.h"
verify_email_request_t* instantiate_verify_email_request(int include_optional);



verify_email_request_t* instantiate_verify_email_request(int include_optional) {
  verify_email_request_t* verify_email_request = NULL;
  if (include_optional) {
    verify_email_request = verify_email_request_create(
      "0"
    );
  } else {
    verify_email_request = verify_email_request_create(
      "0"
    );
  }

  return verify_email_request;
}


#ifdef verify_email_request_MAIN

void test_verify_email_request(int include_optional) {
    verify_email_request_t* verify_email_request_1 = instantiate_verify_email_request(include_optional);

	cJSON* jsonverify_email_request_1 = verify_email_request_convertToJSON(verify_email_request_1);
	printf("verify_email_request :\n%s\n", cJSON_Print(jsonverify_email_request_1));
	verify_email_request_t* verify_email_request_2 = verify_email_request_parseFromJSON(jsonverify_email_request_1);
	cJSON* jsonverify_email_request_2 = verify_email_request_convertToJSON(verify_email_request_2);
	printf("repeating verify_email_request:\n%s\n", cJSON_Print(jsonverify_email_request_2));
}

int main() {
  test_verify_email_request(1);
  test_verify_email_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // verify_email_request_MAIN
#endif // verify_email_request_TEST
