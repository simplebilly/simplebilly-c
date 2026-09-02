#ifndef tracking_info_TEST
#define tracking_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define tracking_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/tracking_info.h"
tracking_info_t* instantiate_tracking_info(int include_optional);



tracking_info_t* instantiate_tracking_info(int include_optional) {
  tracking_info_t* tracking_info = NULL;
  if (include_optional) {
    tracking_info = tracking_info_create(
      "0",
      "0",
      list_createList(),
      null,
      "0",
      "0"
    );
  } else {
    tracking_info = tracking_info_create(
      "0",
      "0",
      list_createList(),
      null,
      "0",
      "0"
    );
  }

  return tracking_info;
}


#ifdef tracking_info_MAIN

void test_tracking_info(int include_optional) {
    tracking_info_t* tracking_info_1 = instantiate_tracking_info(include_optional);

	cJSON* jsontracking_info_1 = tracking_info_convertToJSON(tracking_info_1);
	printf("tracking_info :\n%s\n", cJSON_Print(jsontracking_info_1));
	tracking_info_t* tracking_info_2 = tracking_info_parseFromJSON(jsontracking_info_1);
	cJSON* jsontracking_info_2 = tracking_info_convertToJSON(tracking_info_2);
	printf("repeating tracking_info:\n%s\n", cJSON_Print(jsontracking_info_2));
}

int main() {
  test_tracking_info(1);
  test_tracking_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // tracking_info_MAIN
#endif // tracking_info_TEST
