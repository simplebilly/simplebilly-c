#ifndef attachment_TEST
#define attachment_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define attachment_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/attachment.h"
attachment_t* instantiate_attachment(int include_optional);



attachment_t* instantiate_attachment(int include_optional) {
  attachment_t* attachment = NULL;
  if (include_optional) {
    attachment = attachment_create(
      "0",
      "0",
      56,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    attachment = attachment_create(
      "0",
      "0",
      56,
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return attachment;
}


#ifdef attachment_MAIN

void test_attachment(int include_optional) {
    attachment_t* attachment_1 = instantiate_attachment(include_optional);

	cJSON* jsonattachment_1 = attachment_convertToJSON(attachment_1);
	printf("attachment :\n%s\n", cJSON_Print(jsonattachment_1));
	attachment_t* attachment_2 = attachment_parseFromJSON(jsonattachment_1);
	cJSON* jsonattachment_2 = attachment_convertToJSON(attachment_2);
	printf("repeating attachment:\n%s\n", cJSON_Print(jsonattachment_2));
}

int main() {
  test_attachment(1);
  test_attachment(0);

  printf("Hello world \n");
  return 0;
}

#endif // attachment_MAIN
#endif // attachment_TEST
