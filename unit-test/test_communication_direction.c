#ifndef communication_direction_TEST
#define communication_direction_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define communication_direction_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/communication_direction.h"
communication_direction_t* instantiate_communication_direction(int include_optional);



communication_direction_t* instantiate_communication_direction(int include_optional) {
  communication_direction_t* communication_direction = NULL;
  if (include_optional) {
    communication_direction = communication_direction_create(
    );
  } else {
    communication_direction = communication_direction_create(
    );
  }

  return communication_direction;
}


#ifdef communication_direction_MAIN

void test_communication_direction(int include_optional) {
    communication_direction_t* communication_direction_1 = instantiate_communication_direction(include_optional);

	cJSON* jsoncommunication_direction_1 = communication_direction_convertToJSON(communication_direction_1);
	printf("communication_direction :\n%s\n", cJSON_Print(jsoncommunication_direction_1));
	communication_direction_t* communication_direction_2 = communication_direction_parseFromJSON(jsoncommunication_direction_1);
	cJSON* jsoncommunication_direction_2 = communication_direction_convertToJSON(communication_direction_2);
	printf("repeating communication_direction:\n%s\n", cJSON_Print(jsoncommunication_direction_2));
}

int main() {
  test_communication_direction(1);
  test_communication_direction(0);

  printf("Hello world \n");
  return 0;
}

#endif // communication_direction_MAIN
#endif // communication_direction_TEST
