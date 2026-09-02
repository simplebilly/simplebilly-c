#ifndef gateway_type_TEST
#define gateway_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gateway_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gateway_type.h"
gateway_type_t* instantiate_gateway_type(int include_optional);



gateway_type_t* instantiate_gateway_type(int include_optional) {
  gateway_type_t* gateway_type = NULL;
  if (include_optional) {
    gateway_type = gateway_type_create(
    );
  } else {
    gateway_type = gateway_type_create(
    );
  }

  return gateway_type;
}


#ifdef gateway_type_MAIN

void test_gateway_type(int include_optional) {
    gateway_type_t* gateway_type_1 = instantiate_gateway_type(include_optional);

	cJSON* jsongateway_type_1 = gateway_type_convertToJSON(gateway_type_1);
	printf("gateway_type :\n%s\n", cJSON_Print(jsongateway_type_1));
	gateway_type_t* gateway_type_2 = gateway_type_parseFromJSON(jsongateway_type_1);
	cJSON* jsongateway_type_2 = gateway_type_convertToJSON(gateway_type_2);
	printf("repeating gateway_type:\n%s\n", cJSON_Print(jsongateway_type_2));
}

int main() {
  test_gateway_type(1);
  test_gateway_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // gateway_type_MAIN
#endif // gateway_type_TEST
