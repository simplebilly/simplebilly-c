#ifndef config_field_kind_one_of_TEST
#define config_field_kind_one_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define config_field_kind_one_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/config_field_kind_one_of.h"
config_field_kind_one_of_t* instantiate_config_field_kind_one_of(int include_optional);



config_field_kind_one_of_t* instantiate_config_field_kind_one_of(int include_optional) {
  config_field_kind_one_of_t* config_field_kind_one_of = NULL;
  if (include_optional) {
    config_field_kind_one_of = config_field_kind_one_of_create(
      simplebilly_api_config_field_kind_one_of_TYPE_text
    );
  } else {
    config_field_kind_one_of = config_field_kind_one_of_create(
      simplebilly_api_config_field_kind_one_of_TYPE_text
    );
  }

  return config_field_kind_one_of;
}


#ifdef config_field_kind_one_of_MAIN

void test_config_field_kind_one_of(int include_optional) {
    config_field_kind_one_of_t* config_field_kind_one_of_1 = instantiate_config_field_kind_one_of(include_optional);

	cJSON* jsonconfig_field_kind_one_of_1 = config_field_kind_one_of_convertToJSON(config_field_kind_one_of_1);
	printf("config_field_kind_one_of :\n%s\n", cJSON_Print(jsonconfig_field_kind_one_of_1));
	config_field_kind_one_of_t* config_field_kind_one_of_2 = config_field_kind_one_of_parseFromJSON(jsonconfig_field_kind_one_of_1);
	cJSON* jsonconfig_field_kind_one_of_2 = config_field_kind_one_of_convertToJSON(config_field_kind_one_of_2);
	printf("repeating config_field_kind_one_of:\n%s\n", cJSON_Print(jsonconfig_field_kind_one_of_2));
}

int main() {
  test_config_field_kind_one_of(1);
  test_config_field_kind_one_of(0);

  printf("Hello world \n");
  return 0;
}

#endif // config_field_kind_one_of_MAIN
#endif // config_field_kind_one_of_TEST
