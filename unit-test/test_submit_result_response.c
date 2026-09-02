#ifndef submit_result_response_TEST
#define submit_result_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define submit_result_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/submit_result_response.h"
submit_result_response_t* instantiate_submit_result_response(int include_optional);



submit_result_response_t* instantiate_submit_result_response(int include_optional) {
  submit_result_response_t* submit_result_response = NULL;
  if (include_optional) {
    submit_result_response = submit_result_response_create(
      "0",
      "0",
      56,
      1,
      56,
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    submit_result_response = submit_result_response_create(
      "0",
      "0",
      56,
      1,
      56,
      "2013-10-20T19:20:30+01:00"
    );
  }

  return submit_result_response;
}


#ifdef submit_result_response_MAIN

void test_submit_result_response(int include_optional) {
    submit_result_response_t* submit_result_response_1 = instantiate_submit_result_response(include_optional);

	cJSON* jsonsubmit_result_response_1 = submit_result_response_convertToJSON(submit_result_response_1);
	printf("submit_result_response :\n%s\n", cJSON_Print(jsonsubmit_result_response_1));
	submit_result_response_t* submit_result_response_2 = submit_result_response_parseFromJSON(jsonsubmit_result_response_1);
	cJSON* jsonsubmit_result_response_2 = submit_result_response_convertToJSON(submit_result_response_2);
	printf("repeating submit_result_response:\n%s\n", cJSON_Print(jsonsubmit_result_response_2));
}

int main() {
  test_submit_result_response(1);
  test_submit_result_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // submit_result_response_MAIN
#endif // submit_result_response_TEST
