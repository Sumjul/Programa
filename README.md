# Efektyvumo Tyrimai (v0.4)

Šiame skyriuje pateikiami išsamūs našumo testų rezultatai, susiję su duomenų failų generavimu, nuskaitymu, rūšiavimu ir išvedimu.
[Testų ekrano nuotraukų aplankalas](../programa/performance_tests)

## 1. Failų generavimas

| Failas            | Sukūrimo laikas (s) |
|------------------|-----------------|
| `st1000.txt`     | 0.0101944       |
| `st10000.txt`    | 0.0466155       |
| `st100000.txt`   | 0.553198        |
| `st1000000.txt`  | 4.72237         |
| `st10000000.txt` | 56.8465         |

---

## 2. Duomenų apdorojimas

### 2.1. Duomenų nuskaitymas iš failo

| Failas            | Nuskaitymo laikas (s) |
|------------------|------------------|
| `st1000.txt`     | 0.027287         |
| `st10000.txt`    | 0.0723405        |
| `st100000.txt`   | 0.866603         |
| `st1000000.txt`  | 4.49162          |
| `st10000000.txt` | 62.7062          |

### 2.2. Studentų rūšiavimas į dvi grupes

| Failas            | Rūšiavimo laikas (s) |
|------------------|------------------|
| `st1000.txt`     | 0.0018859        |
| `st10000.txt`    | 0.165601         |
| `st100000.txt`   | 1.23176          |
| `st1000000.txt`  | 2.14116          |
| `st10000000.txt` | 10.2318          |

### 2.3. Surūšiuotų studentų išvedimas į du failus

| Failas            | Išvedimo laikas (s) |
|------------------|------------------|
| `st1000.txt`     | 0.0131835        |
| `st10000.txt`    | 0.0620217        |
| `st100000.txt`   | 0.315976         |
| `st1000000.txt`  | 1.26934          |
| `st10000000.txt` | 41.999           |

---

**Pastaba:** Testai buvo atlikti naudojant šios versijos optimizacijas, siekiant įvertinti našumą skirtingo dydžio duomenų failuose.
