# RX (Receiver) RFM cez SPI

## Teoretický základ
RX RFM (prijímač) je zariadenie, ktoré prijíma dáta od vysielača (TX RFM). Využíva SPI na komunikáciu so STM32 a dekóduje prijaté pakety na interpretovateľné dáta.

## Proces fungovania

1. **Príjem bezdrôtového signálu:**
   - RX RFM modul neustále monitoruje nastavenú frekvenciu.
   - Ak deteguje rádiový signál, začne proces dekódovania dát.

2. **Dekódovanie prijatého signálu:**
   - RFM modul extrahuje prijaté dáta zo signálu.
   - Dekóduje ich, odstraňuje šifrovanie a overuje integritu pomocou kontrolného súčtu (CRC).

3. **Prenos dát do STM32 cez SPI:**
   - Dekódované dáta sú posielané do STM32 cez SPI protokol:
     - **MISO (Master In Slave Out):** Dáta idú z RFM do STM32.
     - **SCK (Serial Clock):** Hodinový signál synchronizuje prenos.
     - **SS (Slave Select):** Aktivuje RX RFM modul na odosielanie dát.

4. **Spracovanie dát STM32:**
   - STM32 prijaté dáta interpretuje a vykoná zodpovedajúce akcie, napríklad pohyb motorov na základe príkazov.

## Prínosy RX RFM cez SPI
- Spoľahlivý príjem dát na dlhšie vzdialenosti.
- Integrovaná kontrola integrity dát.
- Široká kompatibilita s rôznymi typmi mikrokontrolérov.
