#ifndef sync_log_status_TEST
#define sync_log_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sync_log_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sync_log_status.h"
sync_log_status_t* instantiate_sync_log_status(int include_optional);



sync_log_status_t* instantiate_sync_log_status(int include_optional) {
  sync_log_status_t* sync_log_status = NULL;
  if (include_optional) {
    sync_log_status = sync_log_status_create(
    );
  } else {
    sync_log_status = sync_log_status_create(
    );
  }

  return sync_log_status;
}


#ifdef sync_log_status_MAIN

void test_sync_log_status(int include_optional) {
    sync_log_status_t* sync_log_status_1 = instantiate_sync_log_status(include_optional);

	cJSON* jsonsync_log_status_1 = sync_log_status_convertToJSON(sync_log_status_1);
	printf("sync_log_status :\n%s\n", cJSON_Print(jsonsync_log_status_1));
	sync_log_status_t* sync_log_status_2 = sync_log_status_parseFromJSON(jsonsync_log_status_1);
	cJSON* jsonsync_log_status_2 = sync_log_status_convertToJSON(sync_log_status_2);
	printf("repeating sync_log_status:\n%s\n", cJSON_Print(jsonsync_log_status_2));
}

int main() {
  test_sync_log_status(1);
  test_sync_log_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // sync_log_status_MAIN
#endif // sync_log_status_TEST
