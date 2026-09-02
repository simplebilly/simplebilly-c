#ifndef plan_features_TEST
#define plan_features_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define plan_features_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/plan_features.h"
plan_features_t* instantiate_plan_features(int include_optional);



plan_features_t* instantiate_plan_features(int include_optional) {
  plan_features_t* plan_features = NULL;
  if (include_optional) {
    plan_features = plan_features_create(
      1,
      1,
      1,
      1
    );
  } else {
    plan_features = plan_features_create(
      1,
      1,
      1,
      1
    );
  }

  return plan_features;
}


#ifdef plan_features_MAIN

void test_plan_features(int include_optional) {
    plan_features_t* plan_features_1 = instantiate_plan_features(include_optional);

	cJSON* jsonplan_features_1 = plan_features_convertToJSON(plan_features_1);
	printf("plan_features :\n%s\n", cJSON_Print(jsonplan_features_1));
	plan_features_t* plan_features_2 = plan_features_parseFromJSON(jsonplan_features_1);
	cJSON* jsonplan_features_2 = plan_features_convertToJSON(plan_features_2);
	printf("repeating plan_features:\n%s\n", cJSON_Print(jsonplan_features_2));
}

int main() {
  test_plan_features(1);
  test_plan_features(0);

  printf("Hello world \n");
  return 0;
}

#endif // plan_features_MAIN
#endif // plan_features_TEST
