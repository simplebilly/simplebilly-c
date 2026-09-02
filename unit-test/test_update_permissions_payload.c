#ifndef update_permissions_payload_TEST
#define update_permissions_payload_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_permissions_payload_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_permissions_payload.h"
update_permissions_payload_t* instantiate_update_permissions_payload(int include_optional);



update_permissions_payload_t* instantiate_update_permissions_payload(int include_optional) {
  update_permissions_payload_t* update_permissions_payload = NULL;
  if (include_optional) {
    update_permissions_payload = update_permissions_payload_create(
      list_createList()
    );
  } else {
    update_permissions_payload = update_permissions_payload_create(
      list_createList()
    );
  }

  return update_permissions_payload;
}


#ifdef update_permissions_payload_MAIN

void test_update_permissions_payload(int include_optional) {
    update_permissions_payload_t* update_permissions_payload_1 = instantiate_update_permissions_payload(include_optional);

	cJSON* jsonupdate_permissions_payload_1 = update_permissions_payload_convertToJSON(update_permissions_payload_1);
	printf("update_permissions_payload :\n%s\n", cJSON_Print(jsonupdate_permissions_payload_1));
	update_permissions_payload_t* update_permissions_payload_2 = update_permissions_payload_parseFromJSON(jsonupdate_permissions_payload_1);
	cJSON* jsonupdate_permissions_payload_2 = update_permissions_payload_convertToJSON(update_permissions_payload_2);
	printf("repeating update_permissions_payload:\n%s\n", cJSON_Print(jsonupdate_permissions_payload_2));
}

int main() {
  test_update_permissions_payload(1);
  test_update_permissions_payload(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_permissions_payload_MAIN
#endif // update_permissions_payload_TEST
