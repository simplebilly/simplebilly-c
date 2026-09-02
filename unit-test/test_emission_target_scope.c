#ifndef emission_target_scope_TEST
#define emission_target_scope_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define emission_target_scope_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/emission_target_scope.h"
emission_target_scope_t* instantiate_emission_target_scope(int include_optional);



emission_target_scope_t* instantiate_emission_target_scope(int include_optional) {
  emission_target_scope_t* emission_target_scope = NULL;
  if (include_optional) {
    emission_target_scope = emission_target_scope_create(
    );
  } else {
    emission_target_scope = emission_target_scope_create(
    );
  }

  return emission_target_scope;
}


#ifdef emission_target_scope_MAIN

void test_emission_target_scope(int include_optional) {
    emission_target_scope_t* emission_target_scope_1 = instantiate_emission_target_scope(include_optional);

	cJSON* jsonemission_target_scope_1 = emission_target_scope_convertToJSON(emission_target_scope_1);
	printf("emission_target_scope :\n%s\n", cJSON_Print(jsonemission_target_scope_1));
	emission_target_scope_t* emission_target_scope_2 = emission_target_scope_parseFromJSON(jsonemission_target_scope_1);
	cJSON* jsonemission_target_scope_2 = emission_target_scope_convertToJSON(emission_target_scope_2);
	printf("repeating emission_target_scope:\n%s\n", cJSON_Print(jsonemission_target_scope_2));
}

int main() {
  test_emission_target_scope(1);
  test_emission_target_scope(0);

  printf("Hello world \n");
  return 0;
}

#endif // emission_target_scope_MAIN
#endif // emission_target_scope_TEST
