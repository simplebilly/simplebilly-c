#ifndef config_field_kind_one_of_1_TEST
#define config_field_kind_one_of_1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define config_field_kind_one_of_1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/config_field_kind_one_of_1.h"
config_field_kind_one_of_1_t* instantiate_config_field_kind_one_of_1(int include_optional);



config_field_kind_one_of_1_t* instantiate_config_field_kind_one_of_1(int include_optional) {
  config_field_kind_one_of_1_t* config_field_kind_one_of_1 = NULL;
  if (include_optional) {
    config_field_kind_one_of_1 = config_field_kind_one_of_1_create(
      simplebilly_api_config_field_kind_one_of_1_TYPE_secret
    );
  } else {
    config_field_kind_one_of_1 = config_field_kind_one_of_1_create(
      simplebilly_api_config_field_kind_one_of_1_TYPE_secret
    );
  }

  return config_field_kind_one_of_1;
}


#ifdef config_field_kind_one_of_1_MAIN

void test_config_field_kind_one_of_1(int include_optional) {
    config_field_kind_one_of_1_t* config_field_kind_one_of_1_1 = instantiate_config_field_kind_one_of_1(include_optional);

	cJSON* jsonconfig_field_kind_one_of_1_1 = config_field_kind_one_of_1_convertToJSON(config_field_kind_one_of_1_1);
	printf("config_field_kind_one_of_1 :\n%s\n", cJSON_Print(jsonconfig_field_kind_one_of_1_1));
	config_field_kind_one_of_1_t* config_field_kind_one_of_1_2 = config_field_kind_one_of_1_parseFromJSON(jsonconfig_field_kind_one_of_1_1);
	cJSON* jsonconfig_field_kind_one_of_1_2 = config_field_kind_one_of_1_convertToJSON(config_field_kind_one_of_1_2);
	printf("repeating config_field_kind_one_of_1:\n%s\n", cJSON_Print(jsonconfig_field_kind_one_of_1_2));
}

int main() {
  test_config_field_kind_one_of_1(1);
  test_config_field_kind_one_of_1(0);

  printf("Hello world \n");
  return 0;
}

#endif // config_field_kind_one_of_1_MAIN
#endif // config_field_kind_one_of_1_TEST
