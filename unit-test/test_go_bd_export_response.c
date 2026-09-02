#ifndef go_bd_export_response_TEST
#define go_bd_export_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define go_bd_export_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/go_bd_export_response.h"
go_bd_export_response_t* instantiate_go_bd_export_response(int include_optional);



go_bd_export_response_t* instantiate_go_bd_export_response(int include_optional) {
  go_bd_export_response_t* go_bd_export_response = NULL;
  if (include_optional) {
    go_bd_export_response = go_bd_export_response_create(
      0,
      "0",
      "0"
    );
  } else {
    go_bd_export_response = go_bd_export_response_create(
      0,
      "0",
      "0"
    );
  }

  return go_bd_export_response;
}


#ifdef go_bd_export_response_MAIN

void test_go_bd_export_response(int include_optional) {
    go_bd_export_response_t* go_bd_export_response_1 = instantiate_go_bd_export_response(include_optional);

	cJSON* jsongo_bd_export_response_1 = go_bd_export_response_convertToJSON(go_bd_export_response_1);
	printf("go_bd_export_response :\n%s\n", cJSON_Print(jsongo_bd_export_response_1));
	go_bd_export_response_t* go_bd_export_response_2 = go_bd_export_response_parseFromJSON(jsongo_bd_export_response_1);
	cJSON* jsongo_bd_export_response_2 = go_bd_export_response_convertToJSON(go_bd_export_response_2);
	printf("repeating go_bd_export_response:\n%s\n", cJSON_Print(jsongo_bd_export_response_2));
}

int main() {
  test_go_bd_export_response(1);
  test_go_bd_export_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // go_bd_export_response_MAIN
#endif // go_bd_export_response_TEST
