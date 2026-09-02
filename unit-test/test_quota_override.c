#ifndef quota_override_TEST
#define quota_override_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define quota_override_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/quota_override.h"
quota_override_t* instantiate_quota_override(int include_optional);

#include "test_quota_override_features.c"


quota_override_t* instantiate_quota_override(int include_optional) {
  quota_override_t* quota_override = NULL;
  if (include_optional) {
    quota_override = quota_override_create(
       // false, not to have infinite recursion
      instantiate_quota_override_features(0),
      56,
      56,
      56,
      list_createList(),
      "0"
    );
  } else {
    quota_override = quota_override_create(
      NULL,
      56,
      56,
      56,
      list_createList(),
      "0"
    );
  }

  return quota_override;
}


#ifdef quota_override_MAIN

void test_quota_override(int include_optional) {
    quota_override_t* quota_override_1 = instantiate_quota_override(include_optional);

	cJSON* jsonquota_override_1 = quota_override_convertToJSON(quota_override_1);
	printf("quota_override :\n%s\n", cJSON_Print(jsonquota_override_1));
	quota_override_t* quota_override_2 = quota_override_parseFromJSON(jsonquota_override_1);
	cJSON* jsonquota_override_2 = quota_override_convertToJSON(quota_override_2);
	printf("repeating quota_override:\n%s\n", cJSON_Print(jsonquota_override_2));
}

int main() {
  test_quota_override(1);
  test_quota_override(0);

  printf("Hello world \n");
  return 0;
}

#endif // quota_override_MAIN
#endif // quota_override_TEST
