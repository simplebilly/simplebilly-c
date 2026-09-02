#ifndef marketplace_connection_TEST
#define marketplace_connection_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define marketplace_connection_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/marketplace_connection.h"
marketplace_connection_t* instantiate_marketplace_connection(int include_optional);



marketplace_connection_t* instantiate_marketplace_connection(int include_optional) {
  marketplace_connection_t* marketplace_connection = NULL;
  if (include_optional) {
    marketplace_connection = marketplace_connection_create(
      null,
      "0",
      simplebilly_api_marketplace_connection__apikey,
      "2013-10-20T19:20:30+01:00",
      1,
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    marketplace_connection = marketplace_connection_create(
      null,
      "0",
      simplebilly_api_marketplace_connection__apikey,
      "2013-10-20T19:20:30+01:00",
      1,
      "0",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return marketplace_connection;
}


#ifdef marketplace_connection_MAIN

void test_marketplace_connection(int include_optional) {
    marketplace_connection_t* marketplace_connection_1 = instantiate_marketplace_connection(include_optional);

	cJSON* jsonmarketplace_connection_1 = marketplace_connection_convertToJSON(marketplace_connection_1);
	printf("marketplace_connection :\n%s\n", cJSON_Print(jsonmarketplace_connection_1));
	marketplace_connection_t* marketplace_connection_2 = marketplace_connection_parseFromJSON(jsonmarketplace_connection_1);
	cJSON* jsonmarketplace_connection_2 = marketplace_connection_convertToJSON(marketplace_connection_2);
	printf("repeating marketplace_connection:\n%s\n", cJSON_Print(jsonmarketplace_connection_2));
}

int main() {
  test_marketplace_connection(1);
  test_marketplace_connection(0);

  printf("Hello world \n");
  return 0;
}

#endif // marketplace_connection_MAIN
#endif // marketplace_connection_TEST
