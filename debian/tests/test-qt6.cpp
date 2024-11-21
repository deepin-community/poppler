#include <poppler-qt6.h>
#include <QtCore/QFile>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  if (argc < 2)
    return EXIT_FAILURE;

  std::unique_ptr<Poppler::Document> doc = Poppler::Document::load(QFile::decodeName(argv[1]));
  Q_ASSERT(doc);
  Q_ASSERT(!doc->isLocked());

  int n_pages = doc->numPages();
  Q_ASSERT(n_pages > 0);

  return EXIT_SUCCESS;
}
