#include "app_container.h"

AppGlobal app_global;

void
set_app_global(AppGlobal *app)
{
    app_global.current_file = app->current_file;
    app_global.editor_buffer = app->editor_buffer;
    app_global.main_window = app->main_window;
}

AppGlobal *
get_app_global()
{
    return &app_global;
}