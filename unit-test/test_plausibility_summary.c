#ifndef plausibility_summary_TEST
#define plausibility_summary_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define plausibility_summary_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/plausibility_summary.h"
plausibility_summary_t* instantiate_plausibility_summary(int include_optional);



plausibility_summary_t* instantiate_plausibility_summary(int include_optional) {
  plausibility_summary_t* plausibility_summary = NULL;
  if (include_optional) {
    plausibility_summary = plausibility_summary_create(
      0,
      simplebilly_api_plausibility_summary__Ok,
      0,
      0,
      0
    );
  } else {
    plausibility_summary = plausibility_summary_create(
      0,
      simplebilly_api_plausibility_summary__Ok,
      0,
      0,
      0
    );
  }

  return plausibility_summary;
}


#ifdef plausibility_summary_MAIN

void test_plausibility_summary(int include_optional) {
    plausibility_summary_t* plausibility_summary_1 = instantiate_plausibility_summary(include_optional);

	cJSON* jsonplausibility_summary_1 = plausibility_summary_convertToJSON(plausibility_summary_1);
	printf("plausibility_summary :\n%s\n", cJSON_Print(jsonplausibility_summary_1));
	plausibility_summary_t* plausibility_summary_2 = plausibility_summary_parseFromJSON(jsonplausibility_summary_1);
	cJSON* jsonplausibility_summary_2 = plausibility_summary_convertToJSON(plausibility_summary_2);
	printf("repeating plausibility_summary:\n%s\n", cJSON_Print(jsonplausibility_summary_2));
}

int main() {
  test_plausibility_summary(1);
  test_plausibility_summary(0);

  printf("Hello world \n");
  return 0;
}

#endif // plausibility_summary_MAIN
#endif // plausibility_summary_TEST
