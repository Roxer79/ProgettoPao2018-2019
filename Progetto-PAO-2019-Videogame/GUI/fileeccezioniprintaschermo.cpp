#include "GUI/fileeccezioniprintaschermo.h"

FileEccezioniPrintSchermo::FileEccezioniPrintSchermo(std::string w): eccezione(w) {}

std::string FileEccezioniPrintSchermo::getEccezione() const { return eccezione; }

void FileEccezioniPrintSchermo::stampaErroreSchermo() const {
    std::cout << "Errore: " << getEccezione();
}
