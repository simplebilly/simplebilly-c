#ifndef plugin_error_one_of_TEST
#define plugin_error_one_of_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define plugin_error_one_of_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/plugin_error_one_of.h"
plugin_error_one_of_t* instantiate_plugin_error_one_of(int include_optional);



plugin_error_one_of_t* instantiate_plugin_error_one_of(int include_optional) {
  plugin_error_one_of_t* plugin_error_one_of = NULL;
  if (include_optional) {
    plugin_error_one_of = plugin_error_one_of_create(
      list_createList()
    );
  } else {
    plugin_error_one_of = plugin_error_one_of_create(
      list_createList()
    );
  }

  return plugin_error_one_of;
}


#ifdef plugin_error_one_of_MAIN

void test_plugin_error_one_of(int include_optional) {
    plugin_error_one_of_t* plugin_error_one_of_1 = instantiate_plugin_error_one_of(include_optional);

	cJSON* jsonplugin_error_one_of_1 = plugin_error_one_of_convertToJSON(plugin_error_one_of_1);
	printf("plugin_error_one_of :\n%s\n", cJSON_Print(jsonplugin_error_one_of_1));
	plugin_error_one_of_t* plugin_error_one_of_2 = plugin_error_one_of_parseFromJSON(jsonplugin_error_one_of_1);
	cJSON* jsonplugin_error_one_of_2 = plugin_error_one_of_convertToJSON(plugin_error_one_of_2);
	printf("repeating plugin_error_one_of:\n%s\n", cJSON_Print(jsonplugin_error_one_of_2));
}

int main() {
  test_plugin_error_one_of(1);
  test_plugin_error_one_of(0);

  printf("Hello world \n");
  return 0;
}

#endif // plugin_error_one_of_MAIN
#endif // plugin_error_one_of_TEST
