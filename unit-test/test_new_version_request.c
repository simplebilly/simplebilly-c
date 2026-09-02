#ifndef new_version_request_TEST
#define new_version_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define new_version_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/new_version_request.h"
new_version_request_t* instantiate_new_version_request(int include_optional);



new_version_request_t* instantiate_new_version_request(int include_optional) {
  new_version_request_t* new_version_request = NULL;
  if (include_optional) {
    new_version_request = new_version_request_create(
      "0",
      56,
      "0",
      "0",
      "0"
    );
  } else {
    new_version_request = new_version_request_create(
      "0",
      56,
      "0",
      "0",
      "0"
    );
  }

  return new_version_request;
}


#ifdef new_version_request_MAIN

void test_new_version_request(int include_optional) {
    new_version_request_t* new_version_request_1 = instantiate_new_version_request(include_optional);

	cJSON* jsonnew_version_request_1 = new_version_request_convertToJSON(new_version_request_1);
	printf("new_version_request :\n%s\n", cJSON_Print(jsonnew_version_request_1));
	new_version_request_t* new_version_request_2 = new_version_request_parseFromJSON(jsonnew_version_request_1);
	cJSON* jsonnew_version_request_2 = new_version_request_convertToJSON(new_version_request_2);
	printf("repeating new_version_request:\n%s\n", cJSON_Print(jsonnew_version_request_2));
}

int main() {
  test_new_version_request(1);
  test_new_version_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // new_version_request_MAIN
#endif // new_version_request_TEST
