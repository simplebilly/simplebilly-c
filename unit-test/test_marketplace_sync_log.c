#ifndef marketplace_sync_log_TEST
#define marketplace_sync_log_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define marketplace_sync_log_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/marketplace_sync_log.h"
marketplace_sync_log_t* instantiate_marketplace_sync_log(int include_optional);



marketplace_sync_log_t* instantiate_marketplace_sync_log(int include_optional) {
  marketplace_sync_log_t* marketplace_sync_log = NULL;
  if (include_optional) {
    marketplace_sync_log = marketplace_sync_log_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      56,
      56,
      "0",
      "2013-10-20T19:20:30+01:00",
      simplebilly_api_marketplace_sync_log__running,
      simplebilly_api_marketplace_sync_log__orders
    );
  } else {
    marketplace_sync_log = marketplace_sync_log_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      56,
      56,
      "0",
      "2013-10-20T19:20:30+01:00",
      simplebilly_api_marketplace_sync_log__running,
      simplebilly_api_marketplace_sync_log__orders
    );
  }

  return marketplace_sync_log;
}


#ifdef marketplace_sync_log_MAIN

void test_marketplace_sync_log(int include_optional) {
    marketplace_sync_log_t* marketplace_sync_log_1 = instantiate_marketplace_sync_log(include_optional);

	cJSON* jsonmarketplace_sync_log_1 = marketplace_sync_log_convertToJSON(marketplace_sync_log_1);
	printf("marketplace_sync_log :\n%s\n", cJSON_Print(jsonmarketplace_sync_log_1));
	marketplace_sync_log_t* marketplace_sync_log_2 = marketplace_sync_log_parseFromJSON(jsonmarketplace_sync_log_1);
	cJSON* jsonmarketplace_sync_log_2 = marketplace_sync_log_convertToJSON(marketplace_sync_log_2);
	printf("repeating marketplace_sync_log:\n%s\n", cJSON_Print(jsonmarketplace_sync_log_2));
}

int main() {
  test_marketplace_sync_log(1);
  test_marketplace_sync_log(0);

  printf("Hello world \n");
  return 0;
}

#endif // marketplace_sync_log_MAIN
#endif // marketplace_sync_log_TEST
