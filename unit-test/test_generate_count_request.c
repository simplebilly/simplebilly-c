#ifndef generate_count_request_TEST
#define generate_count_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define generate_count_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/generate_count_request.h"
generate_count_request_t* instantiate_generate_count_request(int include_optional);



generate_count_request_t* instantiate_generate_count_request(int include_optional) {
  generate_count_request_t* generate_count_request = NULL;
  if (include_optional) {
    generate_count_request = generate_count_request_create(
      "0",
      list_createList(),
      "0"
    );
  } else {
    generate_count_request = generate_count_request_create(
      "0",
      list_createList(),
      "0"
    );
  }

  return generate_count_request;
}


#ifdef generate_count_request_MAIN

void test_generate_count_request(int include_optional) {
    generate_count_request_t* generate_count_request_1 = instantiate_generate_count_request(include_optional);

	cJSON* jsongenerate_count_request_1 = generate_count_request_convertToJSON(generate_count_request_1);
	printf("generate_count_request :\n%s\n", cJSON_Print(jsongenerate_count_request_1));
	generate_count_request_t* generate_count_request_2 = generate_count_request_parseFromJSON(jsongenerate_count_request_1);
	cJSON* jsongenerate_count_request_2 = generate_count_request_convertToJSON(generate_count_request_2);
	printf("repeating generate_count_request:\n%s\n", cJSON_Print(jsongenerate_count_request_2));
}

int main() {
  test_generate_count_request(1);
  test_generate_count_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // generate_count_request_MAIN
#endif // generate_count_request_TEST
