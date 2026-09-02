#ifndef smtp_config_TEST
#define smtp_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define smtp_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/smtp_config.h"
smtp_config_t* instantiate_smtp_config(int include_optional);



smtp_config_t* instantiate_smtp_config(int include_optional) {
  smtp_config_t* smtp_config = NULL;
  if (include_optional) {
    smtp_config = smtp_config_create(
      simplebilly_api_smtp_config__StartTls,
      "0",
      "0",
      "0",
      "0",
      0,
      0,
      "0"
    );
  } else {
    smtp_config = smtp_config_create(
      simplebilly_api_smtp_config__StartTls,
      "0",
      "0",
      "0",
      "0",
      0,
      0,
      "0"
    );
  }

  return smtp_config;
}


#ifdef smtp_config_MAIN

void test_smtp_config(int include_optional) {
    smtp_config_t* smtp_config_1 = instantiate_smtp_config(include_optional);

	cJSON* jsonsmtp_config_1 = smtp_config_convertToJSON(smtp_config_1);
	printf("smtp_config :\n%s\n", cJSON_Print(jsonsmtp_config_1));
	smtp_config_t* smtp_config_2 = smtp_config_parseFromJSON(jsonsmtp_config_1);
	cJSON* jsonsmtp_config_2 = smtp_config_convertToJSON(smtp_config_2);
	printf("repeating smtp_config:\n%s\n", cJSON_Print(jsonsmtp_config_2));
}

int main() {
  test_smtp_config(1);
  test_smtp_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // smtp_config_MAIN
#endif // smtp_config_TEST
