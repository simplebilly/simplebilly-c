#ifndef time_entry_dto_TEST
#define time_entry_dto_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define time_entry_dto_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/time_entry_dto.h"
time_entry_dto_t* instantiate_time_entry_dto(int include_optional);



time_entry_dto_t* instantiate_time_entry_dto(int include_optional) {
  time_entry_dto_t* time_entry_dto = NULL;
  if (include_optional) {
    time_entry_dto = time_entry_dto_create(
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    time_entry_dto = time_entry_dto_create(
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20T19:20:30+01:00",
      "2013-10-20",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return time_entry_dto;
}


#ifdef time_entry_dto_MAIN

void test_time_entry_dto(int include_optional) {
    time_entry_dto_t* time_entry_dto_1 = instantiate_time_entry_dto(include_optional);

	cJSON* jsontime_entry_dto_1 = time_entry_dto_convertToJSON(time_entry_dto_1);
	printf("time_entry_dto :\n%s\n", cJSON_Print(jsontime_entry_dto_1));
	time_entry_dto_t* time_entry_dto_2 = time_entry_dto_parseFromJSON(jsontime_entry_dto_1);
	cJSON* jsontime_entry_dto_2 = time_entry_dto_convertToJSON(time_entry_dto_2);
	printf("repeating time_entry_dto:\n%s\n", cJSON_Print(jsontime_entry_dto_2));
}

int main() {
  test_time_entry_dto(1);
  test_time_entry_dto(0);

  printf("Hello world \n");
  return 0;
}

#endif // time_entry_dto_MAIN
#endif // time_entry_dto_TEST
