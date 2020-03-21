# Proiect-POO-3
## Proiect care utilizeaza conceptul de mostenire si template<br>
Pizzeria X testeaza un nou soft, dezvoltat in maniera OOP, pentru gestionarea activitatii sale. Codul propriu-zis contine o clasa abstracta care contine doar metoda virtuala pura de calcul al pretului unui produs, iar din aceasta clasa de deriveaza clasa Pizza. In realizarea oricarui produs intra un anumit numar de ingrediente pentru care se cunosc denumirile, cantitatile si pretul unitar. Pretul unui produs finit este data de pretul ingredientelor plus manopera (o suma constanta fixata de producator). Daca pizza este comandata OnLine, la pret se mai adauga si 5% din pret la fiecare 10 km parcursi deangajatul care livreaza la domiciliu.<br>

### Cerinta suplimentara:
* Sa se construiasca clasa template Meniu care sa gestioneze tipurie de pizza comercializate. Clasa trebuie sa contina indexul unui produs (incrementat automat la vanzarea unui produs rin supraincarcarea operatorului +=) și un vector de pointeri la obiecte de tip pizza, alocat
dinamic. Tipurile de pizza vegetariana trebuie tratate intr-un document contabil separat din care sa rezulte valoarea totala incasata din vanzarea acestora.
* Sa se construiasca o specializare pentru tipul int care sa trateze exceptiile ce pot aparea de la utilizarea valorilor negative.
