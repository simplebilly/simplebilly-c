#ifndef plugin_pricing_one_of_2_TEST
#define plugin_pricing_one_of_2_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define plugin_pricing_one_of_2_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/plugin_pricing_one_of_2.h"
plugin_pricing_one_of_2_t* instantiate_plugin_pricing_one_of_2(int include_optional);



plugin_pricing_one_of_2_t* instantiate_plugin_pricing_one_of_2(int include_optional) {
  plugin_pricing_one_of_2_t* plugin_pricing_one_of_2 = NULL;
  if (include_optional) {
    plugin_pricing_one_of_2 = plugin_pricing_one_of_2_create(
      1.337,
      simplebilly_api_plugin_pricing_one_of_2_TYPE_recurring
    );
  } else {
    plugin_pricing_one_of_2 = plugin_pricing_one_of_2_create(
      1.337,
      simplebilly_api_plugin_pricing_one_of_2_TYPE_recurring
    );
  }

  return plugin_pricing_one_of_2;
}


#ifdef plugin_pricing_one_of_2_MAIN

void test_plugin_pricing_one_of_2(int include_optional) {
    plugin_pricing_one_of_2_t* plugin_pricing_one_of_2_1 = instantiate_plugin_pricing_one_of_2(include_optional);

	cJSON* jsonplugin_pricing_one_of_2_1 = plugin_pricing_one_of_2_convertToJSON(plugin_pricing_one_of_2_1);
	printf("plugin_pricing_one_of_2 :\n%s\n", cJSON_Print(jsonplugin_pricing_one_of_2_1));
	plugin_pricing_one_of_2_t* plugin_pricing_one_of_2_2 = plugin_pricing_one_of_2_parseFromJSON(jsonplugin_pricing_one_of_2_1);
	cJSON* jsonplugin_pricing_one_of_2_2 = plugin_pricing_one_of_2_convertToJSON(plugin_pricing_one_of_2_2);
	printf("repeating plugin_pricing_one_of_2:\n%s\n", cJSON_Print(jsonplugin_pricing_one_of_2_2));
}

int main() {
  test_plugin_pricing_one_of_2(1);
  test_plugin_pricing_one_of_2(0);

  printf("Hello world \n");
  return 0;
}

#endif // plugin_pricing_one_of_2_MAIN
#endif // plugin_pricing_one_of_2_TEST
