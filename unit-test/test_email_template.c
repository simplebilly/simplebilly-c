#ifndef email_template_TEST
#define email_template_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define email_template_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/email_template.h"
email_template_t* instantiate_email_template(int include_optional);



email_template_t* instantiate_email_template(int include_optional) {
  email_template_t* email_template = NULL;
  if (include_optional) {
    email_template = email_template_create(
      "0",
      "0",
      active,
      "0",
      null
    );
  } else {
    email_template = email_template_create(
      "0",
      "0",
      active,
      "0",
      null
    );
  }

  return email_template;
}


#ifdef email_template_MAIN

void test_email_template(int include_optional) {
    email_template_t* email_template_1 = instantiate_email_template(include_optional);

	cJSON* jsonemail_template_1 = email_template_convertToJSON(email_template_1);
	printf("email_template :\n%s\n", cJSON_Print(jsonemail_template_1));
	email_template_t* email_template_2 = email_template_parseFromJSON(jsonemail_template_1);
	cJSON* jsonemail_template_2 = email_template_convertToJSON(email_template_2);
	printf("repeating email_template:\n%s\n", cJSON_Print(jsonemail_template_2));
}

int main() {
  test_email_template(1);
  test_email_template(0);

  printf("Hello world \n");
  return 0;
}

#endif // email_template_MAIN
#endif // email_template_TEST
