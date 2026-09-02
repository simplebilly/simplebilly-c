#ifndef shipping_credentials_TEST
#define shipping_credentials_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define shipping_credentials_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/shipping_credentials.h"
shipping_credentials_t* instantiate_shipping_credentials(int include_optional);

#include "test_dhl_credentials.c"
#include "test_ups_credentials.c"


shipping_credentials_t* instantiate_shipping_credentials(int include_optional) {
  shipping_credentials_t* shipping_credentials = NULL;
  if (include_optional) {
    shipping_credentials = shipping_credentials_create(
       // false, not to have infinite recursion
      instantiate_dhl_credentials(0),
       // false, not to have infinite recursion
      instantiate_ups_credentials(0)
    );
  } else {
    shipping_credentials = shipping_credentials_create(
      NULL,
      NULL
    );
  }

  return shipping_credentials;
}


#ifdef shipping_credentials_MAIN

void test_shipping_credentials(int include_optional) {
    shipping_credentials_t* shipping_credentials_1 = instantiate_shipping_credentials(include_optional);

	cJSON* jsonshipping_credentials_1 = shipping_credentials_convertToJSON(shipping_credentials_1);
	printf("shipping_credentials :\n%s\n", cJSON_Print(jsonshipping_credentials_1));
	shipping_credentials_t* shipping_credentials_2 = shipping_credentials_parseFromJSON(jsonshipping_credentials_1);
	cJSON* jsonshipping_credentials_2 = shipping_credentials_convertToJSON(shipping_credentials_2);
	printf("repeating shipping_credentials:\n%s\n", cJSON_Print(jsonshipping_credentials_2));
}

int main() {
  test_shipping_credentials(1);
  test_shipping_credentials(0);

  printf("Hello world \n");
  return 0;
}

#endif // shipping_credentials_MAIN
#endif // shipping_credentials_TEST
