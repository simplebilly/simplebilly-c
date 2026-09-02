#ifndef institute_check_item_TEST
#define institute_check_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define institute_check_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/institute_check_item.h"
institute_check_item_t* instantiate_institute_check_item(int include_optional);



institute_check_item_t* instantiate_institute_check_item(int include_optional) {
  institute_check_item_t* institute_check_item = NULL;
  if (include_optional) {
    institute_check_item = institute_check_item_create(
      1,
      "0",
      "0"
    );
  } else {
    institute_check_item = institute_check_item_create(
      1,
      "0",
      "0"
    );
  }

  return institute_check_item;
}


#ifdef institute_check_item_MAIN

void test_institute_check_item(int include_optional) {
    institute_check_item_t* institute_check_item_1 = instantiate_institute_check_item(include_optional);

	cJSON* jsoninstitute_check_item_1 = institute_check_item_convertToJSON(institute_check_item_1);
	printf("institute_check_item :\n%s\n", cJSON_Print(jsoninstitute_check_item_1));
	institute_check_item_t* institute_check_item_2 = institute_check_item_parseFromJSON(jsoninstitute_check_item_1);
	cJSON* jsoninstitute_check_item_2 = institute_check_item_convertToJSON(institute_check_item_2);
	printf("repeating institute_check_item:\n%s\n", cJSON_Print(jsoninstitute_check_item_2));
}

int main() {
  test_institute_check_item(1);
  test_institute_check_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // institute_check_item_MAIN
#endif // institute_check_item_TEST
