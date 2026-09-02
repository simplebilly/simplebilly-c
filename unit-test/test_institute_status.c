#ifndef institute_status_TEST
#define institute_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define institute_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/institute_status.h"
institute_status_t* instantiate_institute_status(int include_optional);

#include "test_institute_deadlines.c"


institute_status_t* instantiate_institute_status(int include_optional) {
  institute_status_t* institute_status = NULL;
  if (include_optional) {
    institute_status = institute_status_create(
      list_createList(),
       // false, not to have infinite recursion
      instantiate_institute_deadlines(0),
      "0",
      1
    );
  } else {
    institute_status = institute_status_create(
      list_createList(),
      NULL,
      "0",
      1
    );
  }

  return institute_status;
}


#ifdef institute_status_MAIN

void test_institute_status(int include_optional) {
    institute_status_t* institute_status_1 = instantiate_institute_status(include_optional);

	cJSON* jsoninstitute_status_1 = institute_status_convertToJSON(institute_status_1);
	printf("institute_status :\n%s\n", cJSON_Print(jsoninstitute_status_1));
	institute_status_t* institute_status_2 = institute_status_parseFromJSON(jsoninstitute_status_1);
	cJSON* jsoninstitute_status_2 = institute_status_convertToJSON(institute_status_2);
	printf("repeating institute_status:\n%s\n", cJSON_Print(jsoninstitute_status_2));
}

int main() {
  test_institute_status(1);
  test_institute_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // institute_status_MAIN
#endif // institute_status_TEST
