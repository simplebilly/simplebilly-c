#ifndef config_field_kind_one_of_2_TEST
#define config_field_kind_one_of_2_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define config_field_kind_one_of_2_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/config_field_kind_one_of_2.h"
config_field_kind_one_of_2_t* instantiate_config_field_kind_one_of_2(int include_optional);



config_field_kind_one_of_2_t* instantiate_config_field_kind_one_of_2(int include_optional) {
  config_field_kind_one_of_2_t* config_field_kind_one_of_2 = NULL;
  if (include_optional) {
    config_field_kind_one_of_2 = config_field_kind_one_of_2_create(
      simplebilly_api_config_field_kind_one_of_2_TYPE_url
    );
  } else {
    config_field_kind_one_of_2 = config_field_kind_one_of_2_create(
      simplebilly_api_config_field_kind_one_of_2_TYPE_url
    );
  }

  return config_field_kind_one_of_2;
}


#ifdef config_field_kind_one_of_2_MAIN

void test_config_field_kind_one_of_2(int include_optional) {
    config_field_kind_one_of_2_t* config_field_kind_one_of_2_1 = instantiate_config_field_kind_one_of_2(include_optional);

	cJSON* jsonconfig_field_kind_one_of_2_1 = config_field_kind_one_of_2_convertToJSON(config_field_kind_one_of_2_1);
	printf("config_field_kind_one_of_2 :\n%s\n", cJSON_Print(jsonconfig_field_kind_one_of_2_1));
	config_field_kind_one_of_2_t* config_field_kind_one_of_2_2 = config_field_kind_one_of_2_parseFromJSON(jsonconfig_field_kind_one_of_2_1);
	cJSON* jsonconfig_field_kind_one_of_2_2 = config_field_kind_one_of_2_convertToJSON(config_field_kind_one_of_2_2);
	printf("repeating config_field_kind_one_of_2:\n%s\n", cJSON_Print(jsonconfig_field_kind_one_of_2_2));
}

int main() {
  test_config_field_kind_one_of_2(1);
  test_config_field_kind_one_of_2(0);

  printf("Hello world \n");
  return 0;
}

#endif // config_field_kind_one_of_2_MAIN
#endif // config_field_kind_one_of_2_TEST
