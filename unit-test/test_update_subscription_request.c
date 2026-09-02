#ifndef update_subscription_request_TEST
#define update_subscription_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_subscription_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_subscription_request.h"
update_subscription_request_t* instantiate_update_subscription_request(int include_optional);



update_subscription_request_t* instantiate_update_subscription_request(int include_optional) {
  update_subscription_request_t* update_subscription_request = NULL;
  if (include_optional) {
    update_subscription_request = update_subscription_request_create(
      "0",
      1,
      "0",
      "0",
      "0"
    );
  } else {
    update_subscription_request = update_subscription_request_create(
      "0",
      1,
      "0",
      "0",
      "0"
    );
  }

  return update_subscription_request;
}


#ifdef update_subscription_request_MAIN

void test_update_subscription_request(int include_optional) {
    update_subscription_request_t* update_subscription_request_1 = instantiate_update_subscription_request(include_optional);

	cJSON* jsonupdate_subscription_request_1 = update_subscription_request_convertToJSON(update_subscription_request_1);
	printf("update_subscription_request :\n%s\n", cJSON_Print(jsonupdate_subscription_request_1));
	update_subscription_request_t* update_subscription_request_2 = update_subscription_request_parseFromJSON(jsonupdate_subscription_request_1);
	cJSON* jsonupdate_subscription_request_2 = update_subscription_request_convertToJSON(update_subscription_request_2);
	printf("repeating update_subscription_request:\n%s\n", cJSON_Print(jsonupdate_subscription_request_2));
}

int main() {
  test_update_subscription_request(1);
  test_update_subscription_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_subscription_request_MAIN
#endif // update_subscription_request_TEST
