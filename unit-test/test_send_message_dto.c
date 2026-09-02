#ifndef send_message_dto_TEST
#define send_message_dto_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_message_dto_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_message_dto.h"
send_message_dto_t* instantiate_send_message_dto(int include_optional);



send_message_dto_t* instantiate_send_message_dto(int include_optional) {
  send_message_dto_t* send_message_dto = NULL;
  if (include_optional) {
    send_message_dto = send_message_dto_create(
      "0",
      1
    );
  } else {
    send_message_dto = send_message_dto_create(
      "0",
      1
    );
  }

  return send_message_dto;
}


#ifdef send_message_dto_MAIN

void test_send_message_dto(int include_optional) {
    send_message_dto_t* send_message_dto_1 = instantiate_send_message_dto(include_optional);

	cJSON* jsonsend_message_dto_1 = send_message_dto_convertToJSON(send_message_dto_1);
	printf("send_message_dto :\n%s\n", cJSON_Print(jsonsend_message_dto_1));
	send_message_dto_t* send_message_dto_2 = send_message_dto_parseFromJSON(jsonsend_message_dto_1);
	cJSON* jsonsend_message_dto_2 = send_message_dto_convertToJSON(send_message_dto_2);
	printf("repeating send_message_dto:\n%s\n", cJSON_Print(jsonsend_message_dto_2));
}

int main() {
  test_send_message_dto(1);
  test_send_message_dto(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_message_dto_MAIN
#endif // send_message_dto_TEST
