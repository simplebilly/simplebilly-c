#ifndef group_figure_create_TEST
#define group_figure_create_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define group_figure_create_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/group_figure_create.h"
group_figure_create_t* instantiate_group_figure_create(int include_optional);



group_figure_create_t* instantiate_group_figure_create(int include_optional) {
  group_figure_create_t* group_figure_create = NULL;
  if (include_optional) {
    group_figure_create = group_figure_create_create(
      "0",
      1,
      56,
      "0",
      "0",
      "0"
    );
  } else {
    group_figure_create = group_figure_create_create(
      "0",
      1,
      56,
      "0",
      "0",
      "0"
    );
  }

  return group_figure_create;
}


#ifdef group_figure_create_MAIN

void test_group_figure_create(int include_optional) {
    group_figure_create_t* group_figure_create_1 = instantiate_group_figure_create(include_optional);

	cJSON* jsongroup_figure_create_1 = group_figure_create_convertToJSON(group_figure_create_1);
	printf("group_figure_create :\n%s\n", cJSON_Print(jsongroup_figure_create_1));
	group_figure_create_t* group_figure_create_2 = group_figure_create_parseFromJSON(jsongroup_figure_create_1);
	cJSON* jsongroup_figure_create_2 = group_figure_create_convertToJSON(group_figure_create_2);
	printf("repeating group_figure_create:\n%s\n", cJSON_Print(jsongroup_figure_create_2));
}

int main() {
  test_group_figure_create(1);
  test_group_figure_create(0);

  printf("Hello world \n");
  return 0;
}

#endif // group_figure_create_MAIN
#endif // group_figure_create_TEST
