#ifndef packing_video_response_TEST
#define packing_video_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define packing_video_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/packing_video_response.h"
packing_video_response_t* instantiate_packing_video_response(int include_optional);



packing_video_response_t* instantiate_packing_video_response(int include_optional) {
  packing_video_response_t* packing_video_response = NULL;
  if (include_optional) {
    packing_video_response = packing_video_response_create(
      "0",
      "0",
      1
    );
  } else {
    packing_video_response = packing_video_response_create(
      "0",
      "0",
      1
    );
  }

  return packing_video_response;
}


#ifdef packing_video_response_MAIN

void test_packing_video_response(int include_optional) {
    packing_video_response_t* packing_video_response_1 = instantiate_packing_video_response(include_optional);

	cJSON* jsonpacking_video_response_1 = packing_video_response_convertToJSON(packing_video_response_1);
	printf("packing_video_response :\n%s\n", cJSON_Print(jsonpacking_video_response_1));
	packing_video_response_t* packing_video_response_2 = packing_video_response_parseFromJSON(jsonpacking_video_response_1);
	cJSON* jsonpacking_video_response_2 = packing_video_response_convertToJSON(packing_video_response_2);
	printf("repeating packing_video_response:\n%s\n", cJSON_Print(jsonpacking_video_response_2));
}

int main() {
  test_packing_video_response(1);
  test_packing_video_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // packing_video_response_MAIN
#endif // packing_video_response_TEST
