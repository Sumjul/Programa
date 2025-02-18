# Programa

## Efektyvumo Tyrimai

Šiame skyriuje pateikiami išsamūs aprašymai ir komentarai apie įvairius efektyvumo tyrimus, atliktus šiame repozitoriume.

### Tyrimas 1: Įvesties Tikrinimo Efektyvumas

- **Aprašymas**: Šis tyrimas nagrinėja įvesties tikrinimo funkcijos `skaicioTikrinimas` efektyvumą.
- **Rezultatai**: Funkcija naudoja ciklą, kad pakartotinai prašytų vartotojo įvesties, kol bus pateikta tinkama reikšmė. Tai užtikrina patikimumą, tačiau gali sukelti vėlavimus, jei vartotojas kelis kartus įveda netinkamus duomenis.

### Tyrimas 2: Duomenų Apdorojimo Efektyvumas

- **Aprašymas**: Šis tyrimas nagrinėja studentų duomenų apdorojimo efektyvumą, įskaitant galutinių pažymių ir medianų skaičiavimą.
- **Rezultatai**: `std::sort` naudojimas medianos skaičiavimui yra efektyvus mažiems duomenų rinkiniams, tačiau gali prireikti optimizacijos didesniems rinkiniams. Galutinio pažymio skaičiavimas yra tiesioginis ir efektyvus.

### Tyrimas 3: Išvesties Formavimo Efektyvumas

- **Aprašymas**: Šis tyrimas vertina studentų duomenų formavimo ir rodymo efektyvumą.
- **Rezultatai**: `std::setw` ir `std::fixed` naudojimas formavimui užtikrina tvarkingą išvestį, tačiau gali turėti nedidelį poveikį našumui. Šis poveikis yra nereikšmingas esamam duomenų rinkinio dydžiui.
