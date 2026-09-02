#ifndef scope_total_TEST
#define scope_total_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define scope_total_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/scope_total.h"
scope_total_t* instantiate_scope_total(int include_optional);



scope_total_t* instantiate_scope_total(int include_optional) {
  scope_total_t* scope_total = NULL;
  if (include_optional) {
    scope_total = scope_total_create(
      "0",
      "0"
    );
  } else {
    scope_total = scope_total_create(
      "0",
      "0"
    );
  }

  return scope_total;
}


#ifdef scope_total_MAIN

void test_scope_total(int include_optional) {
    scope_total_t* scope_total_1 = instantiate_scope_total(include_optional);

	cJSON* jsonscope_total_1 = scope_total_convertToJSON(scope_total_1);
	printf("scope_total :\n%s\n", cJSON_Print(jsonscope_total_1));
	scope_total_t* scope_total_2 = scope_total_parseFromJSON(jsonscope_total_1);
	cJSON* jsonscope_total_2 = scope_total_convertToJSON(scope_total_2);
	printf("repeating scope_total:\n%s\n", cJSON_Print(jsonscope_total_2));
}

int main() {
  test_scope_total(1);
  test_scope_total(0);

  printf("Hello world \n");
  return 0;
}

#endif // scope_total_MAIN
#endif // scope_total_TEST
