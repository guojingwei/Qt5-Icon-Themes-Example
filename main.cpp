
#include <QApplication>
#include <QFrame>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  // Create a layout and two buttons
  QVBoxLayout *l = new QVBoxLayout;
  QPushButton *b1 = new QPushButton("Button 1");
  QPushButton *b2 = new QPushButton("Button 2");
  l->addWidget( b1 );
  l->addWidget( b2 );

  // OPTIONAL: Set your own icon pack. By default, Qt will search in :icons/
  QIcon::setThemeName( "zafiro" );
  // If we request an icon that is not found in the icon pack, search in the :custom-icons folder.
  QIcon::setFallbackSearchPaths(QIcon::fallbackSearchPaths() << ":custom-icons");

  // Set icons from theme
  b1->setIcon( QIcon::fromTheme("folder-alt") ); // Most Linux icon packs will have a "folder-alt" icon.
  b2->setIcon( QIcon::fromTheme("open-app-library") ); // If this does not exist in icon pack (It won't), it will search :custom-icons/

  // Create a frame that uses layout and show widgets
  QFrame *f = new QFrame;
  f->setLayout(l);
  f->show();

  return a.exec();
}
