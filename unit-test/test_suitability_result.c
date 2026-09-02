#ifndef suitability_result_TEST
#define suitability_result_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define suitability_result_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/suitability_result.h"
suitability_result_t* instantiate_suitability_result(int include_optional);

#include "test_box_fit.c"


suitability_result_t* instantiate_suitability_result(int include_optional) {
  suitability_result_t* suitability_result = NULL;
  if (include_optional) {
    suitability_result = suitability_result_create(
      list_createList(),
       // false, not to have infinite recursion
      instantiate_box_fit(0),
      1,
      "0",
      1.337
    );
  } else {
    suitability_result = suitability_result_create(
      list_createList(),
      NULL,
      1,
      "0",
      1.337
    );
  }

  return suitability_result;
}


#ifdef suitability_result_MAIN

void test_suitability_result(int include_optional) {
    suitability_result_t* suitability_result_1 = instantiate_suitability_result(include_optional);

	cJSON* jsonsuitability_result_1 = suitability_result_convertToJSON(suitability_result_1);
	printf("suitability_result :\n%s\n", cJSON_Print(jsonsuitability_result_1));
	suitability_result_t* suitability_result_2 = suitability_result_parseFromJSON(jsonsuitability_result_1);
	cJSON* jsonsuitability_result_2 = suitability_result_convertToJSON(suitability_result_2);
	printf("repeating suitability_result:\n%s\n", cJSON_Print(jsonsuitability_result_2));
}

int main() {
  test_suitability_result(1);
  test_suitability_result(0);

  printf("Hello world \n");
  return 0;
}

#endif // suitability_result_MAIN
#endif // suitability_result_TEST
