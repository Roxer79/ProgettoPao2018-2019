#ifndef FILEECCEZIONIPRINTASCHERMO_H
#define FILEECCEZIONIPRINTASCHERMO_H

#include <string>
#include <iostream>

class FileEccezioniPrintSchermo {
private:
    std::string eccezione;
public:
    FileEccezioniPrintSchermo(std::string);
    std::string getEccezione() const;
    void stampaErroreSchermo() const;
};

#endif // FILEECCEZIONIPRINTASCHERMO_H
