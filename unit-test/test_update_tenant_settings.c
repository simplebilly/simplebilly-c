#ifndef update_tenant_settings_TEST
#define update_tenant_settings_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_tenant_settings_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_tenant_settings.h"
update_tenant_settings_t* instantiate_update_tenant_settings(int include_optional);

#include "test_partial_feature_settings.c"


update_tenant_settings_t* instantiate_update_tenant_settings(int include_optional) {
  update_tenant_settings_t* update_tenant_settings = NULL;
  if (include_optional) {
    update_tenant_settings = update_tenant_settings_create(
      simplebilly_api_update_tenant_settings__gmbh,
       // false, not to have infinite recursion
      instantiate_partial_feature_settings(0)
    );
  } else {
    update_tenant_settings = update_tenant_settings_create(
      simplebilly_api_update_tenant_settings__gmbh,
      NULL
    );
  }

  return update_tenant_settings;
}


#ifdef update_tenant_settings_MAIN

void test_update_tenant_settings(int include_optional) {
    update_tenant_settings_t* update_tenant_settings_1 = instantiate_update_tenant_settings(include_optional);

	cJSON* jsonupdate_tenant_settings_1 = update_tenant_settings_convertToJSON(update_tenant_settings_1);
	printf("update_tenant_settings :\n%s\n", cJSON_Print(jsonupdate_tenant_settings_1));
	update_tenant_settings_t* update_tenant_settings_2 = update_tenant_settings_parseFromJSON(jsonupdate_tenant_settings_1);
	cJSON* jsonupdate_tenant_settings_2 = update_tenant_settings_convertToJSON(update_tenant_settings_2);
	printf("repeating update_tenant_settings:\n%s\n", cJSON_Print(jsonupdate_tenant_settings_2));
}

int main() {
  test_update_tenant_settings(1);
  test_update_tenant_settings(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_tenant_settings_MAIN
#endif // update_tenant_settings_TEST
