#ifndef magic_link_request_TEST
#define magic_link_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define magic_link_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/magic_link_request.h"
magic_link_request_t* instantiate_magic_link_request(int include_optional);



magic_link_request_t* instantiate_magic_link_request(int include_optional) {
  magic_link_request_t* magic_link_request = NULL;
  if (include_optional) {
    magic_link_request = magic_link_request_create(
      "0"
    );
  } else {
    magic_link_request = magic_link_request_create(
      "0"
    );
  }

  return magic_link_request;
}


#ifdef magic_link_request_MAIN

void test_magic_link_request(int include_optional) {
    magic_link_request_t* magic_link_request_1 = instantiate_magic_link_request(include_optional);

	cJSON* jsonmagic_link_request_1 = magic_link_request_convertToJSON(magic_link_request_1);
	printf("magic_link_request :\n%s\n", cJSON_Print(jsonmagic_link_request_1));
	magic_link_request_t* magic_link_request_2 = magic_link_request_parseFromJSON(jsonmagic_link_request_1);
	cJSON* jsonmagic_link_request_2 = magic_link_request_convertToJSON(magic_link_request_2);
	printf("repeating magic_link_request:\n%s\n", cJSON_Print(jsonmagic_link_request_2));
}

int main() {
  test_magic_link_request(1);
  test_magic_link_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // magic_link_request_MAIN
#endif // magic_link_request_TEST
