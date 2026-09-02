#ifndef gdpr_user_TEST
#define gdpr_user_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gdpr_user_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gdpr_user.h"
gdpr_user_t* instantiate_gdpr_user(int include_optional);



gdpr_user_t* instantiate_gdpr_user(int include_optional) {
  gdpr_user_t* gdpr_user = NULL;
  if (include_optional) {
    gdpr_user = gdpr_user_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0"
    );
  } else {
    gdpr_user = gdpr_user_create(
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0"
    );
  }

  return gdpr_user;
}


#ifdef gdpr_user_MAIN

void test_gdpr_user(int include_optional) {
    gdpr_user_t* gdpr_user_1 = instantiate_gdpr_user(include_optional);

	cJSON* jsongdpr_user_1 = gdpr_user_convertToJSON(gdpr_user_1);
	printf("gdpr_user :\n%s\n", cJSON_Print(jsongdpr_user_1));
	gdpr_user_t* gdpr_user_2 = gdpr_user_parseFromJSON(jsongdpr_user_1);
	cJSON* jsongdpr_user_2 = gdpr_user_convertToJSON(gdpr_user_2);
	printf("repeating gdpr_user:\n%s\n", cJSON_Print(jsongdpr_user_2));
}

int main() {
  test_gdpr_user(1);
  test_gdpr_user(0);

  printf("Hello world \n");
  return 0;
}

#endif // gdpr_user_MAIN
#endif // gdpr_user_TEST
