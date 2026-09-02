#ifndef pos_register_create_TEST
#define pos_register_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pos_register_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pos_register_create.h"
pos_register_create_t* instantiate_pos_register_create(int include_optional);



pos_register_create_t* instantiate_pos_register_create(int include_optional) {
  pos_register_create_t* pos_register_create = NULL;
  if (include_optional) {
    pos_register_create = pos_register_create_create(
      "0",
      simplebilly_api_pos_register_create__active
    );
  } else {
    pos_register_create = pos_register_create_create(
      "0",
      simplebilly_api_pos_register_create__active
    );
  }

  return pos_register_create;
}


#ifdef pos_register_create_MAIN

void test_pos_register_create(int include_optional) {
    pos_register_create_t* pos_register_create_1 = instantiate_pos_register_create(include_optional);

	cJSON* jsonpos_register_create_1 = pos_register_create_convertToJSON(pos_register_create_1);
	printf("pos_register_create :\n%s\n", cJSON_Print(jsonpos_register_create_1));
	pos_register_create_t* pos_register_create_2 = pos_register_create_parseFromJSON(jsonpos_register_create_1);
	cJSON* jsonpos_register_create_2 = pos_register_create_convertToJSON(pos_register_create_2);
	printf("repeating pos_register_create:\n%s\n", cJSON_Print(jsonpos_register_create_2));
}

int main() {
  test_pos_register_create(1);
  test_pos_register_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // pos_register_create_MAIN
#endif // pos_register_create_TEST
