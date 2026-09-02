#ifndef return_warehouse_summary_TEST
#define return_warehouse_summary_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define return_warehouse_summary_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/return_warehouse_summary.h"
return_warehouse_summary_t* instantiate_return_warehouse_summary(int include_optional);



return_warehouse_summary_t* instantiate_return_warehouse_summary(int include_optional) {
  return_warehouse_summary_t* return_warehouse_summary = NULL;
  if (include_optional) {
    return_warehouse_summary = return_warehouse_summary_create(
      56,
      56,
      0,
      "0"
    );
  } else {
    return_warehouse_summary = return_warehouse_summary_create(
      56,
      56,
      0,
      "0"
    );
  }

  return return_warehouse_summary;
}


#ifdef return_warehouse_summary_MAIN

void test_return_warehouse_summary(int include_optional) {
    return_warehouse_summary_t* return_warehouse_summary_1 = instantiate_return_warehouse_summary(include_optional);

	cJSON* jsonreturn_warehouse_summary_1 = return_warehouse_summary_convertToJSON(return_warehouse_summary_1);
	printf("return_warehouse_summary :\n%s\n", cJSON_Print(jsonreturn_warehouse_summary_1));
	return_warehouse_summary_t* return_warehouse_summary_2 = return_warehouse_summary_parseFromJSON(jsonreturn_warehouse_summary_1);
	cJSON* jsonreturn_warehouse_summary_2 = return_warehouse_summary_convertToJSON(return_warehouse_summary_2);
	printf("repeating return_warehouse_summary:\n%s\n", cJSON_Print(jsonreturn_warehouse_summary_2));
}

int main() {
  test_return_warehouse_summary(1);
  test_return_warehouse_summary(0);

  printf("Hello world \n");
  return 0;
}

#endif // return_warehouse_summary_MAIN
#endif // return_warehouse_summary_TEST
