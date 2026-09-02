#ifndef partial_feature_settings_TEST
#define partial_feature_settings_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define partial_feature_settings_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/partial_feature_settings.h"
partial_feature_settings_t* instantiate_partial_feature_settings(int include_optional);



partial_feature_settings_t* instantiate_partial_feature_settings(int include_optional) {
  partial_feature_settings_t* partial_feature_settings = NULL;
  if (include_optional) {
    partial_feature_settings = partial_feature_settings_create(
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
    partial_feature_settings = partial_feature_settings_create(
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

  return partial_feature_settings;
}


#ifdef partial_feature_settings_MAIN

void test_partial_feature_settings(int include_optional) {
    partial_feature_settings_t* partial_feature_settings_1 = instantiate_partial_feature_settings(include_optional);

	cJSON* jsonpartial_feature_settings_1 = partial_feature_settings_convertToJSON(partial_feature_settings_1);
	printf("partial_feature_settings :\n%s\n", cJSON_Print(jsonpartial_feature_settings_1));
	partial_feature_settings_t* partial_feature_settings_2 = partial_feature_settings_parseFromJSON(jsonpartial_feature_settings_1);
	cJSON* jsonpartial_feature_settings_2 = partial_feature_settings_convertToJSON(partial_feature_settings_2);
	printf("repeating partial_feature_settings:\n%s\n", cJSON_Print(jsonpartial_feature_settings_2));
}

int main() {
  test_partial_feature_settings(1);
  test_partial_feature_settings(0);

  printf("Hello world \n");
  return 0;
}

#endif // partial_feature_settings_MAIN
#endif // partial_feature_settings_TEST
