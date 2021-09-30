#include <string.h>
#include <json-c/json_object.h>
#include <json-c/json_tokener.h>
#include "fileio.h"
#include "app_windows.h"
#include "app_container.h"

int
main(int argc,
     char *argv[])
{
    gtk_init(&argc, &argv);

    struct AppMainWindow mainWindow = create_main_window();

    AppGlobal mainApp;

    mainApp.main_window = mainWindow.window;
    mainApp.editor_buffer = mainWindow.editor_buffer;
    mainApp.current_file = "";

    set_app_global(&mainApp);

    gtk_main();

    return 0;
}