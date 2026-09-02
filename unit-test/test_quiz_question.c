#ifndef quiz_question_TEST
#define quiz_question_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define quiz_question_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/quiz_question.h"
quiz_question_t* instantiate_quiz_question(int include_optional);



quiz_question_t* instantiate_quiz_question(int include_optional) {
  quiz_question_t* quiz_question = NULL;
  if (include_optional) {
    quiz_question = quiz_question_create(
      "0",
      list_createList(),
      list_createList(),
      "0",
      "0"
    );
  } else {
    quiz_question = quiz_question_create(
      "0",
      list_createList(),
      list_createList(),
      "0",
      "0"
    );
  }

  return quiz_question;
}


#ifdef quiz_question_MAIN

void test_quiz_question(int include_optional) {
    quiz_question_t* quiz_question_1 = instantiate_quiz_question(include_optional);

	cJSON* jsonquiz_question_1 = quiz_question_convertToJSON(quiz_question_1);
	printf("quiz_question :\n%s\n", cJSON_Print(jsonquiz_question_1));
	quiz_question_t* quiz_question_2 = quiz_question_parseFromJSON(jsonquiz_question_1);
	cJSON* jsonquiz_question_2 = quiz_question_convertToJSON(quiz_question_2);
	printf("repeating quiz_question:\n%s\n", cJSON_Print(jsonquiz_question_2));
}

int main() {
  test_quiz_question(1);
  test_quiz_question(0);

  printf("Hello world \n");
  return 0;
}

#endif // quiz_question_MAIN
#endif // quiz_question_TEST
