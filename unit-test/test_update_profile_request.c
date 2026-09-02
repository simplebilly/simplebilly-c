#ifndef update_profile_request_TEST
#define update_profile_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_profile_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_profile_request.h"
update_profile_request_t* instantiate_update_profile_request(int include_optional);



update_profile_request_t* instantiate_update_profile_request(int include_optional) {
  update_profile_request_t* update_profile_request = NULL;
  if (include_optional) {
    update_profile_request = update_profile_request_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    update_profile_request = update_profile_request_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return update_profile_request;
}


#ifdef update_profile_request_MAIN

void test_update_profile_request(int include_optional) {
    update_profile_request_t* update_profile_request_1 = instantiate_update_profile_request(include_optional);

	cJSON* jsonupdate_profile_request_1 = update_profile_request_convertToJSON(update_profile_request_1);
	printf("update_profile_request :\n%s\n", cJSON_Print(jsonupdate_profile_request_1));
	update_profile_request_t* update_profile_request_2 = update_profile_request_parseFromJSON(jsonupdate_profile_request_1);
	cJSON* jsonupdate_profile_request_2 = update_profile_request_convertToJSON(update_profile_request_2);
	printf("repeating update_profile_request:\n%s\n", cJSON_Print(jsonupdate_profile_request_2));
}

int main() {
  test_update_profile_request(1);
  test_update_profile_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_profile_request_MAIN
#endif // update_profile_request_TEST
