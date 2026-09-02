#ifndef sync_summary_TEST
#define sync_summary_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sync_summary_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sync_summary.h"
sync_summary_t* instantiate_sync_summary(int include_optional);



sync_summary_t* instantiate_sync_summary(int include_optional) {
  sync_summary_t* sync_summary = NULL;
  if (include_optional) {
    sync_summary = sync_summary_create(
      "0",
      56,
      56
    );
  } else {
    sync_summary = sync_summary_create(
      "0",
      56,
      56
    );
  }

  return sync_summary;
}


#ifdef sync_summary_MAIN

void test_sync_summary(int include_optional) {
    sync_summary_t* sync_summary_1 = instantiate_sync_summary(include_optional);

	cJSON* jsonsync_summary_1 = sync_summary_convertToJSON(sync_summary_1);
	printf("sync_summary :\n%s\n", cJSON_Print(jsonsync_summary_1));
	sync_summary_t* sync_summary_2 = sync_summary_parseFromJSON(jsonsync_summary_1);
	cJSON* jsonsync_summary_2 = sync_summary_convertToJSON(sync_summary_2);
	printf("repeating sync_summary:\n%s\n", cJSON_Print(jsonsync_summary_2));
}

int main() {
  test_sync_summary(1);
  test_sync_summary(0);

  printf("Hello world \n");
  return 0;
}

#endif // sync_summary_MAIN
#endif // sync_summary_TEST
