#ifndef plugin_error_TEST
#define plugin_error_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define plugin_error_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/plugin_error.h"
plugin_error_t* instantiate_plugin_error(int include_optional);



plugin_error_t* instantiate_plugin_error(int include_optional) {
  plugin_error_t* plugin_error = NULL;
  if (include_optional) {
    plugin_error = plugin_error_create(
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      "0"
    );
  } else {
    plugin_error = plugin_error_create(
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      list_createList(),
      "0"
    );
  }

  return plugin_error;
}


#ifdef plugin_error_MAIN

void test_plugin_error(int include_optional) {
    plugin_error_t* plugin_error_1 = instantiate_plugin_error(include_optional);

	cJSON* jsonplugin_error_1 = plugin_error_convertToJSON(plugin_error_1);
	printf("plugin_error :\n%s\n", cJSON_Print(jsonplugin_error_1));
	plugin_error_t* plugin_error_2 = plugin_error_parseFromJSON(jsonplugin_error_1);
	cJSON* jsonplugin_error_2 = plugin_error_convertToJSON(plugin_error_2);
	printf("repeating plugin_error:\n%s\n", cJSON_Print(jsonplugin_error_2));
}

int main() {
  test_plugin_error(1);
  test_plugin_error(0);

  printf("Hello world \n");
  return 0;
}

#endif // plugin_error_MAIN
#endif // plugin_error_TEST
