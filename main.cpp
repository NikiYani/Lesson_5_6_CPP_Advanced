#include <QCoreApplication>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

using namespace std;

mutex m;

void foo()
{
    lock_guard< mutex > guard( m );
    cout << "First" << endl;
}

void foo2()
{
    lock_guard< mutex > guard( m );
    cout << "Second" << endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    thread t1( foo );
    thread t2( foo2 );

    t1.join();
    t2.join();

    return a.exec();
}
