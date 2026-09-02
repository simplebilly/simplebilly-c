#ifndef hr_training_overview_TEST
#define hr_training_overview_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define hr_training_overview_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/hr_training_overview.h"
hr_training_overview_t* instantiate_hr_training_overview(int include_optional);



hr_training_overview_t* instantiate_hr_training_overview(int include_optional) {
  hr_training_overview_t* hr_training_overview = NULL;
  if (include_optional) {
    hr_training_overview = hr_training_overview_create(
      56,
      "0",
      56,
      56,
      "0",
      "0"
    );
  } else {
    hr_training_overview = hr_training_overview_create(
      56,
      "0",
      56,
      56,
      "0",
      "0"
    );
  }

  return hr_training_overview;
}


#ifdef hr_training_overview_MAIN

void test_hr_training_overview(int include_optional) {
    hr_training_overview_t* hr_training_overview_1 = instantiate_hr_training_overview(include_optional);

	cJSON* jsonhr_training_overview_1 = hr_training_overview_convertToJSON(hr_training_overview_1);
	printf("hr_training_overview :\n%s\n", cJSON_Print(jsonhr_training_overview_1));
	hr_training_overview_t* hr_training_overview_2 = hr_training_overview_parseFromJSON(jsonhr_training_overview_1);
	cJSON* jsonhr_training_overview_2 = hr_training_overview_convertToJSON(hr_training_overview_2);
	printf("repeating hr_training_overview:\n%s\n", cJSON_Print(jsonhr_training_overview_2));
}

int main() {
  test_hr_training_overview(1);
  test_hr_training_overview(0);

  printf("Hello world \n");
  return 0;
}

#endif // hr_training_overview_MAIN
#endif // hr_training_overview_TEST
