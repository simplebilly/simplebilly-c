#ifndef plugin_error_one_of_5_TEST
#define plugin_error_one_of_5_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define plugin_error_one_of_5_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/plugin_error_one_of_5.h"
plugin_error_one_of_5_t* instantiate_plugin_error_one_of_5(int include_optional);



plugin_error_one_of_5_t* instantiate_plugin_error_one_of_5(int include_optional) {
  plugin_error_one_of_5_t* plugin_error_one_of_5 = NULL;
  if (include_optional) {
    plugin_error_one_of_5 = plugin_error_one_of_5_create(
      list_createList()
    );
  } else {
    plugin_error_one_of_5 = plugin_error_one_of_5_create(
      list_createList()
    );
  }

  return plugin_error_one_of_5;
}


#ifdef plugin_error_one_of_5_MAIN

void test_plugin_error_one_of_5(int include_optional) {
    plugin_error_one_of_5_t* plugin_error_one_of_5_1 = instantiate_plugin_error_one_of_5(include_optional);

	cJSON* jsonplugin_error_one_of_5_1 = plugin_error_one_of_5_convertToJSON(plugin_error_one_of_5_1);
	printf("plugin_error_one_of_5 :\n%s\n", cJSON_Print(jsonplugin_error_one_of_5_1));
	plugin_error_one_of_5_t* plugin_error_one_of_5_2 = plugin_error_one_of_5_parseFromJSON(jsonplugin_error_one_of_5_1);
	cJSON* jsonplugin_error_one_of_5_2 = plugin_error_one_of_5_convertToJSON(plugin_error_one_of_5_2);
	printf("repeating plugin_error_one_of_5:\n%s\n", cJSON_Print(jsonplugin_error_one_of_5_2));
}

int main() {
  test_plugin_error_one_of_5(1);
  test_plugin_error_one_of_5(0);

  printf("Hello world \n");
  return 0;
}

#endif // plugin_error_one_of_5_MAIN
#endif // plugin_error_one_of_5_TEST
