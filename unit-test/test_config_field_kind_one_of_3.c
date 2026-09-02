#ifndef config_field_kind_one_of_3_TEST
#define config_field_kind_one_of_3_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define config_field_kind_one_of_3_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/config_field_kind_one_of_3.h"
config_field_kind_one_of_3_t* instantiate_config_field_kind_one_of_3(int include_optional);



config_field_kind_one_of_3_t* instantiate_config_field_kind_one_of_3(int include_optional) {
  config_field_kind_one_of_3_t* config_field_kind_one_of_3 = NULL;
  if (include_optional) {
    config_field_kind_one_of_3 = config_field_kind_one_of_3_create(
      list_createList(),
      simplebilly_api_config_field_kind_one_of_3_TYPE_select
    );
  } else {
    config_field_kind_one_of_3 = config_field_kind_one_of_3_create(
      list_createList(),
      simplebilly_api_config_field_kind_one_of_3_TYPE_select
    );
  }

  return config_field_kind_one_of_3;
}


#ifdef config_field_kind_one_of_3_MAIN

void test_config_field_kind_one_of_3(int include_optional) {
    config_field_kind_one_of_3_t* config_field_kind_one_of_3_1 = instantiate_config_field_kind_one_of_3(include_optional);

	cJSON* jsonconfig_field_kind_one_of_3_1 = config_field_kind_one_of_3_convertToJSON(config_field_kind_one_of_3_1);
	printf("config_field_kind_one_of_3 :\n%s\n", cJSON_Print(jsonconfig_field_kind_one_of_3_1));
	config_field_kind_one_of_3_t* config_field_kind_one_of_3_2 = config_field_kind_one_of_3_parseFromJSON(jsonconfig_field_kind_one_of_3_1);
	cJSON* jsonconfig_field_kind_one_of_3_2 = config_field_kind_one_of_3_convertToJSON(config_field_kind_one_of_3_2);
	printf("repeating config_field_kind_one_of_3:\n%s\n", cJSON_Print(jsonconfig_field_kind_one_of_3_2));
}

int main() {
  test_config_field_kind_one_of_3(1);
  test_config_field_kind_one_of_3(0);

  printf("Hello world \n");
  return 0;
}

#endif // config_field_kind_one_of_3_MAIN
#endif // config_field_kind_one_of_3_TEST
