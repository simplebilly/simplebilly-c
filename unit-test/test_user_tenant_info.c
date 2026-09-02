#ifndef user_tenant_info_TEST
#define user_tenant_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define user_tenant_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/user_tenant_info.h"
user_tenant_info_t* instantiate_user_tenant_info(int include_optional);



user_tenant_info_t* instantiate_user_tenant_info(int include_optional) {
  user_tenant_info_t* user_tenant_info = NULL;
  if (include_optional) {
    user_tenant_info = user_tenant_info_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    user_tenant_info = user_tenant_info_create(
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return user_tenant_info;
}


#ifdef user_tenant_info_MAIN

void test_user_tenant_info(int include_optional) {
    user_tenant_info_t* user_tenant_info_1 = instantiate_user_tenant_info(include_optional);

	cJSON* jsonuser_tenant_info_1 = user_tenant_info_convertToJSON(user_tenant_info_1);
	printf("user_tenant_info :\n%s\n", cJSON_Print(jsonuser_tenant_info_1));
	user_tenant_info_t* user_tenant_info_2 = user_tenant_info_parseFromJSON(jsonuser_tenant_info_1);
	cJSON* jsonuser_tenant_info_2 = user_tenant_info_convertToJSON(user_tenant_info_2);
	printf("repeating user_tenant_info:\n%s\n", cJSON_Print(jsonuser_tenant_info_2));
}

int main() {
  test_user_tenant_info(1);
  test_user_tenant_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // user_tenant_info_MAIN
#endif // user_tenant_info_TEST
