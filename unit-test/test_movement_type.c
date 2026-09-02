#ifndef movement_type_TEST
#define movement_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define movement_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/movement_type.h"
movement_type_t* instantiate_movement_type(int include_optional);



movement_type_t* instantiate_movement_type(int include_optional) {
  movement_type_t* movement_type = NULL;
  if (include_optional) {
    movement_type = movement_type_create(
    );
  } else {
    movement_type = movement_type_create(
    );
  }

  return movement_type;
}


#ifdef movement_type_MAIN

void test_movement_type(int include_optional) {
    movement_type_t* movement_type_1 = instantiate_movement_type(include_optional);

	cJSON* jsonmovement_type_1 = movement_type_convertToJSON(movement_type_1);
	printf("movement_type :\n%s\n", cJSON_Print(jsonmovement_type_1));
	movement_type_t* movement_type_2 = movement_type_parseFromJSON(jsonmovement_type_1);
	cJSON* jsonmovement_type_2 = movement_type_convertToJSON(movement_type_2);
	printf("repeating movement_type:\n%s\n", cJSON_Print(jsonmovement_type_2));
}

int main() {
  test_movement_type(1);
  test_movement_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // movement_type_MAIN
#endif // movement_type_TEST
