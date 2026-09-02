#ifndef tenant_settings_TEST
#define tenant_settings_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define tenant_settings_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/tenant_settings.h"
tenant_settings_t* instantiate_tenant_settings(int include_optional);



tenant_settings_t* instantiate_tenant_settings(int include_optional) {
  tenant_settings_t* tenant_settings = NULL;
  if (include_optional) {
    tenant_settings = tenant_settings_create(
      simplebilly_api_tenant_settings__gmbh,
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      null
    );
  } else {
    tenant_settings = tenant_settings_create(
      simplebilly_api_tenant_settings__gmbh,
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      null
    );
  }

  return tenant_settings;
}


#ifdef tenant_settings_MAIN

void test_tenant_settings(int include_optional) {
    tenant_settings_t* tenant_settings_1 = instantiate_tenant_settings(include_optional);

	cJSON* jsontenant_settings_1 = tenant_settings_convertToJSON(tenant_settings_1);
	printf("tenant_settings :\n%s\n", cJSON_Print(jsontenant_settings_1));
	tenant_settings_t* tenant_settings_2 = tenant_settings_parseFromJSON(jsontenant_settings_1);
	cJSON* jsontenant_settings_2 = tenant_settings_convertToJSON(tenant_settings_2);
	printf("repeating tenant_settings:\n%s\n", cJSON_Print(jsontenant_settings_2));
}

int main() {
  test_tenant_settings(1);
  test_tenant_settings(0);

  printf("Hello world \n");
  return 0;
}

#endif // tenant_settings_MAIN
#endif // tenant_settings_TEST
