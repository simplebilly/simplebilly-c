#ifndef support_channel_type_TEST
#define support_channel_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define support_channel_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/support_channel_type.h"
support_channel_type_t* instantiate_support_channel_type(int include_optional);



support_channel_type_t* instantiate_support_channel_type(int include_optional) {
  support_channel_type_t* support_channel_type = NULL;
  if (include_optional) {
    support_channel_type = support_channel_type_create(
    );
  } else {
    support_channel_type = support_channel_type_create(
    );
  }

  return support_channel_type;
}


#ifdef support_channel_type_MAIN

void test_support_channel_type(int include_optional) {
    support_channel_type_t* support_channel_type_1 = instantiate_support_channel_type(include_optional);

	cJSON* jsonsupport_channel_type_1 = support_channel_type_convertToJSON(support_channel_type_1);
	printf("support_channel_type :\n%s\n", cJSON_Print(jsonsupport_channel_type_1));
	support_channel_type_t* support_channel_type_2 = support_channel_type_parseFromJSON(jsonsupport_channel_type_1);
	cJSON* jsonsupport_channel_type_2 = support_channel_type_convertToJSON(support_channel_type_2);
	printf("repeating support_channel_type:\n%s\n", cJSON_Print(jsonsupport_channel_type_2));
}

int main() {
  test_support_channel_type(1);
  test_support_channel_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // support_channel_type_MAIN
#endif // support_channel_type_TEST
