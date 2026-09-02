#ifndef replenishment_suggestion_line_TEST
#define replenishment_suggestion_line_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define replenishment_suggestion_line_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/replenishment_suggestion_line.h"
replenishment_suggestion_line_t* instantiate_replenishment_suggestion_line(int include_optional);



replenishment_suggestion_line_t* instantiate_replenishment_suggestion_line(int include_optional) {
  replenishment_suggestion_line_t* replenishment_suggestion_line = NULL;
  if (include_optional) {
    replenishment_suggestion_line = replenishment_suggestion_line_create(
      56,
      56,
      56,
      "0",
      "0",
      "0",
      56,
      "0",
      56,
      "0"
    );
  } else {
    replenishment_suggestion_line = replenishment_suggestion_line_create(
      56,
      56,
      56,
      "0",
      "0",
      "0",
      56,
      "0",
      56,
      "0"
    );
  }

  return replenishment_suggestion_line;
}


#ifdef replenishment_suggestion_line_MAIN

void test_replenishment_suggestion_line(int include_optional) {
    replenishment_suggestion_line_t* replenishment_suggestion_line_1 = instantiate_replenishment_suggestion_line(include_optional);

	cJSON* jsonreplenishment_suggestion_line_1 = replenishment_suggestion_line_convertToJSON(replenishment_suggestion_line_1);
	printf("replenishment_suggestion_line :\n%s\n", cJSON_Print(jsonreplenishment_suggestion_line_1));
	replenishment_suggestion_line_t* replenishment_suggestion_line_2 = replenishment_suggestion_line_parseFromJSON(jsonreplenishment_suggestion_line_1);
	cJSON* jsonreplenishment_suggestion_line_2 = replenishment_suggestion_line_convertToJSON(replenishment_suggestion_line_2);
	printf("repeating replenishment_suggestion_line:\n%s\n", cJSON_Print(jsonreplenishment_suggestion_line_2));
}

int main() {
  test_replenishment_suggestion_line(1);
  test_replenishment_suggestion_line(0);

  printf("Hello world \n");
  return 0;
}

#endif // replenishment_suggestion_line_MAIN
#endif // replenishment_suggestion_line_TEST
