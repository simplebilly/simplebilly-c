#ifndef register_request_TEST
#define register_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define register_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/register_request.h"
register_request_t* instantiate_register_request(int include_optional);



register_request_t* instantiate_register_request(int include_optional) {
  register_request_t* register_request = NULL;
  if (include_optional) {
    register_request = register_request_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      1
    );
  } else {
    register_request = register_request_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      1
    );
  }

  return register_request;
}


#ifdef register_request_MAIN

void test_register_request(int include_optional) {
    register_request_t* register_request_1 = instantiate_register_request(include_optional);

	cJSON* jsonregister_request_1 = register_request_convertToJSON(register_request_1);
	printf("register_request :\n%s\n", cJSON_Print(jsonregister_request_1));
	register_request_t* register_request_2 = register_request_parseFromJSON(jsonregister_request_1);
	cJSON* jsonregister_request_2 = register_request_convertToJSON(register_request_2);
	printf("repeating register_request:\n%s\n", cJSON_Print(jsonregister_request_2));
}

int main() {
  test_register_request(1);
  test_register_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // register_request_MAIN
#endif // register_request_TEST
