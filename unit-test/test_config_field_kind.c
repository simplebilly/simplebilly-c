#ifndef config_field_kind_TEST
#define config_field_kind_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define config_field_kind_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/config_field_kind.h"
config_field_kind_t* instantiate_config_field_kind(int include_optional);



config_field_kind_t* instantiate_config_field_kind(int include_optional) {
  config_field_kind_t* config_field_kind = NULL;
  if (include_optional) {
    config_field_kind = config_field_kind_create(
      simplebilly_api_config_field_kind_TYPE_text,
      list_createList()
    );
  } else {
    config_field_kind = config_field_kind_create(
      simplebilly_api_config_field_kind_TYPE_text,
      list_createList()
    );
  }

  return config_field_kind;
}


#ifdef config_field_kind_MAIN

void test_config_field_kind(int include_optional) {
    config_field_kind_t* config_field_kind_1 = instantiate_config_field_kind(include_optional);

	cJSON* jsonconfig_field_kind_1 = config_field_kind_convertToJSON(config_field_kind_1);
	printf("config_field_kind :\n%s\n", cJSON_Print(jsonconfig_field_kind_1));
	config_field_kind_t* config_field_kind_2 = config_field_kind_parseFromJSON(jsonconfig_field_kind_1);
	cJSON* jsonconfig_field_kind_2 = config_field_kind_convertToJSON(config_field_kind_2);
	printf("repeating config_field_kind:\n%s\n", cJSON_Print(jsonconfig_field_kind_2));
}

int main() {
  test_config_field_kind(1);
  test_config_field_kind(0);

  printf("Hello world \n");
  return 0;
}

#endif // config_field_kind_MAIN
#endif // config_field_kind_TEST
