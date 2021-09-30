#ifndef APP_CONTAINER_H
#define APP_CONTAINER_H

#include <gtk/gtk.h>
#include <stdlib.h>

typedef struct AppGlobal {
    GtkWidget *main_window;
    GtkTextBuffer *editor_buffer;
    char *current_file;
} AppGlobal;

extern AppGlobal app_global;

void
set_app_global(AppGlobal *app);

AppGlobal *
get_app_global();

#endif