#ifndef message_direction_TEST
#define message_direction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define message_direction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/message_direction.h"
message_direction_t* instantiate_message_direction(int include_optional);



message_direction_t* instantiate_message_direction(int include_optional) {
  message_direction_t* message_direction = NULL;
  if (include_optional) {
    message_direction = message_direction_create(
    );
  } else {
    message_direction = message_direction_create(
    );
  }

  return message_direction;
}


#ifdef message_direction_MAIN

void test_message_direction(int include_optional) {
    message_direction_t* message_direction_1 = instantiate_message_direction(include_optional);

	cJSON* jsonmessage_direction_1 = message_direction_convertToJSON(message_direction_1);
	printf("message_direction :\n%s\n", cJSON_Print(jsonmessage_direction_1));
	message_direction_t* message_direction_2 = message_direction_parseFromJSON(jsonmessage_direction_1);
	cJSON* jsonmessage_direction_2 = message_direction_convertToJSON(message_direction_2);
	printf("repeating message_direction:\n%s\n", cJSON_Print(jsonmessage_direction_2));
}

int main() {
  test_message_direction(1);
  test_message_direction(0);

  printf("Hello world \n");
  return 0;
}

#endif // message_direction_MAIN
#endif // message_direction_TEST
