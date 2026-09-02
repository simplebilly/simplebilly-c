#ifndef plugin_error_one_of_4_TEST
#define plugin_error_one_of_4_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define plugin_error_one_of_4_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/plugin_error_one_of_4.h"
plugin_error_one_of_4_t* instantiate_plugin_error_one_of_4(int include_optional);



plugin_error_one_of_4_t* instantiate_plugin_error_one_of_4(int include_optional) {
  plugin_error_one_of_4_t* plugin_error_one_of_4 = NULL;
  if (include_optional) {
    plugin_error_one_of_4 = plugin_error_one_of_4_create(
      list_createList()
    );
  } else {
    plugin_error_one_of_4 = plugin_error_one_of_4_create(
      list_createList()
    );
  }

  return plugin_error_one_of_4;
}


#ifdef plugin_error_one_of_4_MAIN

void test_plugin_error_one_of_4(int include_optional) {
    plugin_error_one_of_4_t* plugin_error_one_of_4_1 = instantiate_plugin_error_one_of_4(include_optional);

	cJSON* jsonplugin_error_one_of_4_1 = plugin_error_one_of_4_convertToJSON(plugin_error_one_of_4_1);
	printf("plugin_error_one_of_4 :\n%s\n", cJSON_Print(jsonplugin_error_one_of_4_1));
	plugin_error_one_of_4_t* plugin_error_one_of_4_2 = plugin_error_one_of_4_parseFromJSON(jsonplugin_error_one_of_4_1);
	cJSON* jsonplugin_error_one_of_4_2 = plugin_error_one_of_4_convertToJSON(plugin_error_one_of_4_2);
	printf("repeating plugin_error_one_of_4:\n%s\n", cJSON_Print(jsonplugin_error_one_of_4_2));
}

int main() {
  test_plugin_error_one_of_4(1);
  test_plugin_error_one_of_4(0);

  printf("Hello world \n");
  return 0;
}

#endif // plugin_error_one_of_4_MAIN
#endif // plugin_error_one_of_4_TEST
