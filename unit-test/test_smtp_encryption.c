#ifndef smtp_encryption_TEST
#define smtp_encryption_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define smtp_encryption_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/smtp_encryption.h"
smtp_encryption_t* instantiate_smtp_encryption(int include_optional);



smtp_encryption_t* instantiate_smtp_encryption(int include_optional) {
  smtp_encryption_t* smtp_encryption = NULL;
  if (include_optional) {
    smtp_encryption = smtp_encryption_create(
    );
  } else {
    smtp_encryption = smtp_encryption_create(
    );
  }

  return smtp_encryption;
}


#ifdef smtp_encryption_MAIN

void test_smtp_encryption(int include_optional) {
    smtp_encryption_t* smtp_encryption_1 = instantiate_smtp_encryption(include_optional);

	cJSON* jsonsmtp_encryption_1 = smtp_encryption_convertToJSON(smtp_encryption_1);
	printf("smtp_encryption :\n%s\n", cJSON_Print(jsonsmtp_encryption_1));
	smtp_encryption_t* smtp_encryption_2 = smtp_encryption_parseFromJSON(jsonsmtp_encryption_1);
	cJSON* jsonsmtp_encryption_2 = smtp_encryption_convertToJSON(smtp_encryption_2);
	printf("repeating smtp_encryption:\n%s\n", cJSON_Print(jsonsmtp_encryption_2));
}

int main() {
  test_smtp_encryption(1);
  test_smtp_encryption(0);

  printf("Hello world \n");
  return 0;
}

#endif // smtp_encryption_MAIN
#endif // smtp_encryption_TEST
