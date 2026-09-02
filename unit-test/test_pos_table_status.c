#ifndef pos_table_status_TEST
#define pos_table_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pos_table_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pos_table_status.h"
pos_table_status_t* instantiate_pos_table_status(int include_optional);



pos_table_status_t* instantiate_pos_table_status(int include_optional) {
  pos_table_status_t* pos_table_status = NULL;
  if (include_optional) {
    pos_table_status = pos_table_status_create(
    );
  } else {
    pos_table_status = pos_table_status_create(
    );
  }

  return pos_table_status;
}


#ifdef pos_table_status_MAIN

void test_pos_table_status(int include_optional) {
    pos_table_status_t* pos_table_status_1 = instantiate_pos_table_status(include_optional);

	cJSON* jsonpos_table_status_1 = pos_table_status_convertToJSON(pos_table_status_1);
	printf("pos_table_status :\n%s\n", cJSON_Print(jsonpos_table_status_1));
	pos_table_status_t* pos_table_status_2 = pos_table_status_parseFromJSON(jsonpos_table_status_1);
	cJSON* jsonpos_table_status_2 = pos_table_status_convertToJSON(pos_table_status_2);
	printf("repeating pos_table_status:\n%s\n", cJSON_Print(jsonpos_table_status_2));
}

int main() {
  test_pos_table_status(1);
  test_pos_table_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // pos_table_status_MAIN
#endif // pos_table_status_TEST
