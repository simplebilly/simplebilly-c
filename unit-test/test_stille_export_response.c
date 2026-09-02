#ifndef stille_export_response_TEST
#define stille_export_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define stille_export_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/stille_export_response.h"
stille_export_response_t* instantiate_stille_export_response(int include_optional);



stille_export_response_t* instantiate_stille_export_response(int include_optional) {
  stille_export_response_t* stille_export_response = NULL;
  if (include_optional) {
    stille_export_response = stille_export_response_create(
      "0",
      "0"
    );
  } else {
    stille_export_response = stille_export_response_create(
      "0",
      "0"
    );
  }

  return stille_export_response;
}


#ifdef stille_export_response_MAIN

void test_stille_export_response(int include_optional) {
    stille_export_response_t* stille_export_response_1 = instantiate_stille_export_response(include_optional);

	cJSON* jsonstille_export_response_1 = stille_export_response_convertToJSON(stille_export_response_1);
	printf("stille_export_response :\n%s\n", cJSON_Print(jsonstille_export_response_1));
	stille_export_response_t* stille_export_response_2 = stille_export_response_parseFromJSON(jsonstille_export_response_1);
	cJSON* jsonstille_export_response_2 = stille_export_response_convertToJSON(stille_export_response_2);
	printf("repeating stille_export_response:\n%s\n", cJSON_Print(jsonstille_export_response_2));
}

int main() {
  test_stille_export_response(1);
  test_stille_export_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // stille_export_response_MAIN
#endif // stille_export_response_TEST
