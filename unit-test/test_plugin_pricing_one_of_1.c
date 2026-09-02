#ifndef plugin_pricing_one_of_1_TEST
#define plugin_pricing_one_of_1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define plugin_pricing_one_of_1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/plugin_pricing_one_of_1.h"
plugin_pricing_one_of_1_t* instantiate_plugin_pricing_one_of_1(int include_optional);



plugin_pricing_one_of_1_t* instantiate_plugin_pricing_one_of_1(int include_optional) {
  plugin_pricing_one_of_1_t* plugin_pricing_one_of_1 = NULL;
  if (include_optional) {
    plugin_pricing_one_of_1 = plugin_pricing_one_of_1_create(
      1.337,
      simplebilly_api_plugin_pricing_one_of_1_TYPE_one_time
    );
  } else {
    plugin_pricing_one_of_1 = plugin_pricing_one_of_1_create(
      1.337,
      simplebilly_api_plugin_pricing_one_of_1_TYPE_one_time
    );
  }

  return plugin_pricing_one_of_1;
}


#ifdef plugin_pricing_one_of_1_MAIN

void test_plugin_pricing_one_of_1(int include_optional) {
    plugin_pricing_one_of_1_t* plugin_pricing_one_of_1_1 = instantiate_plugin_pricing_one_of_1(include_optional);

	cJSON* jsonplugin_pricing_one_of_1_1 = plugin_pricing_one_of_1_convertToJSON(plugin_pricing_one_of_1_1);
	printf("plugin_pricing_one_of_1 :\n%s\n", cJSON_Print(jsonplugin_pricing_one_of_1_1));
	plugin_pricing_one_of_1_t* plugin_pricing_one_of_1_2 = plugin_pricing_one_of_1_parseFromJSON(jsonplugin_pricing_one_of_1_1);
	cJSON* jsonplugin_pricing_one_of_1_2 = plugin_pricing_one_of_1_convertToJSON(plugin_pricing_one_of_1_2);
	printf("repeating plugin_pricing_one_of_1:\n%s\n", cJSON_Print(jsonplugin_pricing_one_of_1_2));
}

int main() {
  test_plugin_pricing_one_of_1(1);
  test_plugin_pricing_one_of_1(0);

  printf("Hello world \n");
  return 0;
}

#endif // plugin_pricing_one_of_1_MAIN
#endif // plugin_pricing_one_of_1_TEST
