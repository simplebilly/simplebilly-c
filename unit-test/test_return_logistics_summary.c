#ifndef return_logistics_summary_TEST
#define return_logistics_summary_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define return_logistics_summary_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/return_logistics_summary.h"
return_logistics_summary_t* instantiate_return_logistics_summary(int include_optional);



return_logistics_summary_t* instantiate_return_logistics_summary(int include_optional) {
  return_logistics_summary_t* return_logistics_summary = NULL;
  if (include_optional) {
    return_logistics_summary = return_logistics_summary_create(
      null,
      list_createList(),
      56,
      56,
      56,
      0
    );
  } else {
    return_logistics_summary = return_logistics_summary_create(
      null,
      list_createList(),
      56,
      56,
      56,
      0
    );
  }

  return return_logistics_summary;
}


#ifdef return_logistics_summary_MAIN

void test_return_logistics_summary(int include_optional) {
    return_logistics_summary_t* return_logistics_summary_1 = instantiate_return_logistics_summary(include_optional);

	cJSON* jsonreturn_logistics_summary_1 = return_logistics_summary_convertToJSON(return_logistics_summary_1);
	printf("return_logistics_summary :\n%s\n", cJSON_Print(jsonreturn_logistics_summary_1));
	return_logistics_summary_t* return_logistics_summary_2 = return_logistics_summary_parseFromJSON(jsonreturn_logistics_summary_1);
	cJSON* jsonreturn_logistics_summary_2 = return_logistics_summary_convertToJSON(return_logistics_summary_2);
	printf("repeating return_logistics_summary:\n%s\n", cJSON_Print(jsonreturn_logistics_summary_2));
}

int main() {
  test_return_logistics_summary(1);
  test_return_logistics_summary(0);

  printf("Hello world \n");
  return 0;
}

#endif // return_logistics_summary_MAIN
#endif // return_logistics_summary_TEST
