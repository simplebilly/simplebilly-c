#ifndef gdpr_api_key_TEST
#define gdpr_api_key_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gdpr_api_key_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gdpr_api_key.h"
gdpr_api_key_t* instantiate_gdpr_api_key(int include_optional);



gdpr_api_key_t* instantiate_gdpr_api_key(int include_optional) {
  gdpr_api_key_t* gdpr_api_key = NULL;
  if (include_optional) {
    gdpr_api_key = gdpr_api_key_create(
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      1
    );
  } else {
    gdpr_api_key = gdpr_api_key_create(
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0",
      1
    );
  }

  return gdpr_api_key;
}


#ifdef gdpr_api_key_MAIN

void test_gdpr_api_key(int include_optional) {
    gdpr_api_key_t* gdpr_api_key_1 = instantiate_gdpr_api_key(include_optional);

	cJSON* jsongdpr_api_key_1 = gdpr_api_key_convertToJSON(gdpr_api_key_1);
	printf("gdpr_api_key :\n%s\n", cJSON_Print(jsongdpr_api_key_1));
	gdpr_api_key_t* gdpr_api_key_2 = gdpr_api_key_parseFromJSON(jsongdpr_api_key_1);
	cJSON* jsongdpr_api_key_2 = gdpr_api_key_convertToJSON(gdpr_api_key_2);
	printf("repeating gdpr_api_key:\n%s\n", cJSON_Print(jsongdpr_api_key_2));
}

int main() {
  test_gdpr_api_key(1);
  test_gdpr_api_key(0);

  printf("Hello world \n");
  return 0;
}

#endif // gdpr_api_key_MAIN
#endif // gdpr_api_key_TEST
