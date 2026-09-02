#ifndef method_suitability_TEST
#define method_suitability_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define method_suitability_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/method_suitability.h"
method_suitability_t* instantiate_method_suitability(int include_optional);

#include "test_shipping_rate.c"


method_suitability_t* instantiate_method_suitability(int include_optional) {
  method_suitability_t* method_suitability = NULL;
  if (include_optional) {
    method_suitability = method_suitability_create(
      "0",
       // false, not to have infinite recursion
      instantiate_shipping_rate(0),
      list_createList(),
      "0",
      1
    );
  } else {
    method_suitability = method_suitability_create(
      "0",
      NULL,
      list_createList(),
      "0",
      1
    );
  }

  return method_suitability;
}


#ifdef method_suitability_MAIN

void test_method_suitability(int include_optional) {
    method_suitability_t* method_suitability_1 = instantiate_method_suitability(include_optional);

	cJSON* jsonmethod_suitability_1 = method_suitability_convertToJSON(method_suitability_1);
	printf("method_suitability :\n%s\n", cJSON_Print(jsonmethod_suitability_1));
	method_suitability_t* method_suitability_2 = method_suitability_parseFromJSON(jsonmethod_suitability_1);
	cJSON* jsonmethod_suitability_2 = method_suitability_convertToJSON(method_suitability_2);
	printf("repeating method_suitability:\n%s\n", cJSON_Print(jsonmethod_suitability_2));
}

int main() {
  test_method_suitability(1);
  test_method_suitability(0);

  printf("Hello world \n");
  return 0;
}

#endif // method_suitability_MAIN
#endif // method_suitability_TEST
