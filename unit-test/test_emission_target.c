#ifndef emission_target_TEST
#define emission_target_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define emission_target_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/emission_target.h"
emission_target_t* instantiate_emission_target(int include_optional);



emission_target_t* instantiate_emission_target(int include_optional) {
  emission_target_t* emission_target = NULL;
  if (include_optional) {
    emission_target = emission_target_create(
      "0",
      56,
      "0",
      total,
      "0",
      56,
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    emission_target = emission_target_create(
      "0",
      56,
      "0",
      total,
      "0",
      56,
      "2013-10-20T19:20:30+01:00"
    );
  }

  return emission_target;
}


#ifdef emission_target_MAIN

void test_emission_target(int include_optional) {
    emission_target_t* emission_target_1 = instantiate_emission_target(include_optional);

	cJSON* jsonemission_target_1 = emission_target_convertToJSON(emission_target_1);
	printf("emission_target :\n%s\n", cJSON_Print(jsonemission_target_1));
	emission_target_t* emission_target_2 = emission_target_parseFromJSON(jsonemission_target_1);
	cJSON* jsonemission_target_2 = emission_target_convertToJSON(emission_target_2);
	printf("repeating emission_target:\n%s\n", cJSON_Print(jsonemission_target_2));
}

int main() {
  test_emission_target(1);
  test_emission_target(0);

  printf("Hello world \n");
  return 0;
}

#endif // emission_target_MAIN
#endif // emission_target_TEST
