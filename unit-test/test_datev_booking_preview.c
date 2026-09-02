#ifndef datev_booking_preview_TEST
#define datev_booking_preview_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define datev_booking_preview_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/datev_booking_preview.h"
datev_booking_preview_t* instantiate_datev_booking_preview(int include_optional);



datev_booking_preview_t* instantiate_datev_booking_preview(int include_optional) {
  datev_booking_preview_t* datev_booking_preview = NULL;
  if (include_optional) {
    datev_booking_preview = datev_booking_preview_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    datev_booking_preview = datev_booking_preview_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return datev_booking_preview;
}


#ifdef datev_booking_preview_MAIN

void test_datev_booking_preview(int include_optional) {
    datev_booking_preview_t* datev_booking_preview_1 = instantiate_datev_booking_preview(include_optional);

	cJSON* jsondatev_booking_preview_1 = datev_booking_preview_convertToJSON(datev_booking_preview_1);
	printf("datev_booking_preview :\n%s\n", cJSON_Print(jsondatev_booking_preview_1));
	datev_booking_preview_t* datev_booking_preview_2 = datev_booking_preview_parseFromJSON(jsondatev_booking_preview_1);
	cJSON* jsondatev_booking_preview_2 = datev_booking_preview_convertToJSON(datev_booking_preview_2);
	printf("repeating datev_booking_preview:\n%s\n", cJSON_Print(jsondatev_booking_preview_2));
}

int main() {
  test_datev_booking_preview(1);
  test_datev_booking_preview(0);

  printf("Hello world \n");
  return 0;
}

#endif // datev_booking_preview_MAIN
#endif // datev_booking_preview_TEST
