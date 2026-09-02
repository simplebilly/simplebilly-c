#ifndef konzern_export_response_TEST
#define konzern_export_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define konzern_export_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/konzern_export_response.h"
konzern_export_response_t* instantiate_konzern_export_response(int include_optional);



konzern_export_response_t* instantiate_konzern_export_response(int include_optional) {
  konzern_export_response_t* konzern_export_response = NULL;
  if (include_optional) {
    konzern_export_response = konzern_export_response_create(
      "0",
      "0"
    );
  } else {
    konzern_export_response = konzern_export_response_create(
      "0",
      "0"
    );
  }

  return konzern_export_response;
}


#ifdef konzern_export_response_MAIN

void test_konzern_export_response(int include_optional) {
    konzern_export_response_t* konzern_export_response_1 = instantiate_konzern_export_response(include_optional);

	cJSON* jsonkonzern_export_response_1 = konzern_export_response_convertToJSON(konzern_export_response_1);
	printf("konzern_export_response :\n%s\n", cJSON_Print(jsonkonzern_export_response_1));
	konzern_export_response_t* konzern_export_response_2 = konzern_export_response_parseFromJSON(jsonkonzern_export_response_1);
	cJSON* jsonkonzern_export_response_2 = konzern_export_response_convertToJSON(konzern_export_response_2);
	printf("repeating konzern_export_response:\n%s\n", cJSON_Print(jsonkonzern_export_response_2));
}

int main() {
  test_konzern_export_response(1);
  test_konzern_export_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // konzern_export_response_MAIN
#endif // konzern_export_response_TEST
