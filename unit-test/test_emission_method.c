#ifndef emission_method_TEST
#define emission_method_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define emission_method_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/emission_method.h"
emission_method_t* instantiate_emission_method(int include_optional);



emission_method_t* instantiate_emission_method(int include_optional) {
  emission_method_t* emission_method = NULL;
  if (include_optional) {
    emission_method = emission_method_create(
    );
  } else {
    emission_method = emission_method_create(
    );
  }

  return emission_method;
}


#ifdef emission_method_MAIN

void test_emission_method(int include_optional) {
    emission_method_t* emission_method_1 = instantiate_emission_method(include_optional);

	cJSON* jsonemission_method_1 = emission_method_convertToJSON(emission_method_1);
	printf("emission_method :\n%s\n", cJSON_Print(jsonemission_method_1));
	emission_method_t* emission_method_2 = emission_method_parseFromJSON(jsonemission_method_1);
	cJSON* jsonemission_method_2 = emission_method_convertToJSON(emission_method_2);
	printf("repeating emission_method:\n%s\n", cJSON_Print(jsonemission_method_2));
}

int main() {
  test_emission_method(1);
  test_emission_method(0);

  printf("Hello world \n");
  return 0;
}

#endif // emission_method_MAIN
#endif // emission_method_TEST
