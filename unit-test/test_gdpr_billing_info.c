#ifndef gdpr_billing_info_TEST
#define gdpr_billing_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define gdpr_billing_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/gdpr_billing_info.h"
gdpr_billing_info_t* instantiate_gdpr_billing_info(int include_optional);



gdpr_billing_info_t* instantiate_gdpr_billing_info(int include_optional) {
  gdpr_billing_info_t* gdpr_billing_info = NULL;
  if (include_optional) {
    gdpr_billing_info = gdpr_billing_info_create(
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0"
    );
  } else {
    gdpr_billing_info = gdpr_billing_info_create(
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "0",
      "0",
      "0"
    );
  }

  return gdpr_billing_info;
}


#ifdef gdpr_billing_info_MAIN

void test_gdpr_billing_info(int include_optional) {
    gdpr_billing_info_t* gdpr_billing_info_1 = instantiate_gdpr_billing_info(include_optional);

	cJSON* jsongdpr_billing_info_1 = gdpr_billing_info_convertToJSON(gdpr_billing_info_1);
	printf("gdpr_billing_info :\n%s\n", cJSON_Print(jsongdpr_billing_info_1));
	gdpr_billing_info_t* gdpr_billing_info_2 = gdpr_billing_info_parseFromJSON(jsongdpr_billing_info_1);
	cJSON* jsongdpr_billing_info_2 = gdpr_billing_info_convertToJSON(gdpr_billing_info_2);
	printf("repeating gdpr_billing_info:\n%s\n", cJSON_Print(jsongdpr_billing_info_2));
}

int main() {
  test_gdpr_billing_info(1);
  test_gdpr_billing_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // gdpr_billing_info_MAIN
#endif // gdpr_billing_info_TEST
