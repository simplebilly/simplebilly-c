#ifndef mirror_trigger_response_TEST
#define mirror_trigger_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define mirror_trigger_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/mirror_trigger_response.h"
mirror_trigger_response_t* instantiate_mirror_trigger_response(int include_optional);



mirror_trigger_response_t* instantiate_mirror_trigger_response(int include_optional) {
  mirror_trigger_response_t* mirror_trigger_response = NULL;
  if (include_optional) {
    mirror_trigger_response = mirror_trigger_response_create(
      "0"
    );
  } else {
    mirror_trigger_response = mirror_trigger_response_create(
      "0"
    );
  }

  return mirror_trigger_response;
}


#ifdef mirror_trigger_response_MAIN

void test_mirror_trigger_response(int include_optional) {
    mirror_trigger_response_t* mirror_trigger_response_1 = instantiate_mirror_trigger_response(include_optional);

	cJSON* jsonmirror_trigger_response_1 = mirror_trigger_response_convertToJSON(mirror_trigger_response_1);
	printf("mirror_trigger_response :\n%s\n", cJSON_Print(jsonmirror_trigger_response_1));
	mirror_trigger_response_t* mirror_trigger_response_2 = mirror_trigger_response_parseFromJSON(jsonmirror_trigger_response_1);
	cJSON* jsonmirror_trigger_response_2 = mirror_trigger_response_convertToJSON(mirror_trigger_response_2);
	printf("repeating mirror_trigger_response:\n%s\n", cJSON_Print(jsonmirror_trigger_response_2));
}

int main() {
  test_mirror_trigger_response(1);
  test_mirror_trigger_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // mirror_trigger_response_MAIN
#endif // mirror_trigger_response_TEST
