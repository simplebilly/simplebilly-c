#ifndef plugin_error_one_of_6_TEST
#define plugin_error_one_of_6_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define plugin_error_one_of_6_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/plugin_error_one_of_6.h"
plugin_error_one_of_6_t* instantiate_plugin_error_one_of_6(int include_optional);



plugin_error_one_of_6_t* instantiate_plugin_error_one_of_6(int include_optional) {
  plugin_error_one_of_6_t* plugin_error_one_of_6 = NULL;
  if (include_optional) {
    plugin_error_one_of_6 = plugin_error_one_of_6_create(
      "0"
    );
  } else {
    plugin_error_one_of_6 = plugin_error_one_of_6_create(
      "0"
    );
  }

  return plugin_error_one_of_6;
}


#ifdef plugin_error_one_of_6_MAIN

void test_plugin_error_one_of_6(int include_optional) {
    plugin_error_one_of_6_t* plugin_error_one_of_6_1 = instantiate_plugin_error_one_of_6(include_optional);

	cJSON* jsonplugin_error_one_of_6_1 = plugin_error_one_of_6_convertToJSON(plugin_error_one_of_6_1);
	printf("plugin_error_one_of_6 :\n%s\n", cJSON_Print(jsonplugin_error_one_of_6_1));
	plugin_error_one_of_6_t* plugin_error_one_of_6_2 = plugin_error_one_of_6_parseFromJSON(jsonplugin_error_one_of_6_1);
	cJSON* jsonplugin_error_one_of_6_2 = plugin_error_one_of_6_convertToJSON(plugin_error_one_of_6_2);
	printf("repeating plugin_error_one_of_6:\n%s\n", cJSON_Print(jsonplugin_error_one_of_6_2));
}

int main() {
  test_plugin_error_one_of_6(1);
  test_plugin_error_one_of_6(0);

  printf("Hello world \n");
  return 0;
}

#endif // plugin_error_one_of_6_MAIN
#endif // plugin_error_one_of_6_TEST
