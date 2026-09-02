#ifndef tenant_user_TEST
#define tenant_user_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define tenant_user_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/tenant_user.h"
tenant_user_t* instantiate_tenant_user(int include_optional);



tenant_user_t* instantiate_tenant_user(int include_optional) {
  tenant_user_t* tenant_user = NULL;
  if (include_optional) {
    tenant_user = tenant_user_create(
      "0",
      1,
      1,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      list_createList(),
      "0",
      "0"
    );
  } else {
    tenant_user = tenant_user_create(
      "0",
      1,
      1,
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      list_createList(),
      "0",
      "0"
    );
  }

  return tenant_user;
}


#ifdef tenant_user_MAIN

void test_tenant_user(int include_optional) {
    tenant_user_t* tenant_user_1 = instantiate_tenant_user(include_optional);

	cJSON* jsontenant_user_1 = tenant_user_convertToJSON(tenant_user_1);
	printf("tenant_user :\n%s\n", cJSON_Print(jsontenant_user_1));
	tenant_user_t* tenant_user_2 = tenant_user_parseFromJSON(jsontenant_user_1);
	cJSON* jsontenant_user_2 = tenant_user_convertToJSON(tenant_user_2);
	printf("repeating tenant_user:\n%s\n", cJSON_Print(jsontenant_user_2));
}

int main() {
  test_tenant_user(1);
  test_tenant_user(0);

  printf("Hello world \n");
  return 0;
}

#endif // tenant_user_MAIN
#endif // tenant_user_TEST
