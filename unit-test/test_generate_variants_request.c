#ifndef generate_variants_request_TEST
#define generate_variants_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define generate_variants_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/generate_variants_request.h"
generate_variants_request_t* instantiate_generate_variants_request(int include_optional);



generate_variants_request_t* instantiate_generate_variants_request(int include_optional) {
  generate_variants_request_t* generate_variants_request = NULL;
  if (include_optional) {
    generate_variants_request = generate_variants_request_create(
      list_createList(),
      "0",
      "0",
      "0"
    );
  } else {
    generate_variants_request = generate_variants_request_create(
      list_createList(),
      "0",
      "0",
      "0"
    );
  }

  return generate_variants_request;
}


#ifdef generate_variants_request_MAIN

void test_generate_variants_request(int include_optional) {
    generate_variants_request_t* generate_variants_request_1 = instantiate_generate_variants_request(include_optional);

	cJSON* jsongenerate_variants_request_1 = generate_variants_request_convertToJSON(generate_variants_request_1);
	printf("generate_variants_request :\n%s\n", cJSON_Print(jsongenerate_variants_request_1));
	generate_variants_request_t* generate_variants_request_2 = generate_variants_request_parseFromJSON(jsongenerate_variants_request_1);
	cJSON* jsongenerate_variants_request_2 = generate_variants_request_convertToJSON(generate_variants_request_2);
	printf("repeating generate_variants_request:\n%s\n", cJSON_Print(jsongenerate_variants_request_2));
}

int main() {
  test_generate_variants_request(1);
  test_generate_variants_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // generate_variants_request_MAIN
#endif // generate_variants_request_TEST
