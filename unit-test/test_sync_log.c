#ifndef sync_log_TEST
#define sync_log_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sync_log_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sync_log.h"
sync_log_t* instantiate_sync_log(int include_optional);



sync_log_t* instantiate_sync_log(int include_optional) {
  sync_log_t* sync_log = NULL;
  if (include_optional) {
    sync_log = sync_log_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      56,
      56,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0"
    );
  } else {
    sync_log = sync_log_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      56,
      56,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0"
    );
  }

  return sync_log;
}


#ifdef sync_log_MAIN

void test_sync_log(int include_optional) {
    sync_log_t* sync_log_1 = instantiate_sync_log(include_optional);

	cJSON* jsonsync_log_1 = sync_log_convertToJSON(sync_log_1);
	printf("sync_log :\n%s\n", cJSON_Print(jsonsync_log_1));
	sync_log_t* sync_log_2 = sync_log_parseFromJSON(jsonsync_log_1);
	cJSON* jsonsync_log_2 = sync_log_convertToJSON(sync_log_2);
	printf("repeating sync_log:\n%s\n", cJSON_Print(jsonsync_log_2));
}

int main() {
  test_sync_log(1);
  test_sync_log(0);

  printf("Hello world \n");
  return 0;
}

#endif // sync_log_MAIN
#endif // sync_log_TEST
