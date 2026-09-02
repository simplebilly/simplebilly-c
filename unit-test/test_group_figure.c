#ifndef group_figure_TEST
#define group_figure_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define group_figure_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/group_figure.h"
group_figure_t* instantiate_group_figure(int include_optional);



group_figure_t* instantiate_group_figure(int include_optional) {
  group_figure_t* group_figure = NULL;
  if (include_optional) {
    group_figure = group_figure_create(
      "0",
      1,
      56,
      "0",
      "0",
      "0",
      56
    );
  } else {
    group_figure = group_figure_create(
      "0",
      1,
      56,
      "0",
      "0",
      "0",
      56
    );
  }

  return group_figure;
}


#ifdef group_figure_MAIN

void test_group_figure(int include_optional) {
    group_figure_t* group_figure_1 = instantiate_group_figure(include_optional);

	cJSON* jsongroup_figure_1 = group_figure_convertToJSON(group_figure_1);
	printf("group_figure :\n%s\n", cJSON_Print(jsongroup_figure_1));
	group_figure_t* group_figure_2 = group_figure_parseFromJSON(jsongroup_figure_1);
	cJSON* jsongroup_figure_2 = group_figure_convertToJSON(group_figure_2);
	printf("repeating group_figure:\n%s\n", cJSON_Print(jsongroup_figure_2));
}

int main() {
  test_group_figure(1);
  test_group_figure(0);

  printf("Hello world \n");
  return 0;
}

#endif // group_figure_MAIN
#endif // group_figure_TEST
