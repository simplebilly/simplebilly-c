#ifndef subscription_overview_TEST
#define subscription_overview_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define subscription_overview_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/subscription_overview.h"
subscription_overview_t* instantiate_subscription_overview(int include_optional);

#include "test_plan_features.c"
#include "test_plan_limits.c"
#include "test_usage_snapshot.c"


subscription_overview_t* instantiate_subscription_overview(int include_optional) {
  subscription_overview_t* subscription_overview = NULL;
  if (include_optional) {
    subscription_overview = subscription_overview_create(
      "2013-10-20T19:20:30+01:00",
       // false, not to have infinite recursion
      instantiate_plan_features(0),
      1,
       // false, not to have infinite recursion
      instantiate_plan_limits(0),
      "0",
      "0",
      "0",
      1.337,
      56,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
       // false, not to have infinite recursion
      instantiate_usage_snapshot(0)
    );
  } else {
    subscription_overview = subscription_overview_create(
      "2013-10-20T19:20:30+01:00",
      NULL,
      1,
      NULL,
      "0",
      "0",
      "0",
      1.337,
      56,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      NULL
    );
  }

  return subscription_overview;
}


#ifdef subscription_overview_MAIN

void test_subscription_overview(int include_optional) {
    subscription_overview_t* subscription_overview_1 = instantiate_subscription_overview(include_optional);

	cJSON* jsonsubscription_overview_1 = subscription_overview_convertToJSON(subscription_overview_1);
	printf("subscription_overview :\n%s\n", cJSON_Print(jsonsubscription_overview_1));
	subscription_overview_t* subscription_overview_2 = subscription_overview_parseFromJSON(jsonsubscription_overview_1);
	cJSON* jsonsubscription_overview_2 = subscription_overview_convertToJSON(subscription_overview_2);
	printf("repeating subscription_overview:\n%s\n", cJSON_Print(jsonsubscription_overview_2));
}

int main() {
  test_subscription_overview(1);
  test_subscription_overview(0);

  printf("Hello world \n");
  return 0;
}

#endif // subscription_overview_MAIN
#endif // subscription_overview_TEST
