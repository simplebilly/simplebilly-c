#ifndef pos_table_TEST
#define pos_table_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pos_table_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pos_table.h"
pos_table_t* instantiate_pos_table(int include_optional);



pos_table_t* instantiate_pos_table(int include_optional) {
  pos_table_t* pos_table = NULL;
  if (include_optional) {
    pos_table = pos_table_create(
      "0",
      "0",
      simplebilly_api_pos_table__free
    );
  } else {
    pos_table = pos_table_create(
      "0",
      "0",
      simplebilly_api_pos_table__free
    );
  }

  return pos_table;
}


#ifdef pos_table_MAIN

void test_pos_table(int include_optional) {
    pos_table_t* pos_table_1 = instantiate_pos_table(include_optional);

	cJSON* jsonpos_table_1 = pos_table_convertToJSON(pos_table_1);
	printf("pos_table :\n%s\n", cJSON_Print(jsonpos_table_1));
	pos_table_t* pos_table_2 = pos_table_parseFromJSON(jsonpos_table_1);
	cJSON* jsonpos_table_2 = pos_table_convertToJSON(pos_table_2);
	printf("repeating pos_table:\n%s\n", cJSON_Print(jsonpos_table_2));
}

int main() {
  test_pos_table(1);
  test_pos_table(0);

  printf("Hello world \n");
  return 0;
}

#endif // pos_table_MAIN
#endif // pos_table_TEST
