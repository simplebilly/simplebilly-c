#ifndef forgot_password_request_TEST
#define forgot_password_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define forgot_password_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/forgot_password_request.h"
forgot_password_request_t* instantiate_forgot_password_request(int include_optional);



forgot_password_request_t* instantiate_forgot_password_request(int include_optional) {
  forgot_password_request_t* forgot_password_request = NULL;
  if (include_optional) {
    forgot_password_request = forgot_password_request_create(
      "0"
    );
  } else {
    forgot_password_request = forgot_password_request_create(
      "0"
    );
  }

  return forgot_password_request;
}


#ifdef forgot_password_request_MAIN

void test_forgot_password_request(int include_optional) {
    forgot_password_request_t* forgot_password_request_1 = instantiate_forgot_password_request(include_optional);

	cJSON* jsonforgot_password_request_1 = forgot_password_request_convertToJSON(forgot_password_request_1);
	printf("forgot_password_request :\n%s\n", cJSON_Print(jsonforgot_password_request_1));
	forgot_password_request_t* forgot_password_request_2 = forgot_password_request_parseFromJSON(jsonforgot_password_request_1);
	cJSON* jsonforgot_password_request_2 = forgot_password_request_convertToJSON(forgot_password_request_2);
	printf("repeating forgot_password_request:\n%s\n", cJSON_Print(jsonforgot_password_request_2));
}

int main() {
  test_forgot_password_request(1);
  test_forgot_password_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // forgot_password_request_MAIN
#endif // forgot_password_request_TEST
