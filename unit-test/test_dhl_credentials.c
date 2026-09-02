#ifndef dhl_credentials_TEST
#define dhl_credentials_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dhl_credentials_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dhl_credentials.h"
dhl_credentials_t* instantiate_dhl_credentials(int include_optional);



dhl_credentials_t* instantiate_dhl_credentials(int include_optional) {
  dhl_credentials_t* dhl_credentials = NULL;
  if (include_optional) {
    dhl_credentials = dhl_credentials_create(
      "0",
      "0",
      "0"
    );
  } else {
    dhl_credentials = dhl_credentials_create(
      "0",
      "0",
      "0"
    );
  }

  return dhl_credentials;
}


#ifdef dhl_credentials_MAIN

void test_dhl_credentials(int include_optional) {
    dhl_credentials_t* dhl_credentials_1 = instantiate_dhl_credentials(include_optional);

	cJSON* jsondhl_credentials_1 = dhl_credentials_convertToJSON(dhl_credentials_1);
	printf("dhl_credentials :\n%s\n", cJSON_Print(jsondhl_credentials_1));
	dhl_credentials_t* dhl_credentials_2 = dhl_credentials_parseFromJSON(jsondhl_credentials_1);
	cJSON* jsondhl_credentials_2 = dhl_credentials_convertToJSON(dhl_credentials_2);
	printf("repeating dhl_credentials:\n%s\n", cJSON_Print(jsondhl_credentials_2));
}

int main() {
  test_dhl_credentials(1);
  test_dhl_credentials(0);

  printf("Hello world \n");
  return 0;
}

#endif // dhl_credentials_MAIN
#endif // dhl_credentials_TEST
