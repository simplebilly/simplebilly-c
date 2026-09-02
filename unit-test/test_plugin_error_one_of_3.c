#ifndef plugin_error_one_of_3_TEST
#define plugin_error_one_of_3_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define plugin_error_one_of_3_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/plugin_error_one_of_3.h"
plugin_error_one_of_3_t* instantiate_plugin_error_one_of_3(int include_optional);



plugin_error_one_of_3_t* instantiate_plugin_error_one_of_3(int include_optional) {
  plugin_error_one_of_3_t* plugin_error_one_of_3 = NULL;
  if (include_optional) {
    plugin_error_one_of_3 = plugin_error_one_of_3_create(
      list_createList()
    );
  } else {
    plugin_error_one_of_3 = plugin_error_one_of_3_create(
      list_createList()
    );
  }

  return plugin_error_one_of_3;
}


#ifdef plugin_error_one_of_3_MAIN

void test_plugin_error_one_of_3(int include_optional) {
    plugin_error_one_of_3_t* plugin_error_one_of_3_1 = instantiate_plugin_error_one_of_3(include_optional);

	cJSON* jsonplugin_error_one_of_3_1 = plugin_error_one_of_3_convertToJSON(plugin_error_one_of_3_1);
	printf("plugin_error_one_of_3 :\n%s\n", cJSON_Print(jsonplugin_error_one_of_3_1));
	plugin_error_one_of_3_t* plugin_error_one_of_3_2 = plugin_error_one_of_3_parseFromJSON(jsonplugin_error_one_of_3_1);
	cJSON* jsonplugin_error_one_of_3_2 = plugin_error_one_of_3_convertToJSON(plugin_error_one_of_3_2);
	printf("repeating plugin_error_one_of_3:\n%s\n", cJSON_Print(jsonplugin_error_one_of_3_2));
}

int main() {
  test_plugin_error_one_of_3(1);
  test_plugin_error_one_of_3(0);

  printf("Hello world \n");
  return 0;
}

#endif // plugin_error_one_of_3_MAIN
#endif // plugin_error_one_of_3_TEST
