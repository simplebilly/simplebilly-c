#ifndef create_subscription_request_TEST
#define create_subscription_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_subscription_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_subscription_request.h"
create_subscription_request_t* instantiate_create_subscription_request(int include_optional);



create_subscription_request_t* instantiate_create_subscription_request(int include_optional) {
  create_subscription_request_t* create_subscription_request = NULL;
  if (include_optional) {
    create_subscription_request = create_subscription_request_create(
      "0",
      1,
      "0",
      "0",
      "0"
    );
  } else {
    create_subscription_request = create_subscription_request_create(
      "0",
      1,
      "0",
      "0",
      "0"
    );
  }

  return create_subscription_request;
}


#ifdef create_subscription_request_MAIN

void test_create_subscription_request(int include_optional) {
    create_subscription_request_t* create_subscription_request_1 = instantiate_create_subscription_request(include_optional);

	cJSON* jsoncreate_subscription_request_1 = create_subscription_request_convertToJSON(create_subscription_request_1);
	printf("create_subscription_request :\n%s\n", cJSON_Print(jsoncreate_subscription_request_1));
	create_subscription_request_t* create_subscription_request_2 = create_subscription_request_parseFromJSON(jsoncreate_subscription_request_1);
	cJSON* jsoncreate_subscription_request_2 = create_subscription_request_convertToJSON(create_subscription_request_2);
	printf("repeating create_subscription_request:\n%s\n", cJSON_Print(jsoncreate_subscription_request_2));
}

int main() {
  test_create_subscription_request(1);
  test_create_subscription_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_subscription_request_MAIN
#endif // create_subscription_request_TEST
