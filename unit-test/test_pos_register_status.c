#ifndef pos_register_status_TEST
#define pos_register_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pos_register_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pos_register_status.h"
pos_register_status_t* instantiate_pos_register_status(int include_optional);



pos_register_status_t* instantiate_pos_register_status(int include_optional) {
  pos_register_status_t* pos_register_status = NULL;
  if (include_optional) {
    pos_register_status = pos_register_status_create(
    );
  } else {
    pos_register_status = pos_register_status_create(
    );
  }

  return pos_register_status;
}


#ifdef pos_register_status_MAIN

void test_pos_register_status(int include_optional) {
    pos_register_status_t* pos_register_status_1 = instantiate_pos_register_status(include_optional);

	cJSON* jsonpos_register_status_1 = pos_register_status_convertToJSON(pos_register_status_1);
	printf("pos_register_status :\n%s\n", cJSON_Print(jsonpos_register_status_1));
	pos_register_status_t* pos_register_status_2 = pos_register_status_parseFromJSON(jsonpos_register_status_1);
	cJSON* jsonpos_register_status_2 = pos_register_status_convertToJSON(pos_register_status_2);
	printf("repeating pos_register_status:\n%s\n", cJSON_Print(jsonpos_register_status_2));
}

int main() {
  test_pos_register_status(1);
  test_pos_register_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // pos_register_status_MAIN
#endif // pos_register_status_TEST
