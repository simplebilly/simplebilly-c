#ifndef box_fit_TEST
#define box_fit_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define box_fit_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/box_fit.h"
box_fit_t* instantiate_box_fit(int include_optional);



box_fit_t* instantiate_box_fit(int include_optional) {
  box_fit_t* box_fit = NULL;
  if (include_optional) {
    box_fit = box_fit_create(
      1.337,
      0,
      1.337,
      1.337,
      1.337
    );
  } else {
    box_fit = box_fit_create(
      1.337,
      0,
      1.337,
      1.337,
      1.337
    );
  }

  return box_fit;
}


#ifdef box_fit_MAIN

void test_box_fit(int include_optional) {
    box_fit_t* box_fit_1 = instantiate_box_fit(include_optional);

	cJSON* jsonbox_fit_1 = box_fit_convertToJSON(box_fit_1);
	printf("box_fit :\n%s\n", cJSON_Print(jsonbox_fit_1));
	box_fit_t* box_fit_2 = box_fit_parseFromJSON(jsonbox_fit_1);
	cJSON* jsonbox_fit_2 = box_fit_convertToJSON(box_fit_2);
	printf("repeating box_fit:\n%s\n", cJSON_Print(jsonbox_fit_2));
}

int main() {
  test_box_fit(1);
  test_box_fit(0);

  printf("Hello world \n");
  return 0;
}

#endif // box_fit_MAIN
#endif // box_fit_TEST
