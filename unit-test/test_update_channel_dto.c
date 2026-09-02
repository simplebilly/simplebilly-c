#ifndef update_channel_dto_TEST
#define update_channel_dto_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define update_channel_dto_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/update_channel_dto.h"
update_channel_dto_t* instantiate_update_channel_dto(int include_optional);



update_channel_dto_t* instantiate_update_channel_dto(int include_optional) {
  update_channel_dto_t* update_channel_dto = NULL;
  if (include_optional) {
    update_channel_dto = update_channel_dto_create(
      null,
      1,
      "0"
    );
  } else {
    update_channel_dto = update_channel_dto_create(
      null,
      1,
      "0"
    );
  }

  return update_channel_dto;
}


#ifdef update_channel_dto_MAIN

void test_update_channel_dto(int include_optional) {
    update_channel_dto_t* update_channel_dto_1 = instantiate_update_channel_dto(include_optional);

	cJSON* jsonupdate_channel_dto_1 = update_channel_dto_convertToJSON(update_channel_dto_1);
	printf("update_channel_dto :\n%s\n", cJSON_Print(jsonupdate_channel_dto_1));
	update_channel_dto_t* update_channel_dto_2 = update_channel_dto_parseFromJSON(jsonupdate_channel_dto_1);
	cJSON* jsonupdate_channel_dto_2 = update_channel_dto_convertToJSON(update_channel_dto_2);
	printf("repeating update_channel_dto:\n%s\n", cJSON_Print(jsonupdate_channel_dto_2));
}

int main() {
  test_update_channel_dto(1);
  test_update_channel_dto(0);

  printf("Hello world \n");
  return 0;
}

#endif // update_channel_dto_MAIN
#endif // update_channel_dto_TEST
