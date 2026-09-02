#ifndef plugin_pricing_TEST
#define plugin_pricing_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define plugin_pricing_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/plugin_pricing.h"
plugin_pricing_t* instantiate_plugin_pricing(int include_optional);



plugin_pricing_t* instantiate_plugin_pricing(int include_optional) {
  plugin_pricing_t* plugin_pricing = NULL;
  if (include_optional) {
    plugin_pricing = plugin_pricing_create(
      simplebilly_api_plugin_pricing_TYPE_free,
      1.337,
      1.337
    );
  } else {
    plugin_pricing = plugin_pricing_create(
      simplebilly_api_plugin_pricing_TYPE_free,
      1.337,
      1.337
    );
  }

  return plugin_pricing;
}


#ifdef plugin_pricing_MAIN

void test_plugin_pricing(int include_optional) {
    plugin_pricing_t* plugin_pricing_1 = instantiate_plugin_pricing(include_optional);

	cJSON* jsonplugin_pricing_1 = plugin_pricing_convertToJSON(plugin_pricing_1);
	printf("plugin_pricing :\n%s\n", cJSON_Print(jsonplugin_pricing_1));
	plugin_pricing_t* plugin_pricing_2 = plugin_pricing_parseFromJSON(jsonplugin_pricing_1);
	cJSON* jsonplugin_pricing_2 = plugin_pricing_convertToJSON(plugin_pricing_2);
	printf("repeating plugin_pricing:\n%s\n", cJSON_Print(jsonplugin_pricing_2));
}

int main() {
  test_plugin_pricing(1);
  test_plugin_pricing(0);

  printf("Hello world \n");
  return 0;
}

#endif // plugin_pricing_MAIN
#endif // plugin_pricing_TEST
