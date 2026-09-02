#ifndef create_channel_dto_TEST
#define create_channel_dto_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_channel_dto_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_channel_dto.h"
create_channel_dto_t* instantiate_create_channel_dto(int include_optional);



create_channel_dto_t* instantiate_create_channel_dto(int include_optional) {
  create_channel_dto_t* create_channel_dto = NULL;
  if (include_optional) {
    create_channel_dto = create_channel_dto_create(
      "0",
      null,
      "0"
    );
  } else {
    create_channel_dto = create_channel_dto_create(
      "0",
      null,
      "0"
    );
  }

  return create_channel_dto;
}


#ifdef create_channel_dto_MAIN

void test_create_channel_dto(int include_optional) {
    create_channel_dto_t* create_channel_dto_1 = instantiate_create_channel_dto(include_optional);

	cJSON* jsoncreate_channel_dto_1 = create_channel_dto_convertToJSON(create_channel_dto_1);
	printf("create_channel_dto :\n%s\n", cJSON_Print(jsoncreate_channel_dto_1));
	create_channel_dto_t* create_channel_dto_2 = create_channel_dto_parseFromJSON(jsoncreate_channel_dto_1);
	cJSON* jsoncreate_channel_dto_2 = create_channel_dto_convertToJSON(create_channel_dto_2);
	printf("repeating create_channel_dto:\n%s\n", cJSON_Print(jsoncreate_channel_dto_2));
}

int main() {
  test_create_channel_dto(1);
  test_create_channel_dto(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_channel_dto_MAIN
#endif // create_channel_dto_TEST
