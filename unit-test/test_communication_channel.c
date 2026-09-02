#ifndef communication_channel_TEST
#define communication_channel_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define communication_channel_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/communication_channel.h"
communication_channel_t* instantiate_communication_channel(int include_optional);



communication_channel_t* instantiate_communication_channel(int include_optional) {
  communication_channel_t* communication_channel = NULL;
  if (include_optional) {
    communication_channel = communication_channel_create(
    );
  } else {
    communication_channel = communication_channel_create(
    );
  }

  return communication_channel;
}


#ifdef communication_channel_MAIN

void test_communication_channel(int include_optional) {
    communication_channel_t* communication_channel_1 = instantiate_communication_channel(include_optional);

	cJSON* jsoncommunication_channel_1 = communication_channel_convertToJSON(communication_channel_1);
	printf("communication_channel :\n%s\n", cJSON_Print(jsoncommunication_channel_1));
	communication_channel_t* communication_channel_2 = communication_channel_parseFromJSON(jsoncommunication_channel_1);
	cJSON* jsoncommunication_channel_2 = communication_channel_convertToJSON(communication_channel_2);
	printf("repeating communication_channel:\n%s\n", cJSON_Print(jsoncommunication_channel_2));
}

int main() {
  test_communication_channel(1);
  test_communication_channel(0);

  printf("Hello world \n");
  return 0;
}

#endif // communication_channel_MAIN
#endif // communication_channel_TEST
