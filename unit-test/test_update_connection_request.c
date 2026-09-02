#ifndef update_connection_request_TEST
#define update_connection_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_connection_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_connection_request.h"
update_connection_request_t* instantiate_update_connection_request(int include_optional);



update_connection_request_t* instantiate_update_connection_request(int include_optional) {
  update_connection_request_t* update_connection_request = NULL;
  if (include_optional) {
    update_connection_request = update_connection_request_create(
      "0",
      "0",
      null,
      1,
      "0",
      "0"
    );
  } else {
    update_connection_request = update_connection_request_create(
      "0",
      "0",
      null,
      1,
      "0",
      "0"
    );
  }

  return update_connection_request;
}


#ifdef update_connection_request_MAIN

void test_update_connection_request(int include_optional) {
    update_connection_request_t* update_connection_request_1 = instantiate_update_connection_request(include_optional);

	cJSON* jsonupdate_connection_request_1 = update_connection_request_convertToJSON(update_connection_request_1);
	printf("update_connection_request :\n%s\n", cJSON_Print(jsonupdate_connection_request_1));
	update_connection_request_t* update_connection_request_2 = update_connection_request_parseFromJSON(jsonupdate_connection_request_1);
	cJSON* jsonupdate_connection_request_2 = update_connection_request_convertToJSON(update_connection_request_2);
	printf("repeating update_connection_request:\n%s\n", cJSON_Print(jsonupdate_connection_request_2));
}

int main() {
  test_update_connection_request(1);
  test_update_connection_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_connection_request_MAIN
#endif // update_connection_request_TEST
