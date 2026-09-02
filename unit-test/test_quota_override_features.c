#ifndef quota_override_features_TEST
#define quota_override_features_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define quota_override_features_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/quota_override_features.h"
quota_override_features_t* instantiate_quota_override_features(int include_optional);



quota_override_features_t* instantiate_quota_override_features(int include_optional) {
  quota_override_features_t* quota_override_features = NULL;
  if (include_optional) {
    quota_override_features = quota_override_features_create(
      1,
      1,
      1
    );
  } else {
    quota_override_features = quota_override_features_create(
      1,
      1,
      1
    );
  }

  return quota_override_features;
}


#ifdef quota_override_features_MAIN

void test_quota_override_features(int include_optional) {
    quota_override_features_t* quota_override_features_1 = instantiate_quota_override_features(include_optional);

	cJSON* jsonquota_override_features_1 = quota_override_features_convertToJSON(quota_override_features_1);
	printf("quota_override_features :\n%s\n", cJSON_Print(jsonquota_override_features_1));
	quota_override_features_t* quota_override_features_2 = quota_override_features_parseFromJSON(jsonquota_override_features_1);
	cJSON* jsonquota_override_features_2 = quota_override_features_convertToJSON(quota_override_features_2);
	printf("repeating quota_override_features:\n%s\n", cJSON_Print(jsonquota_override_features_2));
}

int main() {
  test_quota_override_features(1);
  test_quota_override_features(0);

  printf("Hello world \n");
  return 0;
}

#endif // quota_override_features_MAIN
#endif // quota_override_features_TEST
