#include "mainwindow.h"
#include <QApplication>
#include "watchpoint.h"

void init_monitor(int, char *[]);
void restart();
void ui_mainloop();


int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    MainWindow w;
    w.show();
    /* Initialize the monitor. */
    init_monitor(argc, argv);

    /* Test the implementation of the `CPU_state' structure. */
    //reg_test();

    /* Initialize the virtual computer system. */
    restart();
    /* Receive commands from user. */
//    ui_mainloop();
//    w.mainloop();

//	return 0;
    printf("main startloop\n");
    init_wp_pool();
    //w.mainloop();
    return a.exec();
}
