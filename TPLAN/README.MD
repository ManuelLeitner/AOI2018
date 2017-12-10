# Trainingsplan

Arthur hat beschlossen etwas f ̈ur seine Figur zu tun und ins Fitnessstudio zu gehen. Das
Fitnessstudio bietet insgesamt _n_ verschiedene Ger ̈ate zum Trainieren an. Diese sind von 1 bis
_n_ durchnummeriert.

Einer seiner Freunde hat ihm sogar einen Trainingsplan zusammengestellt, welcher aus _m_
Schritten besteht. Die Schritte sind genauso von 1 bis _m_ durchnummeriert. Wenn er nun
also das Fitnessstudio besucht, arbeitet er diese _m_ Schritte der Reihe nach ab.

Jeder Schritt ist entweder eine _Ubungsphase ̈_ oder eine _Wiederholungsphase_ :

- Übungsphase: Arthur trainiert an jedem Ger ̈at im Intervall [ _l, r_ ]. Das heißt er ̈ubt
    mit den Ger ̈aten Nummer _l, l_ + 1 _,... r_ − 1 _, r_ jeweils _einmal_.
- Wiederholungsphase: Sein Freund weiß, dass eine einzige Wiederholung an den
    Ger ̈aten wohl nicht gen ̈ugen wird. Deshalb gilt es in dieser Phase alle Schritte im Inter-
    vall [ _l, r_ ] noch einmal zu wiederholen. Diese Schritte liegen nat ̈urlich _vor_ dem aktuellen
    Schritt, da sie ja wiederholt werden. Sollte bei diesen eine weitere Wiederholungsphase
    dabei sein, so wiederholt Arthur diese auch.

All dieses Training macht Arthur schwer zu schaffen. Er ist der Meinung, dass sein Freund
es mit dem Trainingsplan etwas zu gut gemeint hat. Leider hat er aber mit all den Wieder-
holungen schon denUberblick verloren. Kannst du Arthur helfen und herausfinden, wie oft ̈
er an jedem Ger ̈at trainiert hat? Diese Werte k ̈onnen potentiell (wie er schon vermutet hat)
ziemlich groß werden. Gib sie deshalb _modulo_ 10^9 + 7 (1000000007) aus.

## Eingabe

Die erste Zeile des Inputs enthält zwei Zahlen _n_ und _m_ , die Anzahl an Ger ̈ate und die Anzahl
an Schritte des Trainingsplans. Die n ̈achsten _m_ Zeilen enthalten jeweils drei Zahlen _t l r_ , die
die einzelnen Schritte beschreiben. _t_ = 1 bedeutet, dass es sich um eineUbungsphase han- ̈
delt, _t_ = 2 hingegen kennzeichnet eine Wiederholungsphase. _l r_ beschreibt das dazugeh ̈orige
Intervall.

## Ausgabe

Gib _n_ Zahlen aus, die Anzahl an Wiederholungen, die er an jedem Gerät macht - modulo
109 + 7 (1000000007).

## Beispiel

```
Eingabe Ausgabe
5 5
1 1 2
1 4 5
2 1 2
1 3 4
2 3 4
```
### 3 3 2 5 3

Im ersten Schritt trainiert Arthur an Ger ̈at 1 und 2 einmal, im zweiten mit Gerät 4 und 5.
Der dritte Schritt wiederholt die ersten Beiden. Somit ist zu diesem Zeitpunkt jedes Ger ̈at,
außer das Dritte, zweimal benutzt worden. Im vierten Schritt trainiert er an Ger ̈at 3 und

4. Zum Schluss wird die erste Wiederholungsphase erneut durchgef ̈uhrt, sowie nochmal an
Ger ̈at 3 und 4 trainiert.

## Subtasks

Allgemein gilt:

