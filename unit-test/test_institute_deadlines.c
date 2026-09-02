#ifndef institute_deadlines_TEST
#define institute_deadlines_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define institute_deadlines_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/institute_deadlines.h"
institute_deadlines_t* instantiate_institute_deadlines(int include_optional);



institute_deadlines_t* instantiate_institute_deadlines(int include_optional) {
  institute_deadlines_t* institute_deadlines = NULL;
  if (include_optional) {
    institute_deadlines = institute_deadlines_create(
      56,
      56,
      56
    );
  } else {
    institute_deadlines = institute_deadlines_create(
      56,
      56,
      56
    );
  }

  return institute_deadlines;
}


#ifdef institute_deadlines_MAIN

void test_institute_deadlines(int include_optional) {
    institute_deadlines_t* institute_deadlines_1 = instantiate_institute_deadlines(include_optional);

	cJSON* jsoninstitute_deadlines_1 = institute_deadlines_convertToJSON(institute_deadlines_1);
	printf("institute_deadlines :\n%s\n", cJSON_Print(jsoninstitute_deadlines_1));
	institute_deadlines_t* institute_deadlines_2 = institute_deadlines_parseFromJSON(jsoninstitute_deadlines_1);
	cJSON* jsoninstitute_deadlines_2 = institute_deadlines_convertToJSON(institute_deadlines_2);
	printf("repeating institute_deadlines:\n%s\n", cJSON_Print(jsoninstitute_deadlines_2));
}

int main() {
  test_institute_deadlines(1);
  test_institute_deadlines(0);

  printf("Hello world \n");
  return 0;
}

#endif // institute_deadlines_MAIN
#endif // institute_deadlines_TEST
