#ifndef api_response_gdpr_export_data_TEST
#define api_response_gdpr_export_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define api_response_gdpr_export_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/api_response_gdpr_export_data.h"
api_response_gdpr_export_data_t* instantiate_api_response_gdpr_export_data(int include_optional);

#include "test_gdpr_user.c"


api_response_gdpr_export_data_t* instantiate_api_response_gdpr_export_data(int include_optional) {
  api_response_gdpr_export_data_t* api_response_gdpr_export_data = NULL;
  if (include_optional) {
    api_response_gdpr_export_data = api_response_gdpr_export_data_create(
      list_createList(),
      list_createList(),
      list_createList(),
      "2013-10-20T19:20:30+01:00",
      1,
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
       // false, not to have infinite recursion
      instantiate_gdpr_user(0)
    );
  } else {
    api_response_gdpr_export_data = api_response_gdpr_export_data_create(
      list_createList(),
      list_createList(),
      list_createList(),
      "2013-10-20T19:20:30+01:00",
      1,
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      NULL
    );
  }

  return api_response_gdpr_export_data;
}


#ifdef api_response_gdpr_export_data_MAIN

void test_api_response_gdpr_export_data(int include_optional) {
    api_response_gdpr_export_data_t* api_response_gdpr_export_data_1 = instantiate_api_response_gdpr_export_data(include_optional);

	cJSON* jsonapi_response_gdpr_export_data_1 = api_response_gdpr_export_data_convertToJSON(api_response_gdpr_export_data_1);
	printf("api_response_gdpr_export_data :\n%s\n", cJSON_Print(jsonapi_response_gdpr_export_data_1));
	api_response_gdpr_export_data_t* api_response_gdpr_export_data_2 = api_response_gdpr_export_data_parseFromJSON(jsonapi_response_gdpr_export_data_1);
	cJSON* jsonapi_response_gdpr_export_data_2 = api_response_gdpr_export_data_convertToJSON(api_response_gdpr_export_data_2);
	printf("repeating api_response_gdpr_export_data:\n%s\n", cJSON_Print(jsonapi_response_gdpr_export_data_2));
}

int main() {
  test_api_response_gdpr_export_data(1);
  test_api_response_gdpr_export_data(0);

  printf("Hello world \n");
  return 0;
}

#endif // api_response_gdpr_export_data_MAIN
#endif // api_response_gdpr_export_data_TEST
