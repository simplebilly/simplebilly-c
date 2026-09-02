#ifndef gdpr_tenant_TEST
#define gdpr_tenant_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gdpr_tenant_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gdpr_tenant.h"
gdpr_tenant_t* instantiate_gdpr_tenant(int include_optional);



gdpr_tenant_t* instantiate_gdpr_tenant(int include_optional) {
  gdpr_tenant_t* gdpr_tenant = NULL;
  if (include_optional) {
    gdpr_tenant = gdpr_tenant_create(
      "0",
      "0",
      "0"
    );
  } else {
    gdpr_tenant = gdpr_tenant_create(
      "0",
      "0",
      "0"
    );
  }

  return gdpr_tenant;
}


#ifdef gdpr_tenant_MAIN

void test_gdpr_tenant(int include_optional) {
    gdpr_tenant_t* gdpr_tenant_1 = instantiate_gdpr_tenant(include_optional);

	cJSON* jsongdpr_tenant_1 = gdpr_tenant_convertToJSON(gdpr_tenant_1);
	printf("gdpr_tenant :\n%s\n", cJSON_Print(jsongdpr_tenant_1));
	gdpr_tenant_t* gdpr_tenant_2 = gdpr_tenant_parseFromJSON(jsongdpr_tenant_1);
	cJSON* jsongdpr_tenant_2 = gdpr_tenant_convertToJSON(gdpr_tenant_2);
	printf("repeating gdpr_tenant:\n%s\n", cJSON_Print(jsongdpr_tenant_2));
}

int main() {
  test_gdpr_tenant(1);
  test_gdpr_tenant(0);

  printf("Hello world \n");
  return 0;
}

#endif // gdpr_tenant_MAIN
#endif // gdpr_tenant_TEST
