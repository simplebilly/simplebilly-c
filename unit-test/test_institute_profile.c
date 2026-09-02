#ifndef institute_profile_TEST
#define institute_profile_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define institute_profile_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/institute_profile.h"
institute_profile_t* instantiate_institute_profile(int include_optional);



institute_profile_t* instantiate_institute_profile(int include_optional) {
  institute_profile_t* institute_profile = NULL;
  if (include_optional) {
    institute_profile = institute_profile_create(
      kein,
      1
    );
  } else {
    institute_profile = institute_profile_create(
      kein,
      1
    );
  }

  return institute_profile;
}


#ifdef institute_profile_MAIN

void test_institute_profile(int include_optional) {
    institute_profile_t* institute_profile_1 = instantiate_institute_profile(include_optional);

	cJSON* jsoninstitute_profile_1 = institute_profile_convertToJSON(institute_profile_1);
	printf("institute_profile :\n%s\n", cJSON_Print(jsoninstitute_profile_1));
	institute_profile_t* institute_profile_2 = institute_profile_parseFromJSON(jsoninstitute_profile_1);
	cJSON* jsoninstitute_profile_2 = institute_profile_convertToJSON(institute_profile_2);
	printf("repeating institute_profile:\n%s\n", cJSON_Print(jsoninstitute_profile_2));
}

int main() {
  test_institute_profile(1);
  test_institute_profile(0);

  printf("Hello world \n");
  return 0;
}

#endif // institute_profile_MAIN
#endif // institute_profile_TEST
