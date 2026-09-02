#ifndef config_field_info_TEST
#define config_field_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define config_field_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/config_field_info.h"
config_field_info_t* instantiate_config_field_info(int include_optional);

#include "test_config_field_kind.c"


config_field_info_t* instantiate_config_field_info(int include_optional) {
  config_field_info_t* config_field_info = NULL;
  if (include_optional) {
    config_field_info = config_field_info_create(
      null,
      "0",
      "0",
      "0",
      1
    );
  } else {
    config_field_info = config_field_info_create(
      null,
      "0",
      "0",
      "0",
      1
    );
  }

  return config_field_info;
}


#ifdef config_field_info_MAIN

void test_config_field_info(int include_optional) {
    config_field_info_t* config_field_info_1 = instantiate_config_field_info(include_optional);

	cJSON* jsonconfig_field_info_1 = config_field_info_convertToJSON(config_field_info_1);
	printf("config_field_info :\n%s\n", cJSON_Print(jsonconfig_field_info_1));
	config_field_info_t* config_field_info_2 = config_field_info_parseFromJSON(jsonconfig_field_info_1);
	cJSON* jsonconfig_field_info_2 = config_field_info_convertToJSON(config_field_info_2);
	printf("repeating config_field_info:\n%s\n", cJSON_Print(jsonconfig_field_info_2));
}

int main() {
  test_config_field_info(1);
  test_config_field_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // config_field_info_MAIN
#endif // config_field_info_TEST
