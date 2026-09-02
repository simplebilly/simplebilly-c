#ifndef message_type_TEST
#define message_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define message_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/message_type.h"
message_type_t* instantiate_message_type(int include_optional);



message_type_t* instantiate_message_type(int include_optional) {
  message_type_t* message_type = NULL;
  if (include_optional) {
    message_type = message_type_create(
    );
  } else {
    message_type = message_type_create(
    );
  }

  return message_type;
}


#ifdef message_type_MAIN

void test_message_type(int include_optional) {
    message_type_t* message_type_1 = instantiate_message_type(include_optional);

	cJSON* jsonmessage_type_1 = message_type_convertToJSON(message_type_1);
	printf("message_type :\n%s\n", cJSON_Print(jsonmessage_type_1));
	message_type_t* message_type_2 = message_type_parseFromJSON(jsonmessage_type_1);
	cJSON* jsonmessage_type_2 = message_type_convertToJSON(message_type_2);
	printf("repeating message_type:\n%s\n", cJSON_Print(jsonmessage_type_2));
}

int main() {
  test_message_type(1);
  test_message_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // message_type_MAIN
#endif // message_type_TEST
