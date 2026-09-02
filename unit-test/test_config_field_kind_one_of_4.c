#ifndef config_field_kind_one_of_4_TEST
#define config_field_kind_one_of_4_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define config_field_kind_one_of_4_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/config_field_kind_one_of_4.h"
config_field_kind_one_of_4_t* instantiate_config_field_kind_one_of_4(int include_optional);



config_field_kind_one_of_4_t* instantiate_config_field_kind_one_of_4(int include_optional) {
  config_field_kind_one_of_4_t* config_field_kind_one_of_4 = NULL;
  if (include_optional) {
    config_field_kind_one_of_4 = config_field_kind_one_of_4_create(
      simplebilly_api_config_field_kind_one_of_4_TYPE_bool
    );
  } else {
    config_field_kind_one_of_4 = config_field_kind_one_of_4_create(
      simplebilly_api_config_field_kind_one_of_4_TYPE_bool
    );
  }

  return config_field_kind_one_of_4;
}


#ifdef config_field_kind_one_of_4_MAIN

void test_config_field_kind_one_of_4(int include_optional) {
    config_field_kind_one_of_4_t* config_field_kind_one_of_4_1 = instantiate_config_field_kind_one_of_4(include_optional);

	cJSON* jsonconfig_field_kind_one_of_4_1 = config_field_kind_one_of_4_convertToJSON(config_field_kind_one_of_4_1);
	printf("config_field_kind_one_of_4 :\n%s\n", cJSON_Print(jsonconfig_field_kind_one_of_4_1));
	config_field_kind_one_of_4_t* config_field_kind_one_of_4_2 = config_field_kind_one_of_4_parseFromJSON(jsonconfig_field_kind_one_of_4_1);
	cJSON* jsonconfig_field_kind_one_of_4_2 = config_field_kind_one_of_4_convertToJSON(config_field_kind_one_of_4_2);
	printf("repeating config_field_kind_one_of_4:\n%s\n", cJSON_Print(jsonconfig_field_kind_one_of_4_2));
}

int main() {
  test_config_field_kind_one_of_4(1);
  test_config_field_kind_one_of_4(0);

  printf("Hello world \n");
  return 0;
}

#endif // config_field_kind_one_of_4_MAIN
#endif // config_field_kind_one_of_4_TEST
