#ifndef plausibility_check_TEST
#define plausibility_check_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define plausibility_check_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/plausibility_check.h"
plausibility_check_t* instantiate_plausibility_check(int include_optional);



plausibility_check_t* instantiate_plausibility_check(int include_optional) {
  plausibility_check_t* plausibility_check = NULL;
  if (include_optional) {
    plausibility_check = plausibility_check_create(
      "0",
      "0",
      "0",
      simplebilly_api_plausibility_check__Info,
      simplebilly_api_plausibility_check__Ok
    );
  } else {
    plausibility_check = plausibility_check_create(
      "0",
      "0",
      "0",
      simplebilly_api_plausibility_check__Info,
      simplebilly_api_plausibility_check__Ok
    );
  }

  return plausibility_check;
}


#ifdef plausibility_check_MAIN

void test_plausibility_check(int include_optional) {
    plausibility_check_t* plausibility_check_1 = instantiate_plausibility_check(include_optional);

	cJSON* jsonplausibility_check_1 = plausibility_check_convertToJSON(plausibility_check_1);
	printf("plausibility_check :\n%s\n", cJSON_Print(jsonplausibility_check_1));
	plausibility_check_t* plausibility_check_2 = plausibility_check_parseFromJSON(jsonplausibility_check_1);
	cJSON* jsonplausibility_check_2 = plausibility_check_convertToJSON(plausibility_check_2);
	printf("repeating plausibility_check:\n%s\n", cJSON_Print(jsonplausibility_check_2));
}

int main() {
  test_plausibility_check(1);
  test_plausibility_check(0);

  printf("Hello world \n");
  return 0;
}

#endif // plausibility_check_MAIN
#endif // plausibility_check_TEST
