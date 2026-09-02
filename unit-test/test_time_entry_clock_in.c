#ifndef time_entry_clock_in_TEST
#define time_entry_clock_in_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define time_entry_clock_in_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/time_entry_clock_in.h"
time_entry_clock_in_t* instantiate_time_entry_clock_in(int include_optional);



time_entry_clock_in_t* instantiate_time_entry_clock_in(int include_optional) {
  time_entry_clock_in_t* time_entry_clock_in = NULL;
  if (include_optional) {
    time_entry_clock_in = time_entry_clock_in_create(
      "0"
    );
  } else {
    time_entry_clock_in = time_entry_clock_in_create(
      "0"
    );
  }

  return time_entry_clock_in;
}


#ifdef time_entry_clock_in_MAIN

void test_time_entry_clock_in(int include_optional) {
    time_entry_clock_in_t* time_entry_clock_in_1 = instantiate_time_entry_clock_in(include_optional);

	cJSON* jsontime_entry_clock_in_1 = time_entry_clock_in_convertToJSON(time_entry_clock_in_1);
	printf("time_entry_clock_in :\n%s\n", cJSON_Print(jsontime_entry_clock_in_1));
	time_entry_clock_in_t* time_entry_clock_in_2 = time_entry_clock_in_parseFromJSON(jsontime_entry_clock_in_1);
	cJSON* jsontime_entry_clock_in_2 = time_entry_clock_in_convertToJSON(time_entry_clock_in_2);
	printf("repeating time_entry_clock_in:\n%s\n", cJSON_Print(jsontime_entry_clock_in_2));
}

int main() {
  test_time_entry_clock_in(1);
  test_time_entry_clock_in(0);

  printf("Hello world \n");
  return 0;
}

#endif // time_entry_clock_in_MAIN
#endif // time_entry_clock_in_TEST
