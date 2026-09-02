#ifndef konzern_thresholds_TEST
#define konzern_thresholds_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define konzern_thresholds_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/konzern_thresholds.h"
konzern_thresholds_t* instantiate_konzern_thresholds(int include_optional);



konzern_thresholds_t* instantiate_konzern_thresholds(int include_optional) {
  konzern_thresholds_t* konzern_thresholds = NULL;
  if (include_optional) {
    konzern_thresholds = konzern_thresholds_create(
      "0",
      56,
      "0"
    );
  } else {
    konzern_thresholds = konzern_thresholds_create(
      "0",
      56,
      "0"
    );
  }

  return konzern_thresholds;
}


#ifdef konzern_thresholds_MAIN

void test_konzern_thresholds(int include_optional) {
    konzern_thresholds_t* konzern_thresholds_1 = instantiate_konzern_thresholds(include_optional);

	cJSON* jsonkonzern_thresholds_1 = konzern_thresholds_convertToJSON(konzern_thresholds_1);
	printf("konzern_thresholds :\n%s\n", cJSON_Print(jsonkonzern_thresholds_1));
	konzern_thresholds_t* konzern_thresholds_2 = konzern_thresholds_parseFromJSON(jsonkonzern_thresholds_1);
	cJSON* jsonkonzern_thresholds_2 = konzern_thresholds_convertToJSON(konzern_thresholds_2);
	printf("repeating konzern_thresholds:\n%s\n", cJSON_Print(jsonkonzern_thresholds_2));
}

int main() {
  test_konzern_thresholds(1);
  test_konzern_thresholds(0);

  printf("Hello world \n");
  return 0;
}

#endif // konzern_thresholds_MAIN
#endif // konzern_thresholds_TEST
