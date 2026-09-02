#ifndef email_template_create_TEST
#define email_template_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define email_template_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/email_template_create.h"
email_template_create_t* instantiate_email_template_create(int include_optional);



email_template_create_t* instantiate_email_template_create(int include_optional) {
  email_template_create_t* email_template_create = NULL;
  if (include_optional) {
    email_template_create = email_template_create_create(
      "0",
      "0",
      active,
      "0",
      null
    );
  } else {
    email_template_create = email_template_create_create(
      "0",
      "0",
      active,
      "0",
      null
    );
  }

  return email_template_create;
}


#ifdef email_template_create_MAIN

void test_email_template_create(int include_optional) {
    email_template_create_t* email_template_create_1 = instantiate_email_template_create(include_optional);

	cJSON* jsonemail_template_create_1 = email_template_create_convertToJSON(email_template_create_1);
	printf("email_template_create :\n%s\n", cJSON_Print(jsonemail_template_create_1));
	email_template_create_t* email_template_create_2 = email_template_create_parseFromJSON(jsonemail_template_create_1);
	cJSON* jsonemail_template_create_2 = email_template_create_convertToJSON(email_template_create_2);
	printf("repeating email_template_create:\n%s\n", cJSON_Print(jsonemail_template_create_2));
}

int main() {
  test_email_template_create(1);
  test_email_template_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // email_template_create_MAIN
#endif // email_template_create_TEST
