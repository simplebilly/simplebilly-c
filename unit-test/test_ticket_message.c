#ifndef ticket_message_TEST
#define ticket_message_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ticket_message_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ticket_message.h"
ticket_message_t* instantiate_ticket_message(int include_optional);



ticket_message_t* instantiate_ticket_message(int include_optional) {
  ticket_message_t* ticket_message = NULL;
  if (include_optional) {
    ticket_message = ticket_message_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      simplebilly_api_ticket_message__inbound,
      "0",
      1,
      simplebilly_api_ticket_message__text,
      null,
      "0",
      "0"
    );
  } else {
    ticket_message = ticket_message_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "2013-10-20T19:20:30+01:00",
      simplebilly_api_ticket_message__inbound,
      "0",
      1,
      simplebilly_api_ticket_message__text,
      null,
      "0",
      "0"
    );
  }

  return ticket_message;
}


#ifdef ticket_message_MAIN

void test_ticket_message(int include_optional) {
    ticket_message_t* ticket_message_1 = instantiate_ticket_message(include_optional);

	cJSON* jsonticket_message_1 = ticket_message_convertToJSON(ticket_message_1);
	printf("ticket_message :\n%s\n", cJSON_Print(jsonticket_message_1));
	ticket_message_t* ticket_message_2 = ticket_message_parseFromJSON(jsonticket_message_1);
	cJSON* jsonticket_message_2 = ticket_message_convertToJSON(ticket_message_2);
	printf("repeating ticket_message:\n%s\n", cJSON_Print(jsonticket_message_2));
}

int main() {
  test_ticket_message(1);
  test_ticket_message(0);

  printf("Hello world \n");
  return 0;
}

#endif // ticket_message_MAIN
#endif // ticket_message_TEST
