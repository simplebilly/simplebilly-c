#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/notification_dto.h"


void
NotificationsAPI_deleteNotification(apiClient_t *apiClient, char *id);


list_t*
NotificationsAPI_listNotifications(apiClient_t *apiClient);


long
NotificationsAPI_markAllRead(apiClient_t *apiClient);


void
NotificationsAPI_markAsRead(apiClient_t *apiClient, char *id);


long
NotificationsAPI_unreadCount(apiClient_t *apiClient);


