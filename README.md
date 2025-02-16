ISTRUZIONI PER L'UTILIZZO DEL PROGETTO:
  1)Assicurarsi di aver installato le librerie di QT sul proprio computer
  2)Scaricare la cartella ed aprirla dalla riga di comando nella propria directory corrente
  3)Una volta aperta la cartella digitare "qmake -project"
  4)Andare ora nella cartella ed aprire i file .pro
  5)Aggiungere le riga "QT += widgets" sotto "INCLUDEPATH += ." a riga 7 
  6)Andare a capo ed aggiungere la riga "RESOURCES += risorse.qrc" e salvare il file .pro
  7)Tornare alla riga di comando e digitare "qmake && make" (vanno bene anche i due comandi separatamente, qmake va prima di make)
  8)Entrare nella cartella ed aprire il file applicazione oppure digitare "./Progetto-Programmazione-ad-oggetti-2025"

DISLAIMER : tutti i comandi sono stati messi tra "". Nella riga di comando e nel file .pro gli apici vanno omessi.
  
