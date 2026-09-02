#ifndef attachment_version_TEST
#define attachment_version_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define attachment_version_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/attachment_version.h"
attachment_version_t* instantiate_attachment_version(int include_optional);



attachment_version_t* instantiate_attachment_version(int include_optional) {
  attachment_version_t* attachment_version = NULL;
  if (include_optional) {
    attachment_version = attachment_version_create(
      "0",
      "0",
      56,
      "0",
      "0",
      "0",
      "0",
      56
    );
  } else {
    attachment_version = attachment_version_create(
      "0",
      "0",
      56,
      "0",
      "0",
      "0",
      "0",
      56
    );
  }

  return attachment_version;
}


#ifdef attachment_version_MAIN

void test_attachment_version(int include_optional) {
    attachment_version_t* attachment_version_1 = instantiate_attachment_version(include_optional);

	cJSON* jsonattachment_version_1 = attachment_version_convertToJSON(attachment_version_1);
	printf("attachment_version :\n%s\n", cJSON_Print(jsonattachment_version_1));
	attachment_version_t* attachment_version_2 = attachment_version_parseFromJSON(jsonattachment_version_1);
	cJSON* jsonattachment_version_2 = attachment_version_convertToJSON(attachment_version_2);
	printf("repeating attachment_version:\n%s\n", cJSON_Print(jsonattachment_version_2));
}

int main() {
  test_attachment_version(1);
  test_attachment_version(0);

  printf("Hello world \n");
  return 0;
}

#endif // attachment_version_MAIN
#endif // attachment_version_TEST
