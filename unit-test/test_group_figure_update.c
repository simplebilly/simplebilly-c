#ifndef group_figure_update_TEST
#define group_figure_update_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define group_figure_update_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/group_figure_update.h"
group_figure_update_t* instantiate_group_figure_update(int include_optional);



group_figure_update_t* instantiate_group_figure_update(int include_optional) {
  group_figure_update_t* group_figure_update = NULL;
  if (include_optional) {
    group_figure_update = group_figure_update_create(
      "0",
      1,
      56,
      "0",
      "0",
      "0"
    );
  } else {
    group_figure_update = group_figure_update_create(
      "0",
      1,
      56,
      "0",
      "0",
      "0"
    );
  }

  return group_figure_update;
}


#ifdef group_figure_update_MAIN

void test_group_figure_update(int include_optional) {
    group_figure_update_t* group_figure_update_1 = instantiate_group_figure_update(include_optional);

	cJSON* jsongroup_figure_update_1 = group_figure_update_convertToJSON(group_figure_update_1);
	printf("group_figure_update :\n%s\n", cJSON_Print(jsongroup_figure_update_1));
	group_figure_update_t* group_figure_update_2 = group_figure_update_parseFromJSON(jsongroup_figure_update_1);
	cJSON* jsongroup_figure_update_2 = group_figure_update_convertToJSON(group_figure_update_2);
	printf("repeating group_figure_update:\n%s\n", cJSON_Print(jsongroup_figure_update_2));
}

int main() {
  test_group_figure_update(1);
  test_group_figure_update(0);

  printf("Hello world \n");
  return 0;
}

#endif // group_figure_update_MAIN
#endif // group_figure_update_TEST
