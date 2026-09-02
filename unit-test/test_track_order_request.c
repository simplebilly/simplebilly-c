#ifndef track_order_request_TEST
#define track_order_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define track_order_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/track_order_request.h"
track_order_request_t* instantiate_track_order_request(int include_optional);



track_order_request_t* instantiate_track_order_request(int include_optional) {
  track_order_request_t* track_order_request = NULL;
  if (include_optional) {
    track_order_request = track_order_request_create(
      "0",
      "0"
    );
  } else {
    track_order_request = track_order_request_create(
      "0",
      "0"
    );
  }

  return track_order_request;
}


#ifdef track_order_request_MAIN

void test_track_order_request(int include_optional) {
    track_order_request_t* track_order_request_1 = instantiate_track_order_request(include_optional);

	cJSON* jsontrack_order_request_1 = track_order_request_convertToJSON(track_order_request_1);
	printf("track_order_request :\n%s\n", cJSON_Print(jsontrack_order_request_1));
	track_order_request_t* track_order_request_2 = track_order_request_parseFromJSON(jsontrack_order_request_1);
	cJSON* jsontrack_order_request_2 = track_order_request_convertToJSON(track_order_request_2);
	printf("repeating track_order_request:\n%s\n", cJSON_Print(jsontrack_order_request_2));
}

int main() {
  test_track_order_request(1);
  test_track_order_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // track_order_request_MAIN
#endif // track_order_request_TEST
