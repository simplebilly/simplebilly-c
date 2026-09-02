#ifndef attachment_create_TEST
#define attachment_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define attachment_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/attachment_create.h"
attachment_create_t* instantiate_attachment_create(int include_optional);



attachment_create_t* instantiate_attachment_create(int include_optional) {
  attachment_create_t* attachment_create = NULL;
  if (include_optional) {
    attachment_create = attachment_create_create(
      "0",
      "0",
      56,
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    attachment_create = attachment_create_create(
      "0",
      "0",
      56,
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return attachment_create;
}


#ifdef attachment_create_MAIN

void test_attachment_create(int include_optional) {
    attachment_create_t* attachment_create_1 = instantiate_attachment_create(include_optional);

	cJSON* jsonattachment_create_1 = attachment_create_convertToJSON(attachment_create_1);
	printf("attachment_create :\n%s\n", cJSON_Print(jsonattachment_create_1));
	attachment_create_t* attachment_create_2 = attachment_create_parseFromJSON(jsonattachment_create_1);
	cJSON* jsonattachment_create_2 = attachment_create_convertToJSON(attachment_create_2);
	printf("repeating attachment_create:\n%s\n", cJSON_Print(jsonattachment_create_2));
}

int main() {
  test_attachment_create(1);
  test_attachment_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // attachment_create_MAIN
#endif // attachment_create_TEST
