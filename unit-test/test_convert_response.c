#ifndef convert_response_TEST
#define convert_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define convert_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/convert_response.h"
convert_response_t* instantiate_convert_response(int include_optional);



convert_response_t* instantiate_convert_response(int include_optional) {
  convert_response_t* convert_response = NULL;
  if (include_optional) {
    convert_response = convert_response_create(
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    convert_response = convert_response_create(
      "0",
      "0",
      "0",
      "0"
    );
  }

  return convert_response;
}


#ifdef convert_response_MAIN

void test_convert_response(int include_optional) {
    convert_response_t* convert_response_1 = instantiate_convert_response(include_optional);

	cJSON* jsonconvert_response_1 = convert_response_convertToJSON(convert_response_1);
	printf("convert_response :\n%s\n", cJSON_Print(jsonconvert_response_1));
	convert_response_t* convert_response_2 = convert_response_parseFromJSON(jsonconvert_response_1);
	cJSON* jsonconvert_response_2 = convert_response_convertToJSON(convert_response_2);
	printf("repeating convert_response:\n%s\n", cJSON_Print(jsonconvert_response_2));
}

int main() {
  test_convert_response(1);
  test_convert_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // convert_response_MAIN
#endif // convert_response_TEST
