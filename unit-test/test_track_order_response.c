#ifndef track_order_response_TEST
#define track_order_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define track_order_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/track_order_response.h"
track_order_response_t* instantiate_track_order_response(int include_optional);



track_order_response_t* instantiate_track_order_response(int include_optional) {
  track_order_response_t* track_order_response = NULL;
  if (include_optional) {
    track_order_response = track_order_response_create(
      "0",
      "0",
      list_createList()
    );
  } else {
    track_order_response = track_order_response_create(
      "0",
      "0",
      list_createList()
    );
  }

  return track_order_response;
}


#ifdef track_order_response_MAIN

void test_track_order_response(int include_optional) {
    track_order_response_t* track_order_response_1 = instantiate_track_order_response(include_optional);

	cJSON* jsontrack_order_response_1 = track_order_response_convertToJSON(track_order_response_1);
	printf("track_order_response :\n%s\n", cJSON_Print(jsontrack_order_response_1));
	track_order_response_t* track_order_response_2 = track_order_response_parseFromJSON(jsontrack_order_response_1);
	cJSON* jsontrack_order_response_2 = track_order_response_convertToJSON(track_order_response_2);
	printf("repeating track_order_response:\n%s\n", cJSON_Print(jsontrack_order_response_2));
}

int main() {
  test_track_order_response(1);
  test_track_order_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // track_order_response_MAIN
#endif // track_order_response_TEST
