#ifndef update_role_payload_TEST
#define update_role_payload_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_role_payload_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_role_payload.h"
update_role_payload_t* instantiate_update_role_payload(int include_optional);



update_role_payload_t* instantiate_update_role_payload(int include_optional) {
  update_role_payload_t* update_role_payload = NULL;
  if (include_optional) {
    update_role_payload = update_role_payload_create(
      "0",
      1
    );
  } else {
    update_role_payload = update_role_payload_create(
      "0",
      1
    );
  }

  return update_role_payload;
}


#ifdef update_role_payload_MAIN

void test_update_role_payload(int include_optional) {
    update_role_payload_t* update_role_payload_1 = instantiate_update_role_payload(include_optional);

	cJSON* jsonupdate_role_payload_1 = update_role_payload_convertToJSON(update_role_payload_1);
	printf("update_role_payload :\n%s\n", cJSON_Print(jsonupdate_role_payload_1));
	update_role_payload_t* update_role_payload_2 = update_role_payload_parseFromJSON(jsonupdate_role_payload_1);
	cJSON* jsonupdate_role_payload_2 = update_role_payload_convertToJSON(update_role_payload_2);
	printf("repeating update_role_payload:\n%s\n", cJSON_Print(jsonupdate_role_payload_2));
}

int main() {
  test_update_role_payload(1);
  test_update_role_payload(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_role_payload_MAIN
#endif // update_role_payload_TEST
