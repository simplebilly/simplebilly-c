#ifndef pos_table_create_TEST
#define pos_table_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pos_table_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pos_table_create.h"
pos_table_create_t* instantiate_pos_table_create(int include_optional);



pos_table_create_t* instantiate_pos_table_create(int include_optional) {
  pos_table_create_t* pos_table_create = NULL;
  if (include_optional) {
    pos_table_create = pos_table_create_create(
      "0",
      "0",
      simplebilly_api_pos_table_create__free
    );
  } else {
    pos_table_create = pos_table_create_create(
      "0",
      "0",
      simplebilly_api_pos_table_create__free
    );
  }

  return pos_table_create;
}


#ifdef pos_table_create_MAIN

void test_pos_table_create(int include_optional) {
    pos_table_create_t* pos_table_create_1 = instantiate_pos_table_create(include_optional);

	cJSON* jsonpos_table_create_1 = pos_table_create_convertToJSON(pos_table_create_1);
	printf("pos_table_create :\n%s\n", cJSON_Print(jsonpos_table_create_1));
	pos_table_create_t* pos_table_create_2 = pos_table_create_parseFromJSON(jsonpos_table_create_1);
	cJSON* jsonpos_table_create_2 = pos_table_create_convertToJSON(pos_table_create_2);
	printf("repeating pos_table_create:\n%s\n", cJSON_Print(jsonpos_table_create_2));
}

int main() {
  test_pos_table_create(1);
  test_pos_table_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // pos_table_create_MAIN
#endif // pos_table_create_TEST
