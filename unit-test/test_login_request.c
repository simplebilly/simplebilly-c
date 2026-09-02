#ifndef login_request_TEST
#define login_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define login_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/login_request.h"
login_request_t* instantiate_login_request(int include_optional);



login_request_t* instantiate_login_request(int include_optional) {
  login_request_t* login_request = NULL;
  if (include_optional) {
    login_request = login_request_create(
      "0",
      "0",
      "0"
    );
  } else {
    login_request = login_request_create(
      "0",
      "0",
      "0"
    );
  }

  return login_request;
}


#ifdef login_request_MAIN

void test_login_request(int include_optional) {
    login_request_t* login_request_1 = instantiate_login_request(include_optional);

	cJSON* jsonlogin_request_1 = login_request_convertToJSON(login_request_1);
	printf("login_request :\n%s\n", cJSON_Print(jsonlogin_request_1));
	login_request_t* login_request_2 = login_request_parseFromJSON(jsonlogin_request_1);
	cJSON* jsonlogin_request_2 = login_request_convertToJSON(login_request_2);
	printf("repeating login_request:\n%s\n", cJSON_Print(jsonlogin_request_2));
}

int main() {
  test_login_request(1);
  test_login_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // login_request_MAIN
#endif // login_request_TEST
