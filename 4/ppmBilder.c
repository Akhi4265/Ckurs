#include <stdio.h>
#include <stdlib.h>
struct pixel {
    int rot, gruen, blau;
};

struct ppm_bild{
    int breite, hoehe;
    int maxHelligkeit;

    struct pixel *leinwand;
};

void schreibe_ppm(const char *dateiname, struct ppm_bild *bild) {
    FILE *datei = fopen(dateiname, "w");
    if (datei == NULL) {
        fprintf(stderr, "Fehler: Datei konnte nicht geöffnet werden.\n");
        return;
    }

    // PPM-Header schreiben
    fprintf(datei, "P3\n%d %d\n%d\n", bild->breite, bild->hoehe, bild->maxHelligkeit);

    // Pixelwerte korrekt schreiben
    for (int i = 0; i < bild->breite * bild->hoehe; i++) {
        fprintf(datei, "%d %d %d", 
                bild->leinwand[i].rot, 
                bild->leinwand[i].gruen, 
                bild->leinwand[i].blau);

        if ((i + 1) % bild->breite == 0) {
            fprintf(datei, "\n");  // Neue Zeile nach jeder vollständigen Zeile im Bild
        } else {
            fprintf(datei, " ");  // Leerzeichen zwischen den Pixeln
        }
    }

    fclose(datei);
}



struct ppm_bild *lese_ppm(const char *dateiname) {
    FILE *datei = fopen(dateiname, "r");
    if (datei == NULL) {
        fprintf(stderr, "Fehler: Datei konnte nicht geöffnet werden.\n");
        return NULL;
    }

    struct ppm_bild *bild = malloc(sizeof(struct ppm_bild));
    if (bild == NULL) {
        fprintf(stderr, "Fehler: Speicher konnte nicht allokiert werden.\n");
        fclose(datei);
        return NULL;
    }

    char format[3];
    fscanf(datei, "%2s", format);
    if (format[0] != 'P' || format[1] != '3') {
        fprintf(stderr, "Fehler: Falsches PPM-Format (nur P3 wird unterstützt).\n");
        fclose(datei);
        free(bild);
        return NULL;
    }

    fscanf(datei, "%d %d %d", &bild->breite, &bild->hoehe, &bild->maxHelligkeit);
    
    bild->leinwand = malloc(bild->breite * bild->hoehe * sizeof(struct pixel));
    if (bild->leinwand == NULL) {
        fprintf(stderr, "Fehler: Speicher für Bild konnte nicht allokiert werden.\n");
        fclose(datei);
        free(bild);
        return NULL;
    }

    // Pixelwerte einlesen
    for (int i = 0; i < bild->breite * bild->hoehe; i++) {
        fscanf(datei, "%d %d %d", 
               &bild->leinwand[i].rot, 
               &bild->leinwand[i].gruen, 
               &bild->leinwand[i].blau);
    }

    fclose(datei);
    return bild;
}


int main() {
    struct ppm_bild bild;
    bild.breite = 40;
    bild.hoehe = 40;
    bild.maxHelligkeit = 255;
    
    // Speicher für das Bild allokieren
    bild.leinwand = malloc(bild.breite * bild.hoehe * sizeof(struct pixel));

    if (bild.leinwand == NULL) {
        fprintf(stderr, "Fehler: Speicher konnte nicht allokiert werden.\n");
        return 1;
    }
    int farbe = 0;
    for (int y = 0; y < bild.hoehe; y++) {
        farbe += 3;
        farbe = farbe % 256;
        for (int x = 0; x < bild.breite; x++) {
            int i = y * bild.breite + x; // Index im Array
            
    
            bild.leinwand[i].rot = (farbe * 5) % 256;
            bild.leinwand[i].gruen = (farbe * 7) % 256;
            bild.leinwand[i].blau = (farbe * 13) % 256;
            
        }
    }
    
    // Bild speichern
    schreibe_ppm("testbild.ppm", &bild);

    // Bild aus Datei laden
    struct ppm_bild *geladenes_bild = lese_ppm("testbild.ppm");
    if (geladenes_bild != NULL) {
        printf("Das Bild wurde erfolgreich gespeichert und geladen!\n");
        free(geladenes_bild->leinwand);
        free(geladenes_bild);
    }

    free(bild.leinwand);
    return 0;
}
