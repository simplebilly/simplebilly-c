#ifndef institute_type_TEST
#define institute_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define institute_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/institute_type.h"
institute_type_t* instantiate_institute_type(int include_optional);



institute_type_t* instantiate_institute_type(int include_optional) {
  institute_type_t* institute_type = NULL;
  if (include_optional) {
    institute_type = institute_type_create(
    );
  } else {
    institute_type = institute_type_create(
    );
  }

  return institute_type;
}


#ifdef institute_type_MAIN

void test_institute_type(int include_optional) {
    institute_type_t* institute_type_1 = instantiate_institute_type(include_optional);

	cJSON* jsoninstitute_type_1 = institute_type_convertToJSON(institute_type_1);
	printf("institute_type :\n%s\n", cJSON_Print(jsoninstitute_type_1));
	institute_type_t* institute_type_2 = institute_type_parseFromJSON(jsoninstitute_type_1);
	cJSON* jsoninstitute_type_2 = institute_type_convertToJSON(institute_type_2);
	printf("repeating institute_type:\n%s\n", cJSON_Print(jsoninstitute_type_2));
}

int main() {
  test_institute_type(1);
  test_institute_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // institute_type_MAIN
#endif // institute_type_TEST
