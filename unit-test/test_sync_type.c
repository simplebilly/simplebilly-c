#ifndef sync_type_TEST
#define sync_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sync_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sync_type.h"
sync_type_t* instantiate_sync_type(int include_optional);



sync_type_t* instantiate_sync_type(int include_optional) {
  sync_type_t* sync_type = NULL;
  if (include_optional) {
    sync_type = sync_type_create(
    );
  } else {
    sync_type = sync_type_create(
    );
  }

  return sync_type;
}


#ifdef sync_type_MAIN

void test_sync_type(int include_optional) {
    sync_type_t* sync_type_1 = instantiate_sync_type(include_optional);

	cJSON* jsonsync_type_1 = sync_type_convertToJSON(sync_type_1);
	printf("sync_type :\n%s\n", cJSON_Print(jsonsync_type_1));
	sync_type_t* sync_type_2 = sync_type_parseFromJSON(jsonsync_type_1);
	cJSON* jsonsync_type_2 = sync_type_convertToJSON(sync_type_2);
	printf("repeating sync_type:\n%s\n", cJSON_Print(jsonsync_type_2));
}

int main() {
  test_sync_type(1);
  test_sync_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // sync_type_MAIN
#endif // sync_type_TEST
