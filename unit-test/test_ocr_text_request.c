#ifndef ocr_text_request_TEST
#define ocr_text_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ocr_text_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ocr_text_request.h"
ocr_text_request_t* instantiate_ocr_text_request(int include_optional);



ocr_text_request_t* instantiate_ocr_text_request(int include_optional) {
  ocr_text_request_t* ocr_text_request = NULL;
  if (include_optional) {
    ocr_text_request = ocr_text_request_create(
      "0"
    );
  } else {
    ocr_text_request = ocr_text_request_create(
      "0"
    );
  }

  return ocr_text_request;
}


#ifdef ocr_text_request_MAIN

void test_ocr_text_request(int include_optional) {
    ocr_text_request_t* ocr_text_request_1 = instantiate_ocr_text_request(include_optional);

	cJSON* jsonocr_text_request_1 = ocr_text_request_convertToJSON(ocr_text_request_1);
	printf("ocr_text_request :\n%s\n", cJSON_Print(jsonocr_text_request_1));
	ocr_text_request_t* ocr_text_request_2 = ocr_text_request_parseFromJSON(jsonocr_text_request_1);
	cJSON* jsonocr_text_request_2 = ocr_text_request_convertToJSON(ocr_text_request_2);
	printf("repeating ocr_text_request:\n%s\n", cJSON_Print(jsonocr_text_request_2));
}

int main() {
  test_ocr_text_request(1);
  test_ocr_text_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // ocr_text_request_MAIN
#endif // ocr_text_request_TEST
