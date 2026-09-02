#ifndef pos_register_TEST
#define pos_register_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pos_register_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pos_register.h"
pos_register_t* instantiate_pos_register(int include_optional);



pos_register_t* instantiate_pos_register(int include_optional) {
  pos_register_t* pos_register = NULL;
  if (include_optional) {
    pos_register = pos_register_create(
      "0",
      simplebilly_api_pos_register__active
    );
  } else {
    pos_register = pos_register_create(
      "0",
      simplebilly_api_pos_register__active
    );
  }

  return pos_register;
}


#ifdef pos_register_MAIN

void test_pos_register(int include_optional) {
    pos_register_t* pos_register_1 = instantiate_pos_register(include_optional);

	cJSON* jsonpos_register_1 = pos_register_convertToJSON(pos_register_1);
	printf("pos_register :\n%s\n", cJSON_Print(jsonpos_register_1));
	pos_register_t* pos_register_2 = pos_register_parseFromJSON(jsonpos_register_1);
	cJSON* jsonpos_register_2 = pos_register_convertToJSON(pos_register_2);
	printf("repeating pos_register:\n%s\n", cJSON_Print(jsonpos_register_2));
}

int main() {
  test_pos_register(1);
  test_pos_register(0);

  printf("Hello world \n");
  return 0;
}

#endif // pos_register_MAIN
#endif // pos_register_TEST
