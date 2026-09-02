#ifndef create_connection_request_TEST
#define create_connection_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_connection_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_connection_request.h"
create_connection_request_t* instantiate_create_connection_request(int include_optional);



create_connection_request_t* instantiate_create_connection_request(int include_optional) {
  create_connection_request_t* create_connection_request = NULL;
  if (include_optional) {
    create_connection_request = create_connection_request_create(
      "0",
      "0",
      null,
      "0",
      "0",
      "0"
    );
  } else {
    create_connection_request = create_connection_request_create(
      "0",
      "0",
      null,
      "0",
      "0",
      "0"
    );
  }

  return create_connection_request;
}


#ifdef create_connection_request_MAIN

void test_create_connection_request(int include_optional) {
    create_connection_request_t* create_connection_request_1 = instantiate_create_connection_request(include_optional);

	cJSON* jsoncreate_connection_request_1 = create_connection_request_convertToJSON(create_connection_request_1);
	printf("create_connection_request :\n%s\n", cJSON_Print(jsoncreate_connection_request_1));
	create_connection_request_t* create_connection_request_2 = create_connection_request_parseFromJSON(jsoncreate_connection_request_1);
	cJSON* jsoncreate_connection_request_2 = create_connection_request_convertToJSON(create_connection_request_2);
	printf("repeating create_connection_request:\n%s\n", cJSON_Print(jsoncreate_connection_request_2));
}

int main() {
  test_create_connection_request(1);
  test_create_connection_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_connection_request_MAIN
#endif // create_connection_request_TEST
