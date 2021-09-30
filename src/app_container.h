#ifndef APP_CONTAINER_H
#define APP_CONTAINER_H

#include <gtk/gtk.h>

typedef struct AppGlobal {
    GtkWidget *main_window;
    GtkTextBuffer *editor_buffer;
    char *current_file;
} AppGlobal;

AppGlobal *app_global;

AppGlobal *
get_app();

void
set_app(AppGlobal *app);

#endif