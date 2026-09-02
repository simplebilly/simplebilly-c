#ifndef quota_overview_TEST
#define quota_overview_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define quota_overview_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/quota_overview.h"
quota_overview_t* instantiate_quota_overview(int include_optional);

#include "test_plan_features.c"
#include "test_plan_limits.c"
#include "test_usage_snapshot.c"


quota_overview_t* instantiate_quota_overview(int include_optional) {
  quota_overview_t* quota_overview = NULL;
  if (include_optional) {
    quota_overview = quota_overview_create(
       // false, not to have infinite recursion
      instantiate_plan_features(0),
      1,
       // false, not to have infinite recursion
      instantiate_plan_limits(0),
      list_createList(),
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
       // false, not to have infinite recursion
      instantiate_usage_snapshot(0)
    );
  } else {
    quota_overview = quota_overview_create(
      NULL,
      1,
      NULL,
      list_createList(),
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      NULL
    );
  }

  return quota_overview;
}


#ifdef quota_overview_MAIN

void test_quota_overview(int include_optional) {
    quota_overview_t* quota_overview_1 = instantiate_quota_overview(include_optional);

	cJSON* jsonquota_overview_1 = quota_overview_convertToJSON(quota_overview_1);
	printf("quota_overview :\n%s\n", cJSON_Print(jsonquota_overview_1));
	quota_overview_t* quota_overview_2 = quota_overview_parseFromJSON(jsonquota_overview_1);
	cJSON* jsonquota_overview_2 = quota_overview_convertToJSON(quota_overview_2);
	printf("repeating quota_overview:\n%s\n", cJSON_Print(jsonquota_overview_2));
}

int main() {
  test_quota_overview(1);
  test_quota_overview(0);

  printf("Hello world \n");
  return 0;
}

#endif // quota_overview_MAIN
#endif // quota_overview_TEST
