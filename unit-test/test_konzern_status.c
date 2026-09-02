#ifndef konzern_status_TEST
#define konzern_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define konzern_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/konzern_status.h"
konzern_status_t* instantiate_konzern_status(int include_optional);

#include "test_konzern_thresholds.c"


konzern_status_t* instantiate_konzern_status(int include_optional) {
  konzern_status_t* konzern_status = NULL;
  if (include_optional) {
    konzern_status = konzern_status_create(
      1,
      1,
      1,
      1,
      1,
      "0",
      "0",
      list_createList(),
       // false, not to have infinite recursion
      instantiate_konzern_thresholds(0),
      56,
      1,
      "0"
    );
  } else {
    konzern_status = konzern_status_create(
      1,
      1,
      1,
      1,
      1,
      "0",
      "0",
      list_createList(),
      NULL,
      56,
      1,
      "0"
    );
  }

  return konzern_status;
}


#ifdef konzern_status_MAIN

void test_konzern_status(int include_optional) {
    konzern_status_t* konzern_status_1 = instantiate_konzern_status(include_optional);

	cJSON* jsonkonzern_status_1 = konzern_status_convertToJSON(konzern_status_1);
	printf("konzern_status :\n%s\n", cJSON_Print(jsonkonzern_status_1));
	konzern_status_t* konzern_status_2 = konzern_status_parseFromJSON(jsonkonzern_status_1);
	cJSON* jsonkonzern_status_2 = konzern_status_convertToJSON(konzern_status_2);
	printf("repeating konzern_status:\n%s\n", cJSON_Print(jsonkonzern_status_2));
}

int main() {
  test_konzern_status(1);
  test_konzern_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // konzern_status_MAIN
#endif // konzern_status_TEST
