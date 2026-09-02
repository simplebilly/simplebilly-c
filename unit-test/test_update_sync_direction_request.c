#ifndef update_sync_direction_request_TEST
#define update_sync_direction_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_sync_direction_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_sync_direction_request.h"
update_sync_direction_request_t* instantiate_update_sync_direction_request(int include_optional);



update_sync_direction_request_t* instantiate_update_sync_direction_request(int include_optional) {
  update_sync_direction_request_t* update_sync_direction_request = NULL;
  if (include_optional) {
    update_sync_direction_request = update_sync_direction_request_create(
      list_createList()
    );
  } else {
    update_sync_direction_request = update_sync_direction_request_create(
      list_createList()
    );
  }

  return update_sync_direction_request;
}


#ifdef update_sync_direction_request_MAIN

void test_update_sync_direction_request(int include_optional) {
    update_sync_direction_request_t* update_sync_direction_request_1 = instantiate_update_sync_direction_request(include_optional);

	cJSON* jsonupdate_sync_direction_request_1 = update_sync_direction_request_convertToJSON(update_sync_direction_request_1);
	printf("update_sync_direction_request :\n%s\n", cJSON_Print(jsonupdate_sync_direction_request_1));
	update_sync_direction_request_t* update_sync_direction_request_2 = update_sync_direction_request_parseFromJSON(jsonupdate_sync_direction_request_1);
	cJSON* jsonupdate_sync_direction_request_2 = update_sync_direction_request_convertToJSON(update_sync_direction_request_2);
	printf("repeating update_sync_direction_request:\n%s\n", cJSON_Print(jsonupdate_sync_direction_request_2));
}

int main() {
  test_update_sync_direction_request(1);
  test_update_sync_direction_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_sync_direction_request_MAIN
#endif // update_sync_direction_request_TEST
