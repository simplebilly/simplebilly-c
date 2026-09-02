#ifndef feature_settings_TEST
#define feature_settings_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define feature_settings_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/feature_settings.h"
feature_settings_t* instantiate_feature_settings(int include_optional);



feature_settings_t* instantiate_feature_settings(int include_optional) {
  feature_settings_t* feature_settings = NULL;
  if (include_optional) {
    feature_settings = feature_settings_create(
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  } else {
    feature_settings = feature_settings_create(
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  }

  return feature_settings;
}


#ifdef feature_settings_MAIN

void test_feature_settings(int include_optional) {
    feature_settings_t* feature_settings_1 = instantiate_feature_settings(include_optional);

	cJSON* jsonfeature_settings_1 = feature_settings_convertToJSON(feature_settings_1);
	printf("feature_settings :\n%s\n", cJSON_Print(jsonfeature_settings_1));
	feature_settings_t* feature_settings_2 = feature_settings_parseFromJSON(jsonfeature_settings_1);
	cJSON* jsonfeature_settings_2 = feature_settings_convertToJSON(feature_settings_2);
	printf("repeating feature_settings:\n%s\n", cJSON_Print(jsonfeature_settings_2));
}

int main() {
  test_feature_settings(1);
  test_feature_settings(0);

  printf("Hello world \n");
  return 0;
}

#endif // feature_settings_MAIN
#endif // feature_settings_TEST