- 1 ≤ _n, m_ ≤ 105
- 1 ≤ _t_ ≤ 2
- 1 ≤ _l_ ≤ _r_ ≤ _n_ bei Übungsphasen
- 1 ≤ _l_ ≤ _r_ ≤ _m_ bei Wiederholungsphasen
- _r_ ist bei Wiederholungsphasen _kleiner_ als die Nummer des aktuellen Schrittes. Er
    wiederholt also tats ̈achlich nur Schritte, die er schon gemacht hat. Somit ist die erste
    Phase seines Trainingsplanes auch immer eineUbungsphase. ̈

**Subtask 1 (4 Punkte):** _n, m_ ≤1000, _t_ = 1 (nurUbungsphasen) ̈

**Subtask 2 (26 Punkte):** _t_ = 1

**Subtask 3 (5 Punkte):** _n, m_ ≤ 10

**Subtask 4 (25 Punkte):** _n, m_ ≤ 1000

**Subtask 5 (40 Punkte):** Keine Einschränkungen

## Beschränkungen

**Zeitlimit:** 1 s **Speicherlimit:** 256 MB

## Hinweis Modulo

Wenn Werte zu groß werden k ̈onnen, dann muss man diese bei Programmierwettbewerben
oft modulo (Divisionsrest, der % Operator in C++/Java) einer großen (Prim-)Zahl ausgeben.
Dies soll die Aufgabe nicht schwieriger machen. Ganz im Gegenteil, der Grund daf ̈ur ist, dass
man so beim Berechnen keineBigInteger(Datentypen mit mehr als 64 Bit) ben ̈otigt. Es
gilt:
( _a_ + _b_ ) % _c_ = (( _a_ % _c_ ) + ( _b_ % _c_ )) % _c_ (1)

(10 + 5) % 7 liefert also das selbe Ergebnis wie ((10 % 7) + (5 % 7)) % 7 = (3 + 5) % 7 = 1.

Auch multiplizieren ist funktioniert so:

```
( a · b ) % c = (( a % c ) · ( b % c )) % c (2)
```
Ahnlich beim Subtrahieren: ̈

```
( a − b ) % c = (( a % c ) − ( b % c ) + c ) % c (3)
```
Das + _c_ ist dazu da, dass die Summe auf jeden Fall wieder Positiv wird.

Dividieren ist etwas komplizierter und wird zum L ̈osen dieser Aufgabe nicht zwingend ben ̈otigt.

Diese Gleichungen erlauben es, dass man schon bei den Zwischenschritten modulo rechnet,
und so nie einen Overflow produziert.

Zum Beispiel: _Berechne das Produkt aller Elemente eines Arraysa, mit L ̈angen- modulo_
106_. Es gilt:_ 1 ≤ _n_ ≤ 1000 _,_ 1 ≤ _ai_ ≤ 1000

Ein 32-Bit Datentyp wie (zumindest auf den meisten Systemen) intkann Werte bis zu
231 −1 = 2147483647, also etwas ̈uber zwei Milliarden (2· 109 ), speichern. Wenn wir in
diesem Beispiel die Werte einfach multiplizieren, dann k ̈onnte dieses Produkt bis zu 1000^1000

- also weit ̈uber demintRange - groß werden. Wenn wir die Zahlen also naive multiplizieren
und dann modulo Rechnen, dann entsteht ein Overflow. Deshalb kommt der Modulo ins
Spiel:

Durch Gleichung (2) wissen wir, dass wir einfach zwischendurch modulo rechnen dürfen, und
das Ergebnis dadurch nicht verändert wird:

```
int product = 1 ;
for ( int i = 0 ; i < n ; i++)
product = ( product ∗ a[i] ) % 1000000 ;
```
Wenn wir modulo _x_ rechnen, dann ist das Ergebnis zwischen 0 und _x_ −1 (es ist ja immerhin
der Rest). Somit kann das Produkt (product∗a[ i ]) maximal (1000000−1)· 1000 _<_ 109 groß
werden, was imintRange liegt. Deshalb k ̈onnen wir das Produkt aller Zahlen - modulo 10^6

- ausrechnen, ohne je mehr als einen 32-Bit Datentypen zu ben ̈otigen.
