#ifndef usage_snapshot_TEST
#define usage_snapshot_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define usage_snapshot_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/usage_snapshot.h"
usage_snapshot_t* instantiate_usage_snapshot(int include_optional);



usage_snapshot_t* instantiate_usage_snapshot(int include_optional) {
  usage_snapshot_t* usage_snapshot = NULL;
  if (include_optional) {
    usage_snapshot = usage_snapshot_create(
      56,
      56,
      56,
      56
    );
  } else {
    usage_snapshot = usage_snapshot_create(
      56,
      56,
      56,
      56
    );
  }

  return usage_snapshot;
}


#ifdef usage_snapshot_MAIN

void test_usage_snapshot(int include_optional) {
    usage_snapshot_t* usage_snapshot_1 = instantiate_usage_snapshot(include_optional);

	cJSON* jsonusage_snapshot_1 = usage_snapshot_convertToJSON(usage_snapshot_1);
	printf("usage_snapshot :\n%s\n", cJSON_Print(jsonusage_snapshot_1));
	usage_snapshot_t* usage_snapshot_2 = usage_snapshot_parseFromJSON(jsonusage_snapshot_1);
	cJSON* jsonusage_snapshot_2 = usage_snapshot_convertToJSON(usage_snapshot_2);
	printf("repeating usage_snapshot:\n%s\n", cJSON_Print(jsonusage_snapshot_2));
}

int main() {
  test_usage_snapshot(1);
  test_usage_snapshot(0);

  printf("Hello world \n");
  return 0;
}

#endif // usage_snapshot_MAIN
#endif // usage_snapshot_TEST
