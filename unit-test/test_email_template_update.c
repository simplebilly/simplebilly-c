#ifndef email_template_update_TEST
#define email_template_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define email_template_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/email_template_update.h"
email_template_update_t* instantiate_email_template_update(int include_optional);



email_template_update_t* instantiate_email_template_update(int include_optional) {
  email_template_update_t* email_template_update = NULL;
  if (include_optional) {
    email_template_update = email_template_update_create(
      "0",
      "0",
      active,
      "0",
      null
    );
  } else {
    email_template_update = email_template_update_create(
      "0",
      "0",
      active,
      "0",
      null
    );
  }

  return email_template_update;
}


#ifdef email_template_update_MAIN

void test_email_template_update(int include_optional) {
    email_template_update_t* email_template_update_1 = instantiate_email_template_update(include_optional);

	cJSON* jsonemail_template_update_1 = email_template_update_convertToJSON(email_template_update_1);
	printf("email_template_update :\n%s\n", cJSON_Print(jsonemail_template_update_1));
	email_template_update_t* email_template_update_2 = email_template_update_parseFromJSON(jsonemail_template_update_1);
	cJSON* jsonemail_template_update_2 = email_template_update_convertToJSON(email_template_update_2);
	printf("repeating email_template_update:\n%s\n", cJSON_Print(jsonemail_template_update_2));
}

int main() {
  test_email_template_update(1);
  test_email_template_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // email_template_update_MAIN
#endif // email_template_update_TEST
