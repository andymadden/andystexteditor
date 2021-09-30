#include "app_container.h"

AppGlobal *app_global;

AppGlobal *
get_app()
{
    return app_global;
}

void
set_app(AppGlobal *app)
{
    app_global = app;
}