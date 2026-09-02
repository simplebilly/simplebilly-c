#ifndef email_template_status_TEST
#define email_template_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define email_template_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/email_template_status.h"
email_template_status_t* instantiate_email_template_status(int include_optional);



email_template_status_t* instantiate_email_template_status(int include_optional) {
  email_template_status_t* email_template_status = NULL;
  if (include_optional) {
    email_template_status = email_template_status_create(
    );
  } else {
    email_template_status = email_template_status_create(
    );
  }

  return email_template_status;
}


#ifdef email_template_status_MAIN

void test_email_template_status(int include_optional) {
    email_template_status_t* email_template_status_1 = instantiate_email_template_status(include_optional);

	cJSON* jsonemail_template_status_1 = email_template_status_convertToJSON(email_template_status_1);
	printf("email_template_status :\n%s\n", cJSON_Print(jsonemail_template_status_1));
	email_template_status_t* email_template_status_2 = email_template_status_parseFromJSON(jsonemail_template_status_1);
	cJSON* jsonemail_template_status_2 = email_template_status_convertToJSON(email_template_status_2);
	printf("repeating email_template_status:\n%s\n", cJSON_Print(jsonemail_template_status_2));
}

int main() {
  test_email_template_status(1);
  test_email_template_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // email_template_status_MAIN
#endif // email_template_status_TEST
