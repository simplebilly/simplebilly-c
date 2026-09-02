#ifndef gdpr_refresh_token_TEST
#define gdpr_refresh_token_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gdpr_refresh_token_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gdpr_refresh_token.h"
gdpr_refresh_token_t* instantiate_gdpr_refresh_token(int include_optional);



gdpr_refresh_token_t* instantiate_gdpr_refresh_token(int include_optional) {
  gdpr_refresh_token_t* gdpr_refresh_token = NULL;
  if (include_optional) {
    gdpr_refresh_token = gdpr_refresh_token_create(
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      "0"
    );
  } else {
    gdpr_refresh_token = gdpr_refresh_token_create(
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "2013-10-20T19:20:30+01:00",
      "0"
    );
  }

  return gdpr_refresh_token;
}


#ifdef gdpr_refresh_token_MAIN

void test_gdpr_refresh_token(int include_optional) {
    gdpr_refresh_token_t* gdpr_refresh_token_1 = instantiate_gdpr_refresh_token(include_optional);

	cJSON* jsongdpr_refresh_token_1 = gdpr_refresh_token_convertToJSON(gdpr_refresh_token_1);
	printf("gdpr_refresh_token :\n%s\n", cJSON_Print(jsongdpr_refresh_token_1));
	gdpr_refresh_token_t* gdpr_refresh_token_2 = gdpr_refresh_token_parseFromJSON(jsongdpr_refresh_token_1);
	cJSON* jsongdpr_refresh_token_2 = gdpr_refresh_token_convertToJSON(gdpr_refresh_token_2);
	printf("repeating gdpr_refresh_token:\n%s\n", cJSON_Print(jsongdpr_refresh_token_2));
}

int main() {
  test_gdpr_refresh_token(1);
  test_gdpr_refresh_token(0);

  printf("Hello world \n");
  return 0;
}

#endif // gdpr_refresh_token_MAIN
#endif // gdpr_refresh_token_TEST
