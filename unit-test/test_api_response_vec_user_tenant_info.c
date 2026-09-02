#ifndef api_response_vec_user_tenant_info_TEST
#define api_response_vec_user_tenant_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define api_response_vec_user_tenant_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/api_response_vec_user_tenant_info.h"
api_response_vec_user_tenant_info_t* instantiate_api_response_vec_user_tenant_info(int include_optional);



api_response_vec_user_tenant_info_t* instantiate_api_response_vec_user_tenant_info(int include_optional) {
  api_response_vec_user_tenant_info_t* api_response_vec_user_tenant_info = NULL;
  if (include_optional) {
    api_response_vec_user_tenant_info = api_response_vec_user_tenant_info_create(
      list_createList(),
      "0",
      "0",
      1
    );
  } else {
    api_response_vec_user_tenant_info = api_response_vec_user_tenant_info_create(
      list_createList(),
      "0",
      "0",
      1
    );
  }

  return api_response_vec_user_tenant_info;
}


#ifdef api_response_vec_user_tenant_info_MAIN

void test_api_response_vec_user_tenant_info(int include_optional) {
    api_response_vec_user_tenant_info_t* api_response_vec_user_tenant_info_1 = instantiate_api_response_vec_user_tenant_info(include_optional);

	cJSON* jsonapi_response_vec_user_tenant_info_1 = api_response_vec_user_tenant_info_convertToJSON(api_response_vec_user_tenant_info_1);
	printf("api_response_vec_user_tenant_info :\n%s\n", cJSON_Print(jsonapi_response_vec_user_tenant_info_1));
	api_response_vec_user_tenant_info_t* api_response_vec_user_tenant_info_2 = api_response_vec_user_tenant_info_parseFromJSON(jsonapi_response_vec_user_tenant_info_1);
	cJSON* jsonapi_response_vec_user_tenant_info_2 = api_response_vec_user_tenant_info_convertToJSON(api_response_vec_user_tenant_info_2);
	printf("repeating api_response_vec_user_tenant_info:\n%s\n", cJSON_Print(jsonapi_response_vec_user_tenant_info_2));
}

int main() {
  test_api_response_vec_user_tenant_info(1);
  test_api_response_vec_user_tenant_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // api_response_vec_user_tenant_info_MAIN
#endif // api_response_vec_user_tenant_info_TEST
