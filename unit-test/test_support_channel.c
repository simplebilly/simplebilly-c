#ifndef support_channel_TEST
#define support_channel_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define support_channel_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/support_channel.h"
support_channel_t* instantiate_support_channel(int include_optional);



support_channel_t* instantiate_support_channel(int include_optional) {
  support_channel_t* support_channel = NULL;
  if (include_optional) {
    support_channel = support_channel_create(
      simplebilly_api_support_channel__email,
      null,
      "2013-10-20T19:20:30+01:00",
      1,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  } else {
    support_channel = support_channel_create(
      simplebilly_api_support_channel__email,
      null,
      "2013-10-20T19:20:30+01:00",
      1,
      "0",
      "0",
      "2013-10-20T19:20:30+01:00"
    );
  }

  return support_channel;
}


#ifdef support_channel_MAIN

void test_support_channel(int include_optional) {
    support_channel_t* support_channel_1 = instantiate_support_channel(include_optional);

	cJSON* jsonsupport_channel_1 = support_channel_convertToJSON(support_channel_1);
	printf("support_channel :\n%s\n", cJSON_Print(jsonsupport_channel_1));
	support_channel_t* support_channel_2 = support_channel_parseFromJSON(jsonsupport_channel_1);
	cJSON* jsonsupport_channel_2 = support_channel_convertToJSON(support_channel_2);
	printf("repeating support_channel:\n%s\n", cJSON_Print(jsonsupport_channel_2));
}

int main() {
  test_support_channel(1);
  test_support_channel(0);

  printf("Hello world \n");
  return 0;
}

#endif // support_channel_MAIN
#endif // support_channel_TEST
