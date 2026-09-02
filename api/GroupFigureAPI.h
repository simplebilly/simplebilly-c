#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/group_figure.h"
#include "../model/group_figure_create.h"
#include "../model/group_figure_update.h"
#include "../model/plugin_error.h"


group_figure_t*
GroupFigureAPI_createGroupFigure(apiClient_t *apiClient, group_figure_create_t *group_figure_create);


void
GroupFigureAPI_deleteGroupFigure(apiClient_t *apiClient, int *year);


group_figure_t*
GroupFigureAPI_getGroupFigure(apiClient_t *apiClient, int *year);


list_t*
GroupFigureAPI_getGroupFigures(apiClient_t *apiClient, int *page, int *page_size, char *search, int *include_deleted);


group_figure_t*
GroupFigureAPI_updateGroupFigure(apiClient_t *apiClient, int *year, group_figure_update_t *group_figure_update);


