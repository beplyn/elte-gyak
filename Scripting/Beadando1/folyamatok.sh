#!/bin/bash
# folyamatok.sh - kepzelt futo folyamatok kezelese (MI altal keszitett megoldas)
#
# Fajlformatum (indulo.dat, aktualis.dat), soronkent egy folyamat:
#   PID;NEV;STATUSZ      pl.  101;systemd;S
#   STATUSZ: S = fut (sleeping/running), T = terminalt (stopped)
#
# Hasznalat:
#   ./folyamatok.sh -start <alkalmazas neve>
#   ./folyamatok.sh -stop  <PID>
#   ./folyamatok.sh -kill  <PID>
#   ./folyamatok.sh -lista
#   ./folyamatok.sh -boot          (ujrainditas: aktualis.dat = indulo.dat)

INDULO="indulo.dat"
AKTUALIS="aktualis.dat"

hasznalat() {
    echo "Hasznalat:"
    echo "  $0 -start <alkalmazas neve>   uj folyamat inditasa"
    echo "  $0 -stop <PID>                folyamat leallitasa (S -> T)"
    echo "  $0 -kill <PID>                folyamat torlese"
    echo "  $0 -lista                     folyamatok listazasa"
    echo "  $0 -boot                      bekapcsolas (aktualis.dat ujrairasa indulo.dat-bol)"
    exit 1
}

# Bekapcsolas: ha meg nincs aktualis.dat, az indulo folyamatokbol jon letre
inicializal() {
    if [ ! -f "$AKTUALIS" ]; then
        if [ ! -f "$INDULO" ]; then
            echo "Hiba: nem talalhato a(z) $INDULO fajl!" >&2
            exit 2
        fi
        cp "$INDULO" "$AKTUALIS"
    fi
}

# PID ellenorzese: csak pozitiv egesz szam lehet
pid_ellenoriz() {
    if ! [[ "$1" =~ ^[0-9]+$ ]]; then
        echo "Hiba: ervenytelen PID: '$1'" >&2
        exit 3
    fi
    if ! grep -q "^$1;" "$AKTUALIS"; then
        echo "Hiba: nincs $1 PID-u folyamat!" >&2
        exit 4
    fi
}

# A kapcsolo elejen allo kotojelek (-, --, –) egysegesitese
kapcsolo="${1#–}"
kapcsolo="${kapcsolo#--}"
kapcsolo="${kapcsolo#-}"

[ $# -lt 1 ] && hasznalat

case "$kapcsolo" in
    boot)
        [ ! -f "$INDULO" ] && { echo "Hiba: nem talalhato a(z) $INDULO fajl!" >&2; exit 2; }
        cp "$INDULO" "$AKTUALIS"
        echo "Rendszer elinditva, $(grep -c . "$AKTUALIS") folyamat fut."
        ;;
    start)
        [ $# -lt 2 ] && { echo "Hiba: adja meg az alkalmazas nevet!" >&2; exit 1; }
        inicializal
        shift
        nev="$*"
        # A pontosvesszo az elvalaszto, a nevben nem szerepelhet
        nev="${nev//;/_}"
        # Uj PID: a legnagyobb meglevo PID + 1 (ures fajl eseten 100)
        max=$(cut -d';' -f1 "$AKTUALIS" | sort -n | tail -1)
        [ -z "$max" ] && max=99
        ujpid=$((max + 1))
        echo "$ujpid;$nev;S" >> "$AKTUALIS"
        echo "Elinditva: $nev (PID: $ujpid, statusz: S)"
        ;;
    stop)
        [ $# -lt 2 ] && { echo "Hiba: adja meg a PID-et!" >&2; exit 1; }
        inicializal
        pid_ellenoriz "$2"
        if grep -q "^$2;.*;T$" "$AKTUALIS"; then
            echo "A(z) $2 PID-u folyamat mar le van allitva."
        else
            sed -i "s/^\($2;.*\);S$/\1;T/" "$AKTUALIS"
            echo "Leallitva: PID $2 (S -> T)"
        fi
        ;;
    kill)
        [ $# -lt 2 ] && { echo "Hiba: adja meg a PID-et!" >&2; exit 1; }
        inicializal
        pid_ellenoriz "$2"
        nev=$(grep "^$2;" "$AKTUALIS" | cut -d';' -f2)
        sed -i "/^$2;/d" "$AKTUALIS"
        echo "Torolve: $nev (PID: $2)"
        ;;
    lista)
        inicializal
        printf "%-6s %-30s %s\n" "PID" "NEV" "STATUSZ"
        printf "%-6s %-30s %s\n" "------" "------------------------------" "-------"
        while IFS=';' read -r pid nev stat; do
            [ -z "$pid" ] && continue
            printf "%-6s %-30s %s\n" "$pid" "$nev" "$stat"
        done < "$AKTUALIS"
        ;;
    *)
        hasznalat
        ;;
esac
