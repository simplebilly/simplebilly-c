#ifndef plan_limits_TEST
#define plan_limits_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define plan_limits_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/plan_limits.h"
plan_limits_t* instantiate_plan_limits(int include_optional);



plan_limits_t* instantiate_plan_limits(int include_optional) {
  plan_limits_t* plan_limits = NULL;
  if (include_optional) {
    plan_limits = plan_limits_create(
      56,
      56,
      56,
      list_createList(),
      list_createList()
    );
  } else {
    plan_limits = plan_limits_create(
      56,
      56,
      56,
      list_createList(),
      list_createList()
    );
  }

  return plan_limits;
}


#ifdef plan_limits_MAIN

void test_plan_limits(int include_optional) {
    plan_limits_t* plan_limits_1 = instantiate_plan_limits(include_optional);

	cJSON* jsonplan_limits_1 = plan_limits_convertToJSON(plan_limits_1);
	printf("plan_limits :\n%s\n", cJSON_Print(jsonplan_limits_1));
	plan_limits_t* plan_limits_2 = plan_limits_parseFromJSON(jsonplan_limits_1);
	cJSON* jsonplan_limits_2 = plan_limits_convertToJSON(plan_limits_2);
	printf("repeating plan_limits:\n%s\n", cJSON_Print(jsonplan_limits_2));
}

int main() {
  test_plan_limits(1);
  test_plan_limits(0);

  printf("Hello world \n");
  return 0;
}

#endif // plan_limits_MAIN
#endif // plan_limits_TEST
