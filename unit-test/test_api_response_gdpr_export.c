#ifndef api_response_gdpr_export_TEST
#define api_response_gdpr_export_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define api_response_gdpr_export_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/api_response_gdpr_export.h"
api_response_gdpr_export_t* instantiate_api_response_gdpr_export(int include_optional);

#include "test_api_response_gdpr_export_data.c"


api_response_gdpr_export_t* instantiate_api_response_gdpr_export(int include_optional) {
  api_response_gdpr_export_t* api_response_gdpr_export = NULL;
  if (include_optional) {
    api_response_gdpr_export = api_response_gdpr_export_create(
       // false, not to have infinite recursion
      instantiate_api_response_gdpr_export_data(0),
      "0",
      "0",
      1
    );
  } else {
    api_response_gdpr_export = api_response_gdpr_export_create(
      NULL,
      "0",
      "0",
      1
    );
  }

  return api_response_gdpr_export;
}


#ifdef api_response_gdpr_export_MAIN

void test_api_response_gdpr_export(int include_optional) {
    api_response_gdpr_export_t* api_response_gdpr_export_1 = instantiate_api_response_gdpr_export(include_optional);

	cJSON* jsonapi_response_gdpr_export_1 = api_response_gdpr_export_convertToJSON(api_response_gdpr_export_1);
	printf("api_response_gdpr_export :\n%s\n", cJSON_Print(jsonapi_response_gdpr_export_1));
	api_response_gdpr_export_t* api_response_gdpr_export_2 = api_response_gdpr_export_parseFromJSON(jsonapi_response_gdpr_export_1);
	cJSON* jsonapi_response_gdpr_export_2 = api_response_gdpr_export_convertToJSON(api_response_gdpr_export_2);
	printf("repeating api_response_gdpr_export:\n%s\n", cJSON_Print(jsonapi_response_gdpr_export_2));
}

int main() {
  test_api_response_gdpr_export(1);
  test_api_response_gdpr_export(0);

  printf("Hello world \n");
  return 0;
}

#endif // api_response_gdpr_export_MAIN
#endif // api_response_gdpr_export_TEST
